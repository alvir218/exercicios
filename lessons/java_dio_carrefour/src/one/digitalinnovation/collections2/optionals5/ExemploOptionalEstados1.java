package one.digitalinnovation.collections2.optionals5;

import java.util.Optional;

public class ExemploOptionalEstados1 {
    public static void main(String[] args) {

        Optional<String> optionalString = Optional.of("valor presente");

        System.out.println("valor optional que esta presente");
        optionalString.ifPresentOrElse(System.out::println,
                ()-> System.out.println("nao esta presente"));
        //valor presente

        Optional<String> optionalNull = Optional.ofNullable(null);
        System.out.println("valor optional que nao esta presente");
        optionalNull.ifPresentOrElse(System.out::println,
                ()-> System.out.println("null = nao esta presente"));
        //null = nao esta presente

        Optional<String> emptyOptional = Optional.empty();
        System.out.println("valor optional que nao esta presente");
        emptyOptional.ifPresentOrElse(System.out::println,
                ()-> System.out.println("empty = nao esta presente"));
        //empty = nao esta presente

        Optional<String> optionalNullErro = Optional.of(null);
        System.out.println("valor optional que lanca erro NullPointerException");
        optionalNullErro.ifPresentOrElse(System.out::println,
                ()-> System.out.println("erro = nao esta presente"));
/*
        Exception in thread "main" java.lang.NullPointerException
        at java.base/java.util.Objects.requireNonNull(Objects.java:208)
        at java.base/java.util.Optional.of(Optional.java:111)
        at one.digitalinnovation.collections2.optionals5.ExemploOptionalEstados.main(ExemploOptionalEstados.java:24)
*/

    }
}
