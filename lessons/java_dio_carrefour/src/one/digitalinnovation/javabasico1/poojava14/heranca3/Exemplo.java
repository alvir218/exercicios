package one.digitalinnovation.javabasico1.poojava14.heranca3;

public class Exemplo {
    public static void main(String[] args) {

        Carro carro = new Carro();
        carro.setMarca("nissan");
        carro.setModelo("march");
        carro.setQuantidadeDePortas(4);

        Motocicleta moto = new Motocicleta();
        moto.setMarca("ducati");
        moto.setModelo("streetfighter");
        moto.setCilindradas("850");
    }
}
