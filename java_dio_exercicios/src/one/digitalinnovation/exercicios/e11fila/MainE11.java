package one.digitalinnovation.exercicios.e11fila;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class MainE11 {
    public static void main(String[] args) {
        Queue<String> fila = new LinkedList<>();

        fila.add("juliana");
        fila.add("pedro");
        fila.add("carlos");
        fila.add("larissa");
        fila.add("joao");

        System.out.println("\nmembros da fila for in range:");
        for(String membro : fila){
            System.out.println(membro);
        }

        System.out.println("\nmembros da fila iterator");
        Iterator iterador = fila.iterator();
        while(iterador.hasNext()){
            System.out.println(iterador.next());
        }

        System.out.println("o primeiro da fila e: " + fila.peek());
        System.out.println(fila);

        System.out.printf("\nremovendo %s da fila\n", fila.poll());
        System.out.println(fila);

        fila.add("daniel");
        System.out.println("o daniel foi adicionado na posicao: " + fila.size());

        System.out.println("tamanho da fila: " + fila.size());

        System.out.println("a fila esta vazia? " + fila.isEmpty());

        System.out.println("carlos esta na fila? " + fila.contains("carlos"));

    }
}
