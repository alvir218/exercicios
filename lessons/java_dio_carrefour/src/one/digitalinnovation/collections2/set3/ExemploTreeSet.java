package one.digitalinnovation.collections2.set3;

import java.util.Iterator;
import java.util.TreeSet;

public class ExemploTreeSet {
    public static void main(String[] args) {

        TreeSet<String> treeCapitais = new TreeSet<>();

        treeCapitais.add("porto alegre");
        treeCapitais.add("florianopolis");
        treeCapitais.add("curitiba");
        treeCapitais.add("sao paulo");
        treeCapitais.add("rio de janeiro");
        treeCapitais.add("belo horizonte");

        System.out.println(treeCapitais);
        //[belo horizonte, curitiba, florianopolis, porto alegre, rio de janeiro, sao paulo]

        System.out.println("retorna a primeira capital no topo da arvore:\n" +
                treeCapitais.first());
        //belo horizonte

        System.out.println("retorna a ultima capital no final da arvore:\n" +
                treeCapitais.last());
        //sao paulo

        System.out.println("retorna a primeira capital abaixo na arvore da capital parametrizada: \n" +
                treeCapitais.lower("florianopolis"));
        //curitiba

        System.out.println("retorna a primeira capital acima na arvore da capital parametrizada: \n" +
                treeCapitais.higher("florianopolis"));
        //porto alegre

        System.out.println("exibe todas as capitais no console:\n" +
                treeCapitais);
        //[belo horizonte, curitiba, florianopolis, porto alegre, rio de janeiro, sao paulo]

        System.out.println("retorna a primeira capital no topo da arvore, removendo do set: " +
                treeCapitais.pollFirst());
        //belo horizonte

        System.out.println("retorna a primeira capital no final da arvore, removendo do set: " +
                treeCapitais.pollLast());
        //sao paulo

        System.out.println("exibe todas as capitais no console:\n" + treeCapitais);
        //[curitiba, florianopolis, porto alegre, rio de janeiro]

        //varredura
        Iterator<String> iterator = treeCapitais.iterator();
        while(iterator.hasNext()){
            System.out.println("iterator: " + iterator.next());
        }
        /*iterator: curitiba
        iterator: florianopolis
        iterator: porto alegre
        iterator: rio de janeiro*/

        for(String capital : treeCapitais){
            System.out.println("for: " + capital);
        }
        /*for: curitiba
        for: florianopolis
        for: porto alegre
        for: rio de janeiro*/
    }
}
