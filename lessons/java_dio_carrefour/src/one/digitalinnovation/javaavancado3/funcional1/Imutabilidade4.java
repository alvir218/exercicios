package one.digitalinnovation.javaavancado3.funcional1;

import java.util.function.UnaryOperator;

public class Imutabilidade4 {
    public static void main(String[] args) {

        int valor = 20;
        UnaryOperator<Integer> retornarDobro = v -> v * 2;

        /*UnaryOperator<Integer> retornarDobro = v -> {
            valor = 30;
            return v * 2;
        };*/
        //parametro dentro da funcao lambda tem de ser final
        //a variavel valor nao pode ser alterado de 20 pra 30 dentro da lambda

        System.out.println(retornarDobro.apply(valor));
        //40
        System.out.println(valor);
        //20

    }
}
