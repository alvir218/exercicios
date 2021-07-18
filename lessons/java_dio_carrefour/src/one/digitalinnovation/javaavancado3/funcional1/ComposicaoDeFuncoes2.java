package one.digitalinnovation.javaavancado3.funcional1;

import java.util.Arrays;

public class ComposicaoDeFuncoes2 {
    public static void main(String[] args) {
        int[] valores = {1,2,3,4};
        Arrays.stream(valores)
                .filter(numero -> numero % 2 == 0)
                .map(numero -> numero * 2)
                .forEach(numero -> System.out.println(numero));

        //equivalente
        for(int i = 0; i < valores.length; i++){
            int valor = 0;
            if(valores[i] % 2 == 0){
                valor = valores[i] * 2;
            }
            if(valor != 0){
                System.out.println(valor);
            }
        }
        //4 8
    }
}
