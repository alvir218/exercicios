package one.digitalinnovation.collections2.streams6;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class ExemploStreamApi {
    public static void main(String[] args) {

        //cria a colecao de estudantes
        List<String> estudantes = new ArrayList<>();

        estudantes.add("pedro");
        estudantes.add("thayse");
        estudantes.add("marcelo");
        estudantes.add("carla");
        estudantes.add("juliana");
        estudantes.add("thiago");
        estudantes.add("rafael");

        System.out.println("retorna a contagem de elementos do stream:\n" +
                estudantes.stream().count());

        System.out.println("retorna o elemento com o maior numero de letras:\n" +
                estudantes.stream()
                        .max(Comparator
                                .comparingInt(String::length)));

        System.out.println("retorna o elemento com o menor numero de letras:\n" +
                estudantes.stream()
                        .min(Comparator
                                .comparingInt(String::length)));

        System.out.println("retorna os elementos que tem a letra r no nome:\n" +
                estudantes.stream().
                        filter((estudante)->
                                estudante
                                        .toLowerCase()
                                        .contains("r"))
                        .collect(Collectors.toList()));

        System.out.println("retorna uma nova colecao, com os nomes concatenados a quantidade de letra de cada nome:\n" +
                estudantes.stream().map(estudante ->
                        estudante.concat(" - ")
                                .concat(String.valueOf(estudante.length())))
                        .collect(Collectors.toList()));

        System.out.println("retorna somente os 3 primeiros elementos da colecao:\n" +
                estudantes
                        .stream()
                        .limit(3)
                        .collect(Collectors.toList()));

        System.out.println("exibe cada elemento no console, e depois retorna a mesma colecao\n" +
                estudantes.stream()
                        .peek(System.out::println)
                        .collect(Collectors.toList()));

        System.out.println("exibe cada elemento no console sem retornar outra colecao\n");
        estudantes.stream().forEach(System.out::println);

        System.out.println("retorna true se todos os elementos possuirem a letra w no nome\n" +
                estudantes.stream()
                        .allMatch((elemento)->
                                elemento.contains("w")));

        System.out.println("retorna true se algum dos elementos possui a letra a no nome\n" +
                estudantes.stream()
                        .anyMatch((elemento)->
                                elemento.contains("a")));

        System.out.println("retorna true se nenhum elemento possuir a letra a no nome\n" +
                estudantes.stream()
                        .noneMatch((elemento)->
                                elemento.contains("a")));

        System.out.println("retorna o primeiro elemento da colecao, se existir exibe no console\n");
        estudantes.stream()
                .findFirst()
                .ifPresent(System.out::println);

        System.out.println("operacao em cadeia");
        System.out.println(estudantes.stream().
                peek(System.out::println)
                .map(estudante ->
                        estudante.concat(" - ")
                                .concat(String.valueOf(estudante.length())))
                .peek(System.out::println)
                .filter((estudante)->
                        estudante.toLowerCase().contains("r"))
                .collect(Collectors.toList()));
                /*.collect(Collectors.joining(", "))
                .collect(Collectors.toSet())
                .collect(Collectors.groupingBy(estudante -> estudante.substring(estudante.indexOf("-" + 1))));*/
    }
}
