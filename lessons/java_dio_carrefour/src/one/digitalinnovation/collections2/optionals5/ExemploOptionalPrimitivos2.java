package one.digitalinnovation.collections2.optionals5;

import java.util.Optional;
import java.util.OptionalDouble;
import java.util.OptionalInt;
import java.util.OptionalLong;

public class ExemploOptionalPrimitivos2 {
    public static void main(String[] args) {

        System.out.println("valor inteiro optional");
        OptionalInt.of(3);

        System.out.println("ponto flutuante optional");
        OptionalDouble.of(55.2).ifPresent(System.out::println);
        //55.2

        System.out.println("valor inteiro longo optional");
        OptionalLong.of(123456789L).ifPresent(System.out::println);
        //123456789
    }
}
