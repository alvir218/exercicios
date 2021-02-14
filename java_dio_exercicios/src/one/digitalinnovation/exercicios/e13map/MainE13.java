package one.digitalinnovation.exercicios.e13map;

import java.util.HashMap;
import java.util.Map;

public class MainE13 {
    public static void main(String[] args) {
        Map<String, String> brasil = new HashMap<>();

        brasil.put("ac", "acre");
        brasil.put("al", "alagoas");
        brasil.put("ap", "amapa");
        brasil.put("am", "amazonas");
        brasil.put("ba", "bahia");
        brasil.put("ce", "ceara");
        brasil.put("es", "espirito santo");
        brasil.put("go", "goias");
        brasil.put("ma", "maranhao");
        brasil.put("mt", "mato grosso");
        brasil.put("ms", "mato grosso do sul");
        brasil.put("mg", "minas gerais");
        brasil.put("pa", "para");
        brasil.put("pb", "paraiba");
        brasil.put("pr", "parana");
        brasil.put("pe", "pernambuco");
        brasil.put("pi", "piaui");
        brasil.put("rj", "rio de janeiro");
        brasil.put("rn", "rio grande do norte");
        brasil.put("rs", "rio grande do sul");
        brasil.put("ro", "rondonia");
        brasil.put("rr", "roraima");
        brasil.put("sc", "santa catarina");
        brasil.put("sp", "sao paulo");
        brasil.put("se", "sergipe");
        brasil.put("to", "tocantins");

        System.out.println(brasil);

        brasil.remove("mg", "minas gerais");
        System.out.println(brasil);

        brasil.put("df", "distrito federal");
        System.out.println(brasil);

        System.out.println("o tamanho do mapa e: " + brasil.size());

        brasil.values().remove("mato grosso do sul");
        System.out.println("mato grosso do sul removido\n" + brasil);

        //nome (sigla)
        System.out.println("\nexibindo mapa em formato personalizado:\n");
        for(String chave : brasil.keySet()){
            System.out.println(brasil.get(chave) + "(" + chave + ")");
        }

        System.out.println("contem santa catarina sc? " + brasil.containsKey("sc"));

        System.out.println("contem maranhao? " + brasil.containsValue("maranhao"));

    }
}
