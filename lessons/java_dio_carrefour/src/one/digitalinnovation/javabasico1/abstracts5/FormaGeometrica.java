package one.digitalinnovation.javabasico1.abstracts5;

public abstract class FormaGeometrica {

    public abstract String nome();
    public abstract Double area();

    public String desenha(int x, int y){
        return "desenhando nas coordenadas x= " + x + " y= " + y + "\n";
    }
}
