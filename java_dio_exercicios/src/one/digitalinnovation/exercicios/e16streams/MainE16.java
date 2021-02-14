package one.digitalinnovation.exercicios.e16streams;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class MainE16 {
    public static void main(String[] args) {
        List<Estudante> estudantes = new ArrayList<>();

        estudantes.add(new Estudante("joao", 18));
        estudantes.add(new Estudante("pedro", 16));
        estudantes.add(new Estudante("bianca", 17));
        estudantes.add(new Estudante("tadeu", 15));
        estudantes.add(new Estudante("marcela", 19));
        estudantes.add(new Estudante("bruno", 18));
        estudantes.add(new Estudante("josefina", 19));
        System.out.println(estudantes);

        System.out.println("\nconvertendo lista para array de strings");
        System.out.println(estudantes.stream()
                .map(estudante -> estudante.toString()).collect(Collectors.toList()));

        System.out.println("\nquantos estudantes tem na lista?" +
                estudantes.stream().count());

        System.out.println("\nmaiores de idade\n" +
                estudantes.stream()
                        .filter(estudante ->
                                estudante.getIdade() >= 18)
                        .collect(Collectors.toList()));

        System.out.println("\nexibindo cada elemento no console");
        estudantes.forEach(estudante -> System.out.println(estudante.getNome()));

        System.out.println("\nquem tem letra b no nome\n" +
                estudantes.stream()
        .filter(estudante ->
                estudante.getNome().contains("b"))
                        .collect(Collectors.toList()));

        System.out.println("\nexiste alguem com a letra d no nome? " +
                estudantes.stream().anyMatch(estudante ->
                        estudante.getNome().contains("d")));

        System.out.println("\nquem e o mais velho? " +
                estudantes.stream()
                        .max(Comparator.comparingInt(Estudante::getIdade)).get());

        System.out.println("\nquem e o mais novo? " +
                estudantes.stream()
                        .min(Comparator.comparingInt(Estudante::getIdade)).get());
    }
}
