package one.digitalinnovation.javabasico1.interfaces8;

public interface Carro extends Automovel{

    String marca();

    Double valor();

    default void ligar(){
        System.out.println("ligando carro");
    }

    default String codigoRenavan(){
        return "rnv123\n";
    }
}
