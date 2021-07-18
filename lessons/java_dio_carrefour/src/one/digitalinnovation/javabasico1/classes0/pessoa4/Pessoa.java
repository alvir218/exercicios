package one.digitalinnovation.javabasico1.classes0.pessoa4;

public class Pessoa {

    private Integer idade;
    private Float peso;

    public Pessoa(){}

    public Pessoa(final Integer idade){
        this.idade = idade;
    }

    public Pessoa(final Integer idade, final Float peso){
        this.idade = idade;
        this.peso = peso;

    }

    public Integer getIdade(){
        return this.idade;
    }

    public Float getPeso(){
        return peso;
    }

    protected String relatorio(){
        return "idade: " + idade + "e peso: " + peso + "\n";
    }
}
