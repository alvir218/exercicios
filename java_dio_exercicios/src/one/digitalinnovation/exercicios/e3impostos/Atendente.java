package one.digitalinnovation.exercicios.e3impostos;

public class Atendente extends Funcionario{

    public Atendente(String nome, Double salario){
        super(nome, salario);
    }

    public void pagarImposto(){
        this.setImposto(this.getSalario() * 0.01 / 100);
    }
}
