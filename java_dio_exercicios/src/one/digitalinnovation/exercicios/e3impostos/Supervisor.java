package one.digitalinnovation.exercicios.e3impostos;

public class Supervisor extends Funcionario{

    public Supervisor(String nome, Double salario){
        super(nome, salario);
    }

    public void pagarImposto(){
        this.setImposto(this.getSalario() * 0.05 / 100);
    }
}
