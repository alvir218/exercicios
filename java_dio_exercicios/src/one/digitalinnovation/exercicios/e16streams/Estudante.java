package one.digitalinnovation.exercicios.e16streams;

public class Estudante {

    private String nome;
    private Integer idade;

    public Estudante(String nome, Integer idade){
        this.nome = nome;
        this.idade = idade;
    }

    @Override
    public String toString(){
        return this.nome + " - " + this.idade;
    }

    public String getNome(){
        return this.nome;
    }

    public Integer getIdade(){
        return this.idade;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setIdade(Integer idade){
        this.idade = idade;
    }
}
