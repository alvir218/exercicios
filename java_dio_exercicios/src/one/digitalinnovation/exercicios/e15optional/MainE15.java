package one.digitalinnovation.exercicios.e15optional;

import java.awt.font.OpenType;
import java.util.Locale;
import java.util.Optional;

public class MainE15 {
    public static void main(String[] args) {
        //vazio presente null

        Optional<String> optionalVazio = Optional.empty();
        Optional<String> optionalPresente = Optional.of("valor presente");
        Optional<String> optionalNull = Optional.ofNullable(null);


        System.out.println("se presente exibir valor\n");
        System.out.println("vazio");
        optionalVazio.ifPresent(System.out::println);
        System.out.println("presente");
        optionalPresente.ifPresent(System.out::println);
        System.out.println("null");
        optionalNull.ifPresent(System.out::println);


        System.out.println("\nse vazio exibir optional vazio\n");
        System.out.println("vazio");
        if(optionalVazio.isEmpty()){
            System.out.println("optional vazio");
        }
        System.out.println("presente");
        if(optionalPresente.isEmpty()){
            System.out.println("optional vazio");
        }
        System.out.println("null");
        if(optionalNull.isEmpty()){
            System.out.println("optional vazio");
        }


        System.out.println("\nse presente, transformar o valor\n");
        System.out.println("vazio");
        optionalVazio.ifPresent((optional) -> {
            System.out.println("__" + optional + "--");
        });

        System.out.println("presente");
        optionalPresente.ifPresent((optional) -> {
            System.out.println("__" + optional + "--");
        });
        System.out.println("null");
        optionalNull.ifPresent((optional) -> {
            System.out.println("__" + optional + "--");
        });


        System.out.println("\nse estiver presente copiar o conteudo para uma variavel e exibi-la\n");
        System.out.println("vazio");
        if(optionalVazio.isPresent()){
            String copiado = optionalVazio.get();
            System.out.println("copiado vazio: " + copiado);
        }

        System.out.println("presente");
        if(optionalPresente.isPresent()){
            String copiado = optionalPresente.get();
            System.out.println("copiado presente: " + copiado);
        }
        System.out.println("null");
        if(optionalNull.isPresent()){
            String copiado = optionalPresente.get();
            System.out.println("copiado null: " + copiado);
        }



        System.out.println("\nse presente, filtrar com uma regra de negocio");
        System.out.println("vazio");
        if(optionalVazio.isPresent()){
            optionalPresente.filter((optional) -> optional.equals("valor presente")).ifPresent(System.out::println);
        }
        System.out.println("presente");
        if(optionalPresente.isPresent()){
            optionalPresente.filter((optional) -> optional.equals("valor presente")).ifPresent(System.out::println);
        }
        System.out.println("null");
        if(optionalNull.isPresent()){
            optionalPresente.filter((optional) -> optional.equals("valor presente")).ifPresent(System.out::println);
        }


        System.out.println("\nse vazio, lancar excecao\n");
        System.out.println("vazio");
        //optionalVazio.orElseThrow(IllegalStateException::new);
        System.out.println("presente");
        optionalPresente.orElseThrow(IllegalStateException::new);
        System.out.println("null");
        //optionalNull.orElseThrow(IllegalStateException::new);


    }
}
