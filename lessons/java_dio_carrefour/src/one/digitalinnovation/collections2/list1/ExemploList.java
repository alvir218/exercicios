package one.digitalinnovation.collections2.list1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class ExemploList {
    public static void main(String[] args) {

        List<String> nomes = new ArrayList<>();

        nomes.add("carlos");
        nomes.add("pedro");
        nomes.add("juliana");
        nomes.add("anderson");
        nomes.add("maria");
        nomes.add("joao");

        System.out.println(nomes);
        //[carlos, pedro, juliana, anderson, maria, joao]

        nomes.set(2, "larissa");

        System.out.println(nomes);
        //[carlos, pedro, larissa, anderson, maria, joao]

        Collections.sort(nomes);

        nomes.set(2, "wesley");

        System.out.println(nomes);
        //[anderson, carlos, wesley, larissa, maria, pedro]

        nomes.remove(4);

        System.out.println(nomes);
        //[anderson, carlos, wesley, larissa, pedro]

        nomes.remove("wesley");
        System.out.println(nomes);

        String nome = nomes.get(3);
        System.out.println(nome);
        //pedro

        int posicao = nomes.indexOf("carlos");
        System.out.println(posicao);
        //1

        posicao = nomes.indexOf("wesley");
        System.out.println(posicao);
        //-1

        int tamanho = nomes.size();
        System.out.println(tamanho);
        //4

        nomes.remove("larissa");

        tamanho = nomes.size();

        System.out.println(tamanho);
        //3

        boolean temAnderson = nomes.contains("anderson");
        System.out.println(temAnderson);
        //true

        boolean temFernando = nomes.contains("fernando");
        System.out.println(temFernando);
        //false

        boolean listaEstaVazia = nomes.isEmpty();
        System.out.println(listaEstaVazia);
        //false

          //varredura por for in range
        for(String nomeDoItem : nomes){
            System.out.println("varredura por for in range: " + nomeDoItem);
        }
        /*varredura por for in range: anderson
        varredura por for in range: carlos
        varredura por for in range: pedro*/

          //varredura por iterator
        Iterator<String> iterator = nomes.iterator();

        while(iterator.hasNext()){
            System.out.println("varredura por iterator" + iterator.next());
        }
        /*varredura por iteratoranderson
        varredura por iteratorcarlos
        varredura por iteratorpedro*/


        nomes.clear();
        listaEstaVazia = nomes.isEmpty();
        System.out.println(listaEstaVazia);
        //true

    }
}
