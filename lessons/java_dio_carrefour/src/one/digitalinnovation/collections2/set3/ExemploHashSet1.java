package one.digitalinnovation.collections2.set3;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class ExemploHashSet1 {
    public static void main(String[] args) {
        Set<Double> notasAlunos = new HashSet<>();

        notasAlunos.add(5.8);
        notasAlunos.add(9.3);
        notasAlunos.add(6.5);
        notasAlunos.add(10.0);
        notasAlunos.add(5.4);
        notasAlunos.add(7.3);
        notasAlunos.add(3.8);
        notasAlunos.add(4.0);

        System.out.println(notasAlunos);

        //remove a nota do set
        notasAlunos.remove(3.8);
        System.out.println(notasAlunos);

        //retorna a quantidade de itens do set
        System.out.println("retorna a quantidade de itens do set: " +
                notasAlunos.size());

        //varredura
        System.out.println("varredura");
        Iterator<Double> iterator = notasAlunos.iterator();
        while(iterator.hasNext()){
            System.out.println("iterator: " + iterator.next());
        }

        for(Double nota : notasAlunos){
            System.out.println("for: " + nota);
        }

        notasAlunos.clear();

        System.out.println("retorna se esta vazio ou nao: " +
                notasAlunos.isEmpty());

    }
}
