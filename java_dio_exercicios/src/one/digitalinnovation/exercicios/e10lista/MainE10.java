package one.digitalinnovation.exercicios.e10lista;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class MainE10 {
    public static void main(String[] args) {
        List<String> nomes = new ArrayList<>();

        nomes.add("juliana");
        nomes.add("pedro");
        nomes.add("carlos");
        nomes.add("larissa");
        nomes.add("joao");
        System.out.println(nomes);

        System.out.println("\nmembros da lista iterator while:");
        Iterator iterador = nomes.iterator();
        while(iterador.hasNext()){
            System.out.println(iterador.next());
        }

        System.out.println("\nmembros da lista for range based:");
        for(String membro : nomes){
            System.out.println(membro);
        }

        nomes.set(nomes.indexOf("carlos"), "roberto");
        System.out.println(nomes);

        System.out.println("nome da posicao 1: " + nomes.get(1));

        nomes.remove(4);
        System.out.println(nomes);

        System.out.println("a lista contem " + nomes.size() + " nomes");

        System.out.println("tem juliano? " + nomes.contains("juliano"));

        List<String> nomesExtra = new ArrayList<>();

        nomesExtra.add("ismael");
        nomesExtra.add("rodrigo");

        for(String nome : nomesExtra){
            nomes.add(nome);
        }

        System.out.println(nomes);

        Collections.sort(nomes);
        System.out.println("ordenado\n" + nomes);

        System.out.println("a lista esta vazia? " + nomes.isEmpty());

    }
}
