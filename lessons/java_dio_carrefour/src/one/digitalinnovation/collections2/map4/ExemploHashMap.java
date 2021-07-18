package one.digitalinnovation.collections2.map4;

import java.util.HashMap;
import java.util.Map;

public class ExemploHashMap {
    public static void main(String[] args) {

        Map<String, Integer> campeosMuldialFifa = new HashMap<>();
        campeosMuldialFifa.put("brasil", 5);
        campeosMuldialFifa.put("alemanha", 4);
        campeosMuldialFifa.put("italia", 4);
        campeosMuldialFifa.put("uruguai", 2);
        campeosMuldialFifa.put("argentina", 2);
        campeosMuldialFifa.put("franca", 2);
        campeosMuldialFifa.put("inglaterra", 1);
        campeosMuldialFifa.put("espanha", 1);

        System.out.println(campeosMuldialFifa);
        //{inglaterra=1, espanha=1, alemanha=4, italia=4, argentina=2, franca=2, brasil=5, uruguai=2}

        //atualiza o valor para a chave brasil
        campeosMuldialFifa.put("brasil", 6);
        System.out.println(campeosMuldialFifa);
        //{inglaterra=1, espanha=1, alemanha=4, italia=4, argentina=2, franca=2, brasil=6, uruguai=2}

        //retorna a argentina
        System.out.println(campeosMuldialFifa.get("argentina"));
        //2

        //retorna se existe ou nao um capeao franca
        System.out.println(campeosMuldialFifa.containsKey("franca"));
        //true

        //remove o campeao franca
        campeosMuldialFifa.remove("franca");

        //retorna se existe ou nao um campeao franca
        System.out.println(campeosMuldialFifa.containsKey("franca"));
        //false

        //retorna se existe ou nao alguma selecao hexa campea
        System.out.println(campeosMuldialFifa.containsValue(6));
        //true

        //retorna o tamanho do mapa
        System.out.println(campeosMuldialFifa.size());
        //7

        System.out.println(campeosMuldialFifa);
        //{inglaterra=1, espanha=1, alemanha=4, italia=4, argentina=2, brasil=6, uruguai=2}

        //varredura
        System.out.println("for1: \n");
        for(Map.Entry<String, Integer> entry : campeosMuldialFifa.entrySet()){
            System.out.println(entry.getKey() + " - " + entry.getValue());
        }
        /*inglaterra - 1
        espanha - 1
        alemanha - 4
        italia - 4
        argentina - 2
        brasil - 6
        uruguai - 2*/

        System.out.println("for2: \n");
        for(String key : campeosMuldialFifa.keySet()){
            System.out.println(key + " _ " + campeosMuldialFifa.get(key));
        }
        /*inglaterra _ 1
        espanha _ 1
        alemanha _ 4
        italia _ 4
        argentina _ 2
        brasil _ 6
        uruguai _ 2*/

        System.out.println(campeosMuldialFifa);
        //{inglaterra=1, espanha=1, alemanha=4, italia=4, argentina=2, brasil=6, uruguai=2}

        System.out.println("verifica se o mapa contem a chave estados unidos: \n" +
                campeosMuldialFifa.containsKey("estados unidos"));
        //false

        System.out.println("verifica se o mapa contem o valor 5: \n" +
                campeosMuldialFifa.containsValue(5));
        //false

        System.out.println("verifica o tamanho: \n" +
                campeosMuldialFifa.size());
        //7

        campeosMuldialFifa.clear();

        System.out.println("depois de limpar: \n" +
                campeosMuldialFifa.size());
        //0


    }
}
