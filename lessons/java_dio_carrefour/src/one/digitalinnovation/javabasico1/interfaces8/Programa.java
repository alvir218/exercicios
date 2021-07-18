package one.digitalinnovation.javabasico1.interfaces8;

public class Programa {
    public static void main(String[] args) {

        final Gol gol = new Gol();
        System.out.println("marca do gol: " + gol.marca());
        gol.ligar();

        //final Trator trator = new Trator();
        final Veiculo trator = new Trator();
        System.out.println("registro do trator: " + trator.registro());
        trator.ligar();

        //final Carro fiesta = new Fiesta();
        //final Veiculo fiesta = new Fiesta();
        //nao baixa marca ou registro
        final Fiesta fiesta = new Fiesta();

        System.out.println("marca do fiesta: " + fiesta.marca());
        System.out.println("registro do fiesta: " + fiesta.registro());


    }
}
