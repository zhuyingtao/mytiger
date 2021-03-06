package codegen.C;

// Given a Java ast, translate it into a C ast and outputs it.

public class TranslateVisitor implements ast.Visitor {
    private ClassTable table;
    private String classId;
    private codegen.C.type.T type; // type after translation
    private codegen.C.dec.T dec;
    private codegen.C.stm.T stm;
    private codegen.C.exp.T exp;
    private codegen.C.method.T method;
    private java.util.LinkedList<codegen.C.dec.T> tmpVars;
    private java.util.LinkedList<codegen.C.classs.T> classes;
    private java.util.LinkedList<codegen.C.vtable.T> vtables;
    private java.util.LinkedList<codegen.C.method.T> methods;
    private codegen.C.mainMethod.T mainMethod;
    public codegen.C.program.T program;

    public TranslateVisitor() {
        this.table = new ClassTable();
        this.classId = null;
        this.type = null;
        this.dec = null;
        this.stm = null;
        this.exp = null;
        this.method = null;
        this.classes = new java.util.LinkedList<codegen.C.classs.T>();
        this.vtables = new java.util.LinkedList<codegen.C.vtable.T>();
        this.methods = new java.util.LinkedList<codegen.C.method.T>();
        this.mainMethod = null;
        this.program = null;
    }

    // //////////////////////////////////////////////////////
    //
    public String genId() {
        return util.Temp.next();
    }

    // /////////////////////////////////////////////////////
    // expressions
    @Override
    public void visit(ast.exp.Add e) {
        if (e.result != null) {
            e.result.accept(this);
            return;
        }
        if (e.left != null)
            e.left.accept(this);
        codegen.C.exp.T left = this.exp;
        if (e.right != null)
            e.right.accept(this);
        codegen.C.exp.T right = this.exp;
        this.exp = new codegen.C.exp.Add(left, right);
    }

    @Override
    public void visit(ast.exp.And e) {
        if (e.result != null) {
            e.result.accept(this);
            return;
        }
        e.left.accept(this);
        codegen.C.exp.T left = this.exp;
        e.right.accept(this);
        codegen.C.exp.T right = this.exp;
        this.exp = new codegen.C.exp.And(left, right);
    }

    @Override
    public void visit(ast.exp.ArraySelect e) {
        e.index.accept(this);
        codegen.C.exp.T index = this.exp;
        e.array.accept(this);
        codegen.C.exp.T array = this.exp;
        this.exp = new codegen.C.exp.ArraySelect(array, index);
    }

    @Override
    public void visit(ast.exp.Call e) {
        e.exp.accept(this);
        String newid = this.genId();
        this.tmpVars.add(new codegen.C.dec.Dec(
                new codegen.C.type.Class(e.type), newid));
        codegen.C.exp.T exp = this.exp;
        java.util.LinkedList<codegen.C.exp.T> args = new java.util.LinkedList<codegen.C.exp.T>();
        if (e.args != null) {
            for (ast.exp.T x : e.args) {
                x.accept(this);
                args.add(this.exp);
            }
        }
        e.rt.accept(this);
        codegen.C.type.T retType = this.type;
        this.exp = new codegen.C.exp.Call(newid, exp, e.id, args, retType);
        return;
    }

    @Override
    // in C,0 is false.
    public void visit(ast.exp.False e) {
        this.exp = new codegen.C.exp.Num(0);
    }

    @Override
    public void visit(ast.exp.Id e) {
        if (e.isField == true)
            this.exp = new codegen.C.exp.Id(e.id, true);
        else
            this.exp = new codegen.C.exp.Id(e.id);
        return;
    }

    @Override
    public void visit(ast.exp.Length e) {
        e.array.accept(this);
        codegen.C.exp.T array = this.exp;
        this.exp = new codegen.C.exp.Length(array);
    }

    @Override
    public void visit(ast.exp.Lt e) {
        if (e.result != null) {
            e.result.accept(this);
            return;
        }
        e.left.accept(this);
        codegen.C.exp.T left = this.exp;
        e.right.accept(this);
        codegen.C.exp.T right = this.exp;
        this.exp = new codegen.C.exp.Lt(left, right);
        return;
    }

    @Override
    public void visit(ast.exp.NewIntArray e) {
        e.exp.accept(this);
        codegen.C.exp.T exp = this.exp;
        this.exp = new codegen.C.exp.NewIntArray(exp);
    }

    @Override
    public void visit(ast.exp.NewObject e) {
        this.exp = new codegen.C.exp.NewObject(e.id);
        return;
    }

    @Override
    public void visit(ast.exp.Not e) {
        if (e.result != null) {
            e.result.accept(this);
            return;
        }
        e.exp.accept(this);
        codegen.C.exp.T exp = this.exp;
        this.exp = new codegen.C.exp.Not(exp);
    }

