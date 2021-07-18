package com.gft.atividade1;

import java.util.Scanner;

public class FuncaoQuadratica {
    public static void main(String[] args) {
        Double a = 0.0;
        Double b = 0.0;
        Double c = 0.0;
        Double delta = 0.0;
        Double x1 = 0.0;
        Double x2 = 0.0;

        Scanner leitura = new Scanner(System.in);

        System.out.println("calculo da funcao quadratica");
        System.out.println("digite o valor de a");
        a = leitura.nextDouble();
        System.out.println("digite o valor de b");
        b = leitura.nextDouble();
        System.out.println("digite o valor de c");
        c = leitura.nextDouble();

        delta = b * b - 4 * a * c;

        if(delta < 0.0){
            System.out.println("impossivel calcular");

        } else if(delta == 0.0){
            x1 = (-1 * b + Math.sqrt(delta)) / (2 * a);
            System.out.println("a raiz dessa equacao e: " + x1);
        } else {
            x1 = (-1 * b + Math.sqrt(delta)) / (2 * a);
            x2 = (-1 * b - Math.sqrt(delta)) / (2 * a);
            System.out.printf("\nx1 = %.5f\n", x1);
            System.out.printf("\nx2 = %.5f\n", x2);
        }

    }
}
