package one.digitalinnovation.javabasico1.debug13;

import one.digitalinnovation.javabasico1.debug13.imc.CalculadorDeImc;
import one.digitalinnovation.javabasico1.debug13.pessoa.Pessoa;

public class Programa {
    public static void main(String[] args) {

        final Pessoa pessoa = new Pessoa("andre", 1.9, 100.0);

        final var calculadorDeImc = new CalculadorDeImc();
        final var imc = calculadorDeImc.calcular(pessoa);

        if(imc < 18.5){
            System.out.printf("imc = %.2f\nmagreza\n", imc);
        }else if(imc >= 18.5 && imc <= 24.9){
            System.out.printf("imc = %.2f\nnormal\n", imc);
        }else if(imc >= 25.0 && imc <= 29.9){
            System.out.printf("imc = %.2f\nsobrepeso 1\n", imc);
        }else if(imc >=30.0 && imc <= 39.9){
            System.out.printf("imc = %.2f\nobesidade 2\n", imc);
        }else if(imc >= 40){
            System.out.printf("imc = %.2f\nobesidade grave 3\n", imc);
        }

        System.out.println("o imc de referencia de peso normal\npossui indice menor que 25");
    }
}