    @Override
    public void visit(ast.exp.Num e) {
        this.exp = new codegen.C.exp.Num(e.num);
        return;
    }

    @Override
    public void visit(ast.exp.Sub e) {
        if (e.result != null) {
            e.result.accept(this);
            return;
        }
        if (e.left != null)
            e.left.accept(this);
        codegen.C.exp.T left = this.exp;
        if (e.right != null)
            e.right.accept(this);
        codegen.C.exp.T right = this.exp;
        this.exp = new codegen.C.exp.Sub(left, right);
        return;
    }

    @Override
    public void visit(ast.exp.This e) {
        this.exp = new codegen.C.exp.This();
        return;
    }

    @Override
    public void visit(ast.exp.Times e) {
        if (e.result != null) {
            e.result.accept(this);
            return;
        }
        if (e.left != null)
            e.left.accept(this);
        codegen.C.exp.T left = this.exp;
        if (e.right != null)
            e.right.accept(this);
        codegen.C.exp.T right = this.exp;
        this.exp = new codegen.C.exp.Times(left, right);
        if (e.right == null && e.left == null)
            this.exp = new codegen.C.exp.Num(0);
        return;
    }

    @Override
    // Because there is no "true" or "false" in C,
    // in C,1 is true.
    public void visit(ast.exp.True e) {
        this.exp = new codegen.C.exp.Num(1);
    }

    // statements
    @Override
    public void visit(ast.stm.Assign s) {
        s.exp.accept(this);
        this.stm = new codegen.C.stm.Assign(s.id, this.exp, s.idIsField);
        return;
    }

    @Override
    public void visit(ast.stm.AssignArray s) {
        s.index.accept(this);
        codegen.C.exp.T index = this.exp;
        s.exp.accept(this);
        codegen.C.exp.T exp = this.exp;
        this.stm = new codegen.C.stm.AssignArray(s.id, index, exp, s.idIsField);
    }

    @Override
    public void visit(ast.stm.Block s) {
        java.util.LinkedList<codegen.C.stm.T> stms = new java.util.LinkedList<codegen.C.stm.T>();
        for (ast.stm.T x : s.stms) {
            x.accept(this);
            stms.add(this.stm);
        }
        this.stm = new codegen.C.stm.Block(stms);
    }

    @Override
    public void visit(ast.stm.If s) {
        codegen.C.exp.T condition = null;
        codegen.C.stm.T thenn = null;
        codegen.C.stm.T elsee = null;
        if (s.condition != null) {
            s.condition.accept(this);
            condition = this.exp;
        }
        if (s.thenn != null) {
            s.thenn.accept(this);
            thenn = this.stm;
        }
        if (s.elsee != null) {
            s.elsee.accept(this);
            elsee = this.stm;
        }
        this.stm = new codegen.C.stm.If(condition, thenn, elsee);
        return;
    }

    @Override
    public void visit(ast.stm.Print s) {
        s.exp.accept(this);
        this.stm = new codegen.C.stm.Print(this.exp);
        return;
    }

    @Override
    public void visit(ast.stm.While s) {
        codegen.C.exp.T condition = null;
        codegen.C.stm.T body = null;
        if (s.condition != null) {
            s.condition.accept(this);
            condition = this.exp;
        }
        if (s.body != null) {
            s.body.accept(this);
            body = this.stm;
        }
        this.stm = new codegen.C.stm.While(condition, body);
    }

    // type
    @Override
    public void visit(ast.type.Boolean t) {
        this.type = new codegen.C.type.Int();
    }

    @Override
    public void visit(ast.type.Class t) {
        this.type = new codegen.C.type.Class(t.id);
    }

    @Override
    public void visit(ast.type.Int t) {
        this.type = new codegen.C.type.Int();
    }

    @Override
    public void visit(ast.type.IntArray t) {
        this.type = new codegen.C.type.IntArray();
    }

    // dec
    @Override
    public void visit(ast.dec.Dec d) {
        d.type.accept(this);
        this.dec = new codegen.C.dec.Dec(this.type, d.id);
        return;
    }

