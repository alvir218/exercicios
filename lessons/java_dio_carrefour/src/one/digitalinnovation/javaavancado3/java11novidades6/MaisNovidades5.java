package one.digitalinnovation.javaavancado3.java11novidades6;

import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;

public class MaisNovidades5 {
    public static void main(String[] args) {
        Function<Integer, Double> divisaoPor2 = (var numero) -> numero / 2.0;
        System.out.println(divisaoPor2.apply(1234));

        //Function divisaoPor2b = (var numero) -> numero / 2.0;
        //erro nao pode dividir inteiro por double usando /

        //saber se a string esta em branco
        String espaco = "    ";
        System.out.println(espaco != null || espaco.length() == 0 || espaco.chars().allMatch(c -> c == ' '));
        //true

        String html = "<html>\n<head>\n</head>\n<body>\n</body>\n</html>";
        System.out.println(html.lines().map(s -> "tag: " + s).collect(Collectors.toList()));

        Collection<String> nomes = Arrays.asList("joao", "paulo", "oliveira", "santos");
        System.out.println(nomes);

        Collection<String> nomes2 = List.of("paulo", "oliveira", "joao", "santos");
        System.out.println(nomes2);

        Collection<String> nomes3 = Set.of("oliveira", "joao", "paulo", "santos");
        System.out.println(nomes3);

        //concatenar nome 10 vezes
        String nome2 = "joao";
        String aux = "";
        for (int i = 0; i < 10; i++){
            aux += nome2;
        }
        System.out.println(aux);

        String joao = "joao";
        System.out.println(joao.repeat(10));

    }

}
