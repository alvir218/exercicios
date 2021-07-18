package one.digitalinnovation.collections2.set3;

import java.util.Iterator;
import java.util.LinkedHashSet;

public class ExemploLinkedHashSet {
    public static void main(String[] args) {

        LinkedHashSet<Integer> sequenciaNumerica = new LinkedHashSet<>();

        sequenciaNumerica.add(1);
        sequenciaNumerica.add(2);
        sequenciaNumerica.add(4);
        sequenciaNumerica.add(8);
        sequenciaNumerica.add(16);

        System.out.println(sequenciaNumerica);

        //remove o numero do set
        sequenciaNumerica.remove(4);

        System.out.println(sequenciaNumerica);

        System.out.println("retorna a quantidade de itens do set: " +
                sequenciaNumerica.size());

        //varredura
        Iterator<Integer> iterator = sequenciaNumerica.iterator();
        while(iterator.hasNext()){
            System.out.println("iterador: " + iterator.next());
        }

        for(Integer numero : sequenciaNumerica){
            System.out.println(numero);
        }

        System.out.println("retorna se esta vazio ou nao: " +
                sequenciaNumerica.isEmpty());
    }
}
