package one.digitalinnovation.javabasico1.operadores11;

public class Igualdade {
    public static void main(String[] args) {

        final var numero = 11;

        if(numero == 10){
            System.out.println("o numero e 10");
        } else{
            System.out.println("o numero nao e 10");
        }

        if(numero != 10){
            System.out.println("o numero nao e 10");
        } else{
            System.out.println("o numero e 10");
        }

        final var letra = "b";

        if("a".equals(letra)){
            System.out.println("e a letra a");
        }

        if(!letra.equals("a")){
            System.out.println("nao e a letra a");
        }


    }
}
