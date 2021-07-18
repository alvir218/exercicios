package one.digitalinnovation.javabasico1.poojava14.equals5.equals3hashcode;

public class Exemplo {
    public static void main(String[] args) {

        Veiculo carro1 = new Carro("palio", "fiat", 20000.0);
        Veiculo carro2 = new Carro("palio", "fiat", 20000.0);

        System.out.println(carro1.equals(carro2));
          //true
    }
}