    // method
    @Override
    public void visit(ast.method.Method m) {
        this.tmpVars = new java.util.LinkedList<codegen.C.dec.T>();
        m.retType.accept(this);
        codegen.C.type.T newRetType = this.type;

        java.util.LinkedList<codegen.C.dec.T> newFormals = new java.util.LinkedList<codegen.C.dec.T>();
        newFormals.add(new codegen.C.dec.Dec(new codegen.C.type.Class(
                this.classId), "this"));
        // initial the arguments GC map with "1" presented "this"
        StringBuffer aString = new StringBuffer("1");

        for (ast.dec.T d : m.formals) {
            d.accept(this);
            if (this.type instanceof codegen.C.type.Class
                    || this.type instanceof codegen.C.type.IntArray)
                aString.append("1");
            else
                aString.append("0");
            newFormals.add(this.dec);
        }

        java.util.LinkedList<codegen.C.dec.T> locals = new java.util.LinkedList<codegen.C.dec.T>();
        StringBuffer lString = new StringBuffer();
        for (ast.dec.T d : m.locals) {
            d.accept(this);
            if (this.type instanceof codegen.C.type.Class
                    || this.type instanceof codegen.C.type.IntArray)
                lString.append("1");
            else
                lString.append("0");
            locals.add(this.dec);
        }

        java.util.LinkedList<codegen.C.stm.T> newStm = new java.util.LinkedList<codegen.C.stm.T>();
        for (ast.stm.T s : m.stms) {
            s.accept(this);
            newStm.add(this.stm);
        }
        m.retExp.accept(this);
        codegen.C.exp.T retExp = this.exp;
        for (codegen.C.dec.T dec : this.tmpVars) {
            if (((codegen.C.dec.Dec) dec).type instanceof codegen.C.type.Class
                    || ((codegen.C.dec.Dec) dec).type instanceof codegen.C.type.IntArray)
                lString.append("1");
            else
                lString.append("0");
            locals.add(dec);
        }
        this.method = new codegen.C.method.Method(newRetType, this.classId,
                m.id, newFormals, locals, newStm, retExp, aString, lString);
        return;
    }

    // class
    @Override
    public void visit(ast.classs.Class c) {
        ClassBinding cb = this.table.get(c.id);
        this.classes.add(new codegen.C.classs.Class(c.id, cb.fields));
        this.vtables.add(new codegen.C.vtable.Vtable(c.id, cb.methods));
        this.classId = c.id;
        for (ast.method.T m : c.methods) {
            m.accept(this);
            this.methods.add(this.method);
        }
        return;
    }

    // main class
    @Override
    public void visit(ast.mainClass.MainClass c) {
        ClassBinding cb = this.table.get(c.id);
        codegen.C.classs.T newc = new codegen.C.classs.Class(c.id, cb.fields);
        this.classes.add(newc);
        this.vtables.add(new codegen.C.vtable.Vtable(c.id, cb.methods));

        this.tmpVars = new java.util.LinkedList<codegen.C.dec.T>();

        c.stm.accept(this);
        codegen.C.mainMethod.T mthd = new codegen.C.mainMethod.MainMethod(
                this.tmpVars, this.stm);
        this.mainMethod = mthd;
        return;
    }

    // /////////////////////////////////////////////////////
    // the first pass
    public void scanMain(ast.mainClass.T m) {
        this.table.init(((ast.mainClass.MainClass) m).id, null);
        // this is a special hacking in that we don't want to
        // enter "main" into the table.
        return;
    }

    public void scanClasses(java.util.LinkedList<ast.classs.T> cs) {
        // put empty chuncks into the table
        for (ast.classs.T c : cs) {
            ast.classs.Class cc = (ast.classs.Class) c;
            this.table.init(cc.id, cc.extendss);
        }

        // put class fields and methods into the table
        for (ast.classs.T c : cs) {
            ast.classs.Class cc = (ast.classs.Class) c;
            java.util.LinkedList<codegen.C.dec.T> newDecs = new java.util.LinkedList<codegen.C.dec.T>();
            for (ast.dec.T dec : cc.decs) {
                dec.accept(this);
                newDecs.add(this.dec);
            }
            this.table.initDecs(cc.id, newDecs);

            // all methods
            java.util.LinkedList<ast.method.T> methods = cc.methods;
            for (ast.method.T mthd : methods) {
                ast.method.Method m = (ast.method.Method) mthd;
                java.util.LinkedList<codegen.C.dec.T> newArgs = new java.util.LinkedList<codegen.C.dec.T>();
                for (ast.dec.T arg : m.formals) {
                    arg.accept(this);
                    newArgs.add(this.dec);
                }
                m.retType.accept(this);
                codegen.C.type.T newRet = this.type;
                this.table.initMethod(cc.id, newRet, newArgs, m.id);
            }
        }

        // calculate all inheritance information
        for (ast.classs.T c : cs) {
            ast.classs.Class cc = (ast.classs.Class) c;
            this.table.inherit(cc.id);
        }
    }

    public void scanProgram(ast.program.T p) {
        ast.program.Program pp = (ast.program.Program) p;
        scanMain(pp.mainClass);
        scanClasses(pp.classes);
        return;
    }

    // end of the first pass
    // ////////////////////////////////////////////////////

    // program
    @Override
    public void visit(ast.program.Program p) {
        // The first pass is to scan the whole program "p", and
        // to collect all information of inheritance.
        scanProgram(p);

        // do translations
        p.mainClass.accept(this);
        for (ast.classs.T classs : p.classes) {
            classs.accept(this);
        }
        this.program = new codegen.C.program.Program(this.classes,
                this.vtables, this.methods, this.mainMethod);
        return;
    }

}
