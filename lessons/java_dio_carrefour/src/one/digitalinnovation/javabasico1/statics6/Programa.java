package one.digitalinnovation.javabasico1.statics6;

public class Programa {
    public static void main(String[] args) {

        final Cachorro pitbull = new Cachorro();
        pitbull.zoologia = "bipede";

        final Cachorro viralatas = new Cachorro();

        System.out.println(pitbull.zoologia);
        System.out.println(viralatas.zoologia);

        System.out.println("static em metodos permite executalos sem instanciar");
        Cachorro.late();

    }
}
