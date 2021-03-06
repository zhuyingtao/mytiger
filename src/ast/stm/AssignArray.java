package ast.stm;

//  id [index]=exp;
public class AssignArray extends T {
    public String id;
    public ast.exp.T index;
    public ast.exp.T exp;

    public boolean idIsField = false;

    public AssignArray(String id, ast.exp.T index, ast.exp.T exp) {
        this.id = id;
        this.index = index;
        this.exp = exp;
    }

    @Override
    public void accept(ast.Visitor v) {
        v.visit(this);
    }
}
