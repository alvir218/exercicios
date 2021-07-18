package one.digitalinnovation.javabasico1.interfaces8;

public class Fiesta implements Carro, Veiculo{
    @Override
    public String marca(){
        return "ford";
    }

    @Override
    public Double valor(){
        return null;
    }

    @Override
    public String registro(){
        return "cde456\n";
    }

    @Override
    public void ligar(){
        Carro.super.ligar();

        Veiculo.super.ligar();
    }

}
