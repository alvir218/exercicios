package one.digitalinnovation.javabasico1.interfaces8;

public interface Veiculo {

    String registro();

    default void ligar(){
        System.out.println("ligando o veiculo");
    }

    //void desligar();

    /*default void desligar(){
        System.out.println("desligando o veiculo");
    }*/
}
