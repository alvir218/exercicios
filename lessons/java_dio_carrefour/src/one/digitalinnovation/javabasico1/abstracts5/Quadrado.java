package one.digitalinnovation.javabasico1.abstracts5;

public class Quadrado extends FormaGeometrica{

    private String nome;
    private Double area;

    public Quadrado(final String nome, final Double area){
        this.nome = nome;
        this.area = area;
    }

    @Override
    public String nome(){
        return nome;
    }

    @Override
    public Double area(){
        return area;
    }

    @Override
    public String toString(){
        final String builder = "quadrado\nnome: " + nome + "\narea: " + area + "\n";
        return builder.toString();
    }
}
