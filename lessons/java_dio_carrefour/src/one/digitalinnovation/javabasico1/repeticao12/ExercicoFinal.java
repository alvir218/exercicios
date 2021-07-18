package one.digitalinnovation.javabasico1.repeticao12;

import java.util.stream.IntStream;

public class ExercicoFinal {
    public static void main(String[] args) {

        IntStream.of(1,2,3,4,5).forEach(n -> {
            System.out.println(n);
        });

/*
        1
        2
        3
        4
        5
*/


        IntStream.range(0,3).forEach(n -> {
            System.out.println("numero = " + n);
        });

        /*numero = 0
        numero = 1
        numero = 2*/
    }
}
