package one.digitalinnovation.javaavancado3.interfacesfuncionais2;

import java.util.function.Supplier;

public class Suppliers5 {
    public static void main(String[] args) {
        //ambos validos
        Supplier<Pessoa> suppliers = () -> new Pessoa();
        System.out.println(suppliers.get());
        //nome: joao, idade: 23

        Supplier<Pessoa> suppliers2 = Pessoa::new;
        System.out.println(suppliers2.get());
        //nome: joao, idade: 23
    }
}

class Pessoa{
    private String nome;
    private Integer idade;

    public Pessoa(){
        nome = "joao";
        idade = 23;
    }

    @Override
    public String toString(){
        return String.format("nome: %s, idade: %d",nome, idade);
    }
}