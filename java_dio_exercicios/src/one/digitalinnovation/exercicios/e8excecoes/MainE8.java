package one.digitalinnovation.exercicios.e8excecoes;

import java.util.Optional;

public class MainE8 {
    public static void main(String[] args) {
        Double numero1 = 6.123;
        Double numero2 = 0.0;

        try{
            Double numero3 = numero1 / numero2;
            System.out.println("resultado da divisao e: " + numero3);
        }catch (ArithmeticException e){
            System.out.println("erro durante a divisao, pode ter ocorrido uma indeterminacao");
        }

        try{
            Optional<String> optionalNullErro = Optional.of(null);
            System.out.println("valor optional que lanca erro NullPointerException");

            optionalNullErro.ifPresentOrElse(System.out::println,
                    ()-> System.out.println("erro = nao esta presente"));
        } catch(NullPointerException e){
            System.out.println("o optional nao poderia ser nulo");
        }

        try{
            new java.io.FileInputStream("arquivo.txt");
        } catch(java.io.FileNotFoundException e){
            System.out.println("nao foi possivel abrir arquivo para leitura");
        }


    }
}
