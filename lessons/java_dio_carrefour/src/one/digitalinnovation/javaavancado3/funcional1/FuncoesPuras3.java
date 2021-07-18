package one.digitalinnovation.javaavancado3.funcional1;

import java.util.function.BiPredicate;

public class FuncoesPuras3 {
    public static void main(String[] args) {

        BiPredicate<Integer, Integer> verificarSeEMaior =
                (parametro, valorComparacao) -> parametro > valorComparacao;

        System.out.println(verificarSeEMaior.test(13, 12));
        //true
    }
}
