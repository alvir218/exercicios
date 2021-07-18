package one.digitalinnovation.javaavancado3.interfacesfuncionais2;

import java.util.function.Predicate;

public class Predicados4 {
    public static void main(String[] args) {
        Predicate<String> estaVazio = valor -> valor.isEmpty();
        System.out.println(estaVazio.test(""));
        //true
        System.out.println(estaVazio.test("joao"));
        //false
    }
}
