package one.digitalinnovation.javaavancado3.interfacesfuncionais2;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Iteracoes6 {
    public static void main(String[] args) {
        String[] nomes = {"joao", "paulo", "oliveira", "santos", "joao", "instrutor", "java"};
        Integer[] numeros = {1,2,3,4,5};
        imprimirNomesFiltrados(nomes);
        //joao

        imprimirTodosNomes(nomes);

        imprimirODobroDeCadaItemDaLista(numeros);

        List<String> profissoes = new ArrayList<>();
        profissoes.add("desenvolvedor");
        profissoes.add("testador");
        profissoes.add("gerente de projeto");
        profissoes.add("gerente de qualidade");

        System.out.println("\nfiltrar por gerente e imprimir cada um deles: ");
        profissoes.stream()
                .filter(profissao -> profissao.startsWith("gerente"))
                .forEach(System.out::println);

    }

    public static void imprimirNomesFiltrados(String... nomes){

        String nomesParaImprimir = "";
        for(int i = 0; i < nomes.length; i++){
            if(nomes[i].equals("joao")){
                nomesParaImprimir += " " + nomes[i];
            }
        }
        System.out.println("for: \n" + nomesParaImprimir);

        String nomesParaImprimirDaStream = Stream.of(nomes)
                .filter(nome -> nome.equals("joao"))
                .collect(Collectors.joining(" "));

        System.out.println("stream: \n" + nomesParaImprimirDaStream);


        System.out.println("\nforeach1: ");
        Stream.of(nomes)
                .forEach(nome -> System.out.println(nome));

        System.out.println("\nforeach2: ");
        Stream.of(nomes)
                .forEach(System.out::println);
    }

    public static void imprimirTodosNomes(String... nomes){
        System.out.println("\nimprimindo todos os nomes");

        for(String nome : nomes){
            System.out.println("for: " + nome);
        }

        System.out.println("\nforeach 1: ");
        Stream.of(nomes)
                .forEach(System.out::println);

        Stream.of(nomes)
                .forEach(nome -> System.out.println("foreach 2: " + nome));
    }

    public static void imprimirODobroDeCadaItemDaLista(Integer... numeros){
        System.out.println("\nimprimindo o dobro de cada da lista pelo for: ");

        for(Integer numero : numeros){
            System.out.println(numero * 2);
        }

        System.out.println("\nimprimindo o dobro de cada da lista pelo map foreach: ");
        Stream.of(numeros).map(numero -> numero * 2)
                .forEach(System.out::println);
    }
}
