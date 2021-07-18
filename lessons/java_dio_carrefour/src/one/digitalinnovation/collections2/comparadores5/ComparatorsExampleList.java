package one.digitalinnovation.collections2.comparadores5;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ComparatorsExampleList {
    public static void main(String[] args) {

        List<Estudante> estudantes = new ArrayList<>();

        estudantes.add(new Estudante("pedro", 19));
        estudantes.add(new Estudante("carlos", 23));
        estudantes.add(new Estudante("mariana", 21));
        estudantes.add(new Estudante("joao", 18));
        estudantes.add(new Estudante("thiago", 20));
        estudantes.add(new Estudante("george", 22));
        estudantes.add(new Estudante("larissa", 21));

        System.out.println("ordem de insercao");
        System.out.println(estudantes);
        //[pedro - 19, carlos - 23, mariana - 21, joao - 18, thiago - 20, george - 22, larissa - 21]

        estudantes.sort((first, second) -> first.getIdade() - second.getIdade());
        System.out.println("ordem natural dos numeros - idade");
        System.out.println(estudantes);
        //[joao - 18, pedro - 19, thiago - 20, mariana - 21, larissa - 21, george - 22, carlos - 23]

        estudantes.sort((first, second) -> second.getIdade() - first.getIdade());
        System.out.println("ordem reversa dos numeros - idade");
        System.out.println(estudantes);
        //[carlos - 23, george - 22, mariana - 21, larissa - 21, thiago - 20, pedro - 19, joao - 18]

        estudantes.sort(Comparator.comparingInt(Estudante::getIdade));
        System.out.println("ordem natural dos numeros - idade (method reference)");
        System.out.println(estudantes);
        //[joao - 18, pedro - 19, thiago - 20, mariana - 21, larissa - 21, george - 22, carlos - 23]

        estudantes.sort(Comparator.comparingInt(Estudante::getIdade).reversed());
        System.out.println("ordem reversa dos numeros - idade (method reference)");
        System.out.println(estudantes);
        //[carlos - 23, george - 22, mariana - 21, larissa - 21, thiago - 20, pedro - 19, joao - 18]

        Collections.sort(estudantes);
        System.out.println("ordem natural dos numeros - idade (interface comparable)");
        System.out.println(estudantes);
        //[joao - 18, pedro - 19, thiago - 20, mariana - 21, larissa - 21, george - 22, carlos - 23]

        Collections.sort(estudantes, new EstudanteOrdemReversaComparator());
        System.out.println("ordem reversa dos numeros - idade (interface comparator)");
        System.out.println(estudantes);
        //[carlos - 23, george - 22, mariana - 21, larissa - 21, thiago - 20, pedro - 19, joao - 18]

    }
}
