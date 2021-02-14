package one.digitalinnovation.exercicios.e3impostos;

public class Funcionario {
    private String nome;
    private Double salario;
    private Double imposto;

    public Funcionario(String nome, Double salario){
        this.nome = nome;
        this.salario = salario;
    }

    public String getNome(){
        return this.nome;
    }

    public Double getSalario(){
        return this.salario;
    }

    public Double getImposto(){
        return this.imposto;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setSalario(Double salario){
        this.salario = salario;
    }

    public void setImposto(Double imposto){
        this.imposto = imposto;
    }
}
