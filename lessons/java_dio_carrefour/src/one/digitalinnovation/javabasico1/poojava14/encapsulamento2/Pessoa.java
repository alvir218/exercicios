package one.digitalinnovation.javabasico1.poojava14.encapsulamento2;

import java.time.LocalDate;
import java.time.Period;

public class Pessoa {

    private String nome;
    private LocalDate dataNascimento;

    public Pessoa(String nome, int dia, int mes, int ano){
        this.nome = nome;
        this.dataNascimento = LocalDate.of(ano,mes,dia);
    }

    public int calculaIdade(){
        return Period.between(dataNascimento, LocalDate.now()).getYears();
    }

    public String getNome(){
        return nome;
    }

    public LocalDate getDataNascimento(){
        return dataNascimento;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
}
