package one.digitalinnovation.javabasico1.operadores11;

public class Relacionais {
    public static void main(String[] args) {

        final var numero = 6;

        if(numero > 20){
            System.out.println("o numero e maior que 20");
        } else if(numero >= 10){
            System.out.println("o numero e maior ou igual a 10");
        } else if(numero <= 5){
            System.out.println("o numero e menor ou igual que 5");
        } else{
            System.out.println("nenhuma das anteriores");
        }
    }
}
