package one.digitalinnovation.exercicios.e3impostos;

public class Gerente extends Funcionario{

    public Gerente(String nome, Double salario){
        super(nome, salario);
    }

    public void pagarImposto(){
       this.setImposto(this.getSalario() * 0.1 / 100);
    }
}
