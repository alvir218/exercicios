package one.digitalinnovation.javaavancado3.paralelismo3;

import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;

public class ParallelStreamsExemplo5 {
    public static void main(String[] args) {
        long inicio = System.currentTimeMillis();
        IntStream.range(1, 100000).forEach(num -> fatorial(num));
        long fim = System.currentTimeMillis();
        System.out.println("tempo calculo fatorial serial: " + (fim - inicio));

        inicio = System.currentTimeMillis();
        IntStream.range(1, 100000).parallel().forEach(num -> fatorial(num));
        fim = System.currentTimeMillis();
        System.out.println("tempo calculo fatorial parallel: " + (fim - inicio));

        List<String> nomes = Arrays.asList("joao", "paulo", "oliveira", "santos");
        nomes.parallelStream().forEach(System.out::println);
    }

    public static long fatorial(long num){
        long fat = 1;

        for(long i = 2; i <= num; i++){
            fat *= i;
        }
        return fat;
    }
}
