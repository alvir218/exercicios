package one.digitalinnovation.collections2.map4;

import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class ExemploTreeMap {
    public static void main(String[] args) {

        TreeMap<String, String> treeCapitais = new TreeMap<>();

        treeCapitais.put("rs", "porto alegre");
        treeCapitais.put("sc", "florianopolis");
        treeCapitais.put("pr", "curitiba");
        treeCapitais.put("sp", "sao paulo");
        treeCapitais.put("rj", "rio de janeiro");
        treeCapitais.put("mg", "belo horizonte");

        System.out.println(treeCapitais);
        //{mg=belo horizonte, pr=curitiba, rj=rio de janeiro, rs=porto alegre, sc=florianopolis, sp=sao paulo}

        System.out.println("retorna a primeira capital no topo da arvore:\n" +
                treeCapitais.firstKey());
        //mg

        System.out.println("retorna a ultima capital no fim da arvore:\n" +
                treeCapitais.lastKey());
        //sp

        System.out.println("retorna a primeira capital abaixo na arvore da capital parametrizada:\n" +
                treeCapitais.lowerKey("sc"));
        //rs

        System.out.println("retorna a primeira capital acima na arvore da capital parametrizada:\n" +
                treeCapitais.higherKey("sc"));
        //sp

        System.out.println(treeCapitais);
        //{mg=belo horizonte, pr=curitiba, rj=rio de janeiro, rs=porto alegre, sc=florianopolis, sp=sao paulo}

        System.out.println("retorna a primeira capital no topo da arvore:\n" +
                treeCapitais.firstEntry().getKey() +
                " - " +
                treeCapitais.firstEntry().getValue());
        //mg - belo horizonte

        System.out.println("retorna a ultima capital no final da arvore:\n" +
                treeCapitais.lastEntry().getKey() +
                " - " +
                treeCapitais.lastEntry().getValue());
        //sp - sao paulo

        System.out.println("retorna a primeira capital abaixo na arvore da capital parametrizada:\n" +
                treeCapitais.lowerEntry("sc").getKey() +
                " - " +
                treeCapitais.lowerEntry("sc").getValue());
        //rs - porto alegre

        System.out.println("retorna a primeira capital acima da arvore da capital parametrizada:\n" +
                treeCapitais.higherEntry("sc").getKey() +
                " - " +
                treeCapitais.higherEntry("sc").getValue());
        //sp - sao paulo

        System.out.println("exibe todas as capitais no console:\n" + treeCapitais);
        //{mg=belo horizonte, pr=curitiba, rj=rio de janeiro, rs=porto alegre, sc=florianopolis, sp=sao paulo}

        Map.Entry<String, String> firstEntry = treeCapitais.pollFirstEntry();
        Map.Entry<String, String> lastEntry = treeCapitais.pollLastEntry();

        System.out.println("retorna a primeira capital no topo da arvore, removendo do map:\n" +
                firstEntry.getKey() +
                " - " +
                firstEntry.getValue());
        //mg - belo horizonte

        System.out.println(treeCapitais);
        //{pr=curitiba, rj=rio de janeiro, rs=porto alegre, sc=florianopolis}

        //varredura nas chaves
        Iterator<String> iterator = treeCapitais.keySet().iterator();
        while(iterator.hasNext()){
            String key = iterator.next();
            System.out.println("iterator: " +
                    key +
                    " - " +
                    treeCapitais.get(key));
        }

        /*iterator: pr - curitiba
        iterator: rj - rio de janeiro
        iterator: rs - porto alegre
        iterator: sc - florianopolis*/

        for(String capital : treeCapitais.keySet()){
            System.out.println("for1: " +
                    capital +
                    " - " +
                    treeCapitais.get(capital));
        }
        /*for1: pr - curitiba
        for1: rj - rio de janeiro
        for1: rs - porto alegre
        for1: sc - florianopolis*/

        for(Map.Entry<String, String> capital : treeCapitais.entrySet()){
            System.out.println("for2: " +
                    capital.getKey() + " - " +
                    capital.getValue());
        }
        /*for2: pr - curitiba
        for2: rj - rio de janeiro
        for2: rs - porto alegre
        for2: sc - florianopolis*/

    }
}
