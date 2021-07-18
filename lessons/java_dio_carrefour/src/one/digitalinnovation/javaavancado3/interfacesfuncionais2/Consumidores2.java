package one.digitalinnovation.javaavancado3.interfacesfuncionais2;

import java.util.function.Consumer;

public class Consumidores2 {
    public static void main(String[] args) {
        //method reference
        //apenas
        //utilizar o parametro da forma que ele foi recebido

        //2 formas
        Consumer<String> imprimirUmaFrase = System.out::println;
        imprimirUmaFrase.accept("hello world");
        //hello world

        Consumer<String> imprimirUmaFrase2 = frase -> System.out.println(frase);
        imprimirUmaFrase2.accept("hello world 2");
        //hello world 2

    }
}
