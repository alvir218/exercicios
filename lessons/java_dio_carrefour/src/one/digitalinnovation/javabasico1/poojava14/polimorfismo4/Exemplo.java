package one.digitalinnovation.javabasico1.poojava14.polimorfismo4;

public class Exemplo {
    public static void main(String[] args) {

       Veiculo generico = new Veiculo();
       generico.setValorVenal(1000.0);
        System.out.println(generico.calculaImposto());
          //10

        Veiculo carro = new Carro();
        carro.setValorVenal(1000.0);
        System.out.println(carro.calculaImposto());
          //70

        Veiculo moto = new Motocicleta();
        moto.setValorVenal(1000.0);
        System.out.println(moto.calculaImposto());
          //30
    }
}
