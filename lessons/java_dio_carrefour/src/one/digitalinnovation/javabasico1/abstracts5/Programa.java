package one.digitalinnovation.javabasico1.abstracts5;

public class Programa {
    public static void main(String[] args) {

        //final FormaGeometrica formaGeometrica = new FormaGeometrica();

        final FormaGeometrica quadrado = new Quadrado("quadrado", 25.0);

        System.out.println(quadrado);

        System.out.println(quadrado.desenha(12,34));
        System.out.println(quadrado.nome());
        System.out.println(quadrado.area());
    }
}
