package one.digitalinnovation.javaavancado3.funcional1;

import java.util.HashMap;
import java.util.Map;

public class FatorialMemoization8 {
    static Map<Integer, Integer> MAPA_FATORIAL = new HashMap<>();

    public static void main(String[] args) {
        long inicio = System.nanoTime();
        System.out.println(fatorialComMemoization(15));
        long fim = System.nanoTime();
        System.out.println("fatorial 1: " + (fim - inicio));

        inicio = System.nanoTime();
        System.out.println(fatorialComMemoization(15));
        fim = System.nanoTime();
        System.out.println("fatorial 2: " + (fim - inicio));
    }

    public static Integer fatorialComMemoization(Integer value){
        if(value == 1){
            return value;
        } else{
            if(MAPA_FATORIAL.containsKey(value)){
                return MAPA_FATORIAL.get(value);
            } else{
                Integer resultado = value * fatorialComMemoization(value - 1);
                MAPA_FATORIAL.put(value, resultado);
                return resultado;
            }
        }
    }
}
