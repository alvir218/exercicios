package one.digitalinnovation.javabasico1.operadores11;

public class Logicos {
    public static void main(String[] args) {

        final var numero = 2;
        final var letra = "a";

          //sort circuit
        if (numero < 5 && letra.equals("a")){
            System.out.println("atendeu a condicao");
        }

        if(numero < 5 || letra.equals("a")){
            System.out.println("atendeu a outra condicao");
        }

        if((10 - 5) > 1 && (5 - 3) > 1){
            System.out.printf("logica maluca");
        }

          //non sort circuit
        if(verifica(15) | verifica("a")){
            System.out.println("ok");
        } else {
            System.out.println("nao ok");
        }

    }

    private static boolean verifica(String letra){
        System.out.println("verificando letra...");
        return letra.equals("a");
    }

    private static boolean verifica(Integer numero){
        System.out.println("verificando numero...");
        return numero > 10;
    }

}
