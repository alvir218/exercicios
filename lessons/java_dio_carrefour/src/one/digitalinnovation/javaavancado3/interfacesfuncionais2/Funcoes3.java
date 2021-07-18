package one.digitalinnovation.javaavancado3.interfacesfuncionais2;

import java.util.function.Function;

public class Funcoes3 {
    public static void main(String[] args) {
        Function<String, String> retornarNomeAoContrario = texto ->
                new StringBuilder(texto)
                        .reverse()
                        .toString();

        System.out.println(retornarNomeAoContrario.apply("joao"));
        //oaoj

        Function<String, Integer> converterStringParaInteiro = string ->
                Integer.valueOf(string);

        System.out.println(converterStringParaInteiro.apply("12"));
        //12

        Function<String, Integer> converterStringParaInteiroDobrado = string ->
                Integer.valueOf(string) * 2;

        System.out.println(converterStringParaInteiroDobrado.apply("3"));
        //6

    }
}
