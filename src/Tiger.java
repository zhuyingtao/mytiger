import control.CommandLine;
import control.Control;
import control.Control.Codegen_Kind_t;
import lexer.Lexer;
import lexer.Token;
import lexer.Token.Kind;
import parser.Parser;

import java.io.*;

public class Tiger {
    static Tiger tiger;
    static CommandLine cmd;
    static InputStream fstream;
    public ast.program.T theAst;

    // lex and parse
    public void lexAndParse(String fname) {
        Parser parser;
        try {
            fstream = new BufferedInputStream(new FileInputStream(fname));
            parser = new Parser(fname, fstream);

            theAst = parser.parse();

            fstream.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
        return;
    }

    public void compile(String fname) {
        // /////////////////////////////////////////////////////
        // to test the pretty printer on the "test/Fac.java" program
        this.testFac();

        if (fname == null) {
            cmd.usage();
            return;
        }

        // /////////////////////////////////////////////////////
        // it would be helpful to be able to test the lexer
        // independently.
        this.testLexer(fname);
        Control.fileName = fname.substring(fname.lastIndexOf("/") + 1);
        // Lexer and Parser , then the AST is generated;
        control.CompilerPass lexAndParsePass = new control.CompilerPass(
                "Lex and parse", tiger, fname);
        lexAndParsePass.doitName("lexAndParse");

        // pretty printing the AST, if necessary
        if (control.Control.dumpAst) {
            ast.PrettyPrintVisitor pp = new ast.PrettyPrintVisitor();
            control.CompilerPass ppAstPass = new control.CompilerPass(
                    "Pretty printing the AST", theAst, pp);
            ppAstPass.doit();
        }

        // elaborate the AST, report all possible errors.
        elaborator.ElaboratorVisitor elab = new elaborator.ElaboratorVisitor();
        control.CompilerPass elabAstPass = new control.CompilerPass(
                "Elaborating the AST", theAst, elab);
        elabAstPass.doit();

        // optimize the AST
        ast.optimizations.Main optAST = new ast.optimizations.Main();
        control.CompilerPass optAstPass = new control.CompilerPass(
                "Optimizing the AST", optAST, theAst);
        optAstPass.doit();
        theAst = optAST.program;

        // translate to cAST
        codegen.C.TranslateVisitor transC = new codegen.C.TranslateVisitor();
        control.CompilerPass genCCodePass = new control.CompilerPass(
                "C code generation", theAst, transC);
        genCCodePass.doit();
        codegen.C.program.T cAst = transC.program;

        // translation to control-flow graph
        cfg.TranslateVisitor transCfg = new cfg.TranslateVisitor();
        control.CompilerPass genCfgCodePass = new control.CompilerPass(
                "Control-flow graph generation", cAst, transCfg);
        genCfgCodePass.doit();
        cfg.program.T cfgAst = transCfg.program;

        // visualize the control-flow graph, if necessary
        if (control.Control.visualize != Control.Visualize_Kind_t.None) {
            System.out.println("the CFG of " + Control.fileName
                    + " has been generated in graph/* !\n");
            cfg.VisualVisitor toDot = new cfg.VisualVisitor();
            control.CompilerPass genDotPass = new control.CompilerPass(
                    "Draw control-flow graph", cfgAst, toDot);
            genDotPass.doit();
        }

        // optimizations on the control-flow graph
        cfg.optimizations.Main cfgOpts = new cfg.optimizations.Main();
        control.CompilerPass cfgOptPass = new control.CompilerPass(
                "Control-flow graph optimizations", cfgOpts, cfgAst);
        cfgOptPass.doit();

        // code generation
        codegen.bytecode.PrettyPrintVisitor ppbc = null;
        codegen.C.PrettyPrintVisitor ppc = null;
        switch (control.Control.codegen) {
            case Bytecode:
                codegen.bytecode.TranslateVisitor trans = new codegen.bytecode.TranslateVisitor();
                control.CompilerPass genBytecodePass = new control.CompilerPass(
                        "Bytecode generation", theAst, trans);
                genBytecodePass.doit();
                codegen.bytecode.program.T bytecodeAst = trans.program;

                ppbc = new codegen.bytecode.PrettyPrintVisitor();
                control.CompilerPass ppBytecodePass = new control.CompilerPass(
                        "Bytecode printing", bytecodeAst, ppbc);
                ppBytecodePass.doit();
                break;
            case C:
                // generate cAST code;
                System.out.println("C code has been generated in test/cCode !\n");
                ppc = new codegen.C.PrettyPrintVisitor();
                control.CompilerPass ppCCodePass = new control.CompilerPass(
                        "C code printing", cAst, ppc);
                ppCCodePass.doit();

                // generate cfgAST code;
                System.out
                        .println("CFG code has been generated in test/cfgCode !\n");
                cfg.PrettyPrintVisitor ppCfg = new cfg.PrettyPrintVisitor();
                control.CompilerPass ppCfgCodePass = new control.CompilerPass(
                        "C code printing", cfgAst, ppCfg);
                ppCfgCodePass.doit();

                break;
            case Dalvik:
                codegen.dalvik.TranslateVisitor transDalvik = new codegen.dalvik.TranslateVisitor();
                control.CompilerPass genDalvikCodePass = new control.CompilerPass(
                        "Dalvik code generation", theAst, transDalvik);
                genDalvikCodePass.doit();
                codegen.dalvik.program.T dalvikAst = transDalvik.program;

                codegen.dalvik.PrettyPrintVisitor ppDalvik = new codegen.dalvik.PrettyPrintVisitor();
                control.CompilerPass ppDalvikCodePass = new control.CompilerPass(
                        "Dalvik code printing", dalvikAst, ppDalvik);
                ppDalvikCodePass.doit();
                break;
            case X86:
                // similar
                break;
            default:
                break;
        }

        // Lab3, exercise 6: add some glue code to
        // call gcc to compile the generated C or x86
        // file, or call java to run the bytecode file.
        // Your code:
        Runtime run = Runtime.getRuntime();
        Process process = null;
        if (control.Control.codegen == Codegen_Kind_t.C) {
            try {
                String file = Control.fileName;
                run.exec("gcc test/cfgCode/" + file
                        + ".c  runtime/runtime.c -o test/exe/" + file + ".exe");
                System.out.println(file
                        + ".exe based on CFG has been generate in test/exe !");
                // process = run.exec("cmd "+file + ".exe");
                return;
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        } else if (control.Control.codegen == Codegen_Kind_t.Bytecode) {
            try {
                for (int i = 0; i < ppbc.jNames.size(); i++) {
                    process = run.exec("java -jar jasmin.jar "
                            + ppbc.jNames.get(i) + " -d test/byteCode");
                }
                process.waitFor();
                // fileName now is '*.java';
                // the regex . can present any character,so use "\\."
                String main = Control.fileName.split("\\.")[0];
                // Here you cannot write the command like this:
                // "java test/bytecodeTest/%main% " and I don't know why;
                process = run.exec("java -classpath test/byteCode " + main);

            } catch (Exception e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        // print the running result in console;
        BufferedReader br = new BufferedReader(new InputStreamReader(
                process.getInputStream()));
        try {
            String str = br.readLine();
            if (str == null) {
                // that is to say an error occurred,so print the error info;
                br = new BufferedReader(new InputStreamReader(
                        process.getErrorStream()));
                str = br.readLine();
            }
            while (str != null) {
                System.out.println(str);
                str = br.readLine();
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

    public void assemble(String str) {
        // Your code here:
        // System.out.println("-------enter assemble");
    }

    public void link(String str) {
        // Your code here:
        // System.out.println("-------enter link");

    }

    public void compileAndLink(String fname) {
        // compile
        control.CompilerPass compilePass = new control.CompilerPass("Compile",
                tiger, fname);
        compilePass.doitName("compile");

        // assembling
        control.CompilerPass assemblePass = new control.CompilerPass(
                "Assembling", tiger, fname);
        assemblePass.doitName("assemble");

        // linking
        control.CompilerPass linkPass = new control.CompilerPass("Linking",
                tiger, fname);
        linkPass.doitName("link");

        return;
    }

    public static void main(String[] args) {
        // ///////////////////////////////////////////////////////
        // handle command line arguments
        tiger = new Tiger();
        cmd = new CommandLine();
        String fname = "";
        fname = cmd.scan(args);
        control.CompilerPass tigerAll = new control.CompilerPass("Tiger",
                tiger, fname);
        tigerAll.doitName("compileAndLink");
        return;
    }

    public void testFac() {
        if (control.Control.testFac) {
            System.out.println("-------enter testFac");

            ast.PrettyPrintVisitor pp = new ast.PrettyPrintVisitor();
            control.CompilerPass ppPass = new control.CompilerPass(
                    "Pretty printing AST", ast.Fac.prog, pp);
            ppPass.doit();
            // elaborate the given program, this step is necessary
            // for that it will annotate the AST with some
            // informations used by later phase.
            elaborator.ElaboratorVisitor elab = new elaborator.ElaboratorVisitor();
            control.CompilerPass elabPass = new control.CompilerPass(
                    "Elaborating the AST", ast.Fac.prog, elab);
            elabPass.doit();

            // optimize the AST
            ast.optimizations.Main optAST = new ast.optimizations.Main();
            control.CompilerPass optAstPass = new control.CompilerPass(
                    "Optimizing AST", optAST, ast.Fac.prog);
            optAstPass.doit();
            ast.Fac.prog = (ast.program.Program) optAST.program;

            // Compile this program to C.
            codegen.C.TranslateVisitor transC = new codegen.C.TranslateVisitor();
            control.CompilerPass genCCodePass = new control.CompilerPass(
                    "Translation to C code", ast.Fac.prog, transC);
            genCCodePass.doit();
            codegen.C.program.T cAst = transC.program;

            if (control.Control.dumpC) {
                codegen.C.PrettyPrintVisitor ppC = new codegen.C.PrettyPrintVisitor();
                control.CompilerPass ppCCodePass = new control.CompilerPass(
                        "C code printing", cAst, ppC);
                ppCCodePass.doit();
            }

            // translation to control-flow graph
            cfg.TranslateVisitor transCfg = new cfg.TranslateVisitor();
            control.CompilerPass genCfgCodePass = new control.CompilerPass(
                    "Control-flow graph generation", cAst, transCfg);
            genCfgCodePass.doit();
            cfg.program.T cfgAst = transCfg.program;

            // visualize the control-flow graph, if necessary
            if (control.Control.visualize != Control.Visualize_Kind_t.None) {
                cfg.VisualVisitor toDot = new cfg.VisualVisitor();
                control.CompilerPass genDotPass = new control.CompilerPass(
                        "Draw control-flow graph", cfgAst, toDot);
                genDotPass.doit();
            }

            // optimizations on the control-flow graph
            cfg.optimizations.Main cfgOpts = new cfg.optimizations.Main();
            control.CompilerPass cfgOptPass = new control.CompilerPass(
                    "Control-flow graph optimizations", cfgOpts, cfgAst);
            cfgOptPass.doit();

            // code generation
            switch (control.Control.codegen) {
                case Bytecode:
                    codegen.bytecode.TranslateVisitor trans = new codegen.bytecode.TranslateVisitor();
                    control.CompilerPass genBytecodePass = new control.CompilerPass(
                            "Bytecode generation", ast.Fac.prog, trans);
                    genBytecodePass.doit();
                    codegen.bytecode.program.T bytecodeAst = trans.program;

                    codegen.bytecode.PrettyPrintVisitor ppbc = new codegen.bytecode.PrettyPrintVisitor();
                    control.CompilerPass ppBytecodePass = new control.CompilerPass(
                            "Bytecode printing", bytecodeAst, ppbc);
                    ppBytecodePass.doit();
                    break;
                case C:
                    cfg.PrettyPrintVisitor ppCfg = new cfg.PrettyPrintVisitor();
                    control.CompilerPass ppCfgCodePass = new control.CompilerPass(
                            "C code printing", cfgAst, ppCfg);
                    ppCfgCodePass.doit();
                    break;
                case Dalvik:
                    codegen.dalvik.TranslateVisitor transDalvik = new codegen.dalvik.TranslateVisitor();
                    control.CompilerPass genDalvikCodePass = new control.CompilerPass(
                            "Dalvik code generation", ast.Fac.prog, transDalvik);
                    genDalvikCodePass.doit();
                    codegen.dalvik.program.T dalvikAst = transDalvik.program;

                    codegen.dalvik.PrettyPrintVisitor ppDalvik = new codegen.dalvik.PrettyPrintVisitor();
                    control.CompilerPass ppDalvikCodePass = new control.CompilerPass(
                            "Dalvik code printing", dalvikAst, ppDalvik);
                    ppDalvikCodePass.doit();
                    break;
                case X86:
                    // similar
                    break;
                default:
                    break;
            }
            System.exit(0);
        }
    }

    public void testLexer(String fname) {
        if (control.Control.testlexer) {
            System.out.println("Testing the lexer. All tokens:");
            try {
                fstream = new BufferedInputStream(new FileInputStream(fname));
                Lexer lexer = new Lexer(fname, fstream);
                Token token = lexer.nextToken();
                while (token.kind != Kind.TOKEN_EOF) {
                    System.out.println(token.toString());
                    token = lexer.nextToken();
                }
                fstream.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.exit(1);
        }
    }
}
