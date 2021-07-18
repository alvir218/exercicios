package one.digitalinnovation.javaavancado3.funcional1;

import java.util.function.UnaryOperator;

public class Funcional1 {
    public static void main(String[] args) {
        UnaryOperator<Integer> calcularValorVezes3 = valor -> valor * 3;
        int valor = 10;
        System.out.println("o resultado e " +
                calcularValorVezes3.apply(3));
    }

    //incorreto
    /*public static void calcular(somar(x,y)){

    }

    public static int somar(int x, int y){
        return x + y;
    }*/
}
