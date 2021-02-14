package one.digitalinnovation.exercicios.e12set;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class MainE12 {
    public static void main(String[] args) {
        Set<Integer> numeros = new HashSet<>();
        numeros.add(3);
        numeros.add(88);
        numeros.add(20);
        numeros.add(44);
        numeros.add(3);

        System.out.println("varrendo set for: ");
        for(Integer numero : numeros){
            System.out.println(numero);
        }

        System.out.println("varrendo set iterator: ");
        Iterator iterador = numeros.iterator();
        while(iterador.hasNext()){
            System.out.println(iterador.next());
        }

        for(Integer numero : numeros){
            numeros.remove(numero);
            break;
        }

        System.out.println("removido o primeiro: \n" + numeros);

        numeros.add(23);
        System.out.println("adicionado 23: \n" + numeros);

        System.out.println("o tamanho do set e: " + numeros.size());

        System.out.println("o set esta vazio: " + numeros.isEmpty());

    }
}
