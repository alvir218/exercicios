package one.digitalinnovation.collections2.optionals5;

import java.util.Optional;

public class ExemploOptional3 {
    public static void main(String[] args) {

        Optional<String> optionalString = Optional.of("valor opcional");

        if(optionalString.isPresent()){
            System.out.println(optionalString.get());
        }
        //valor opcional

        System.out.println(optionalString.isPresent());
        //true

        optionalString.ifPresent(System.out::println);
        //valor opcional

        optionalString.ifPresentOrElse(System.out::println,
                ()-> System.out.println("valor nao esta presente"));
        //valor opcional

        if(optionalString.isPresent()){
            String valor = optionalString.get();
            System.out.println(valor);
        }
        //valor opcional

        optionalString.map((valor)->valor.concat("****")).ifPresent(System.out::println);
        //valor opcional****

        optionalString.orElseThrow(IllegalStateException::new);
    }
}
