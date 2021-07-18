package one.digitalinnovation.javabasico1.operadores11;

public class If {
    public static void main(String[] args) {
        final var condicao = false;

        if (condicao){
            System.out.println("a condicao e verdadeira");
        } else{
            System.out.println("a condicao e falsa");
        }

        if(condicao)
            System.out.println("uma unica linha...");

        final var ternario = condicao ? "e verdadeira" : "e falsa";
        System.out.println(ternario);
    }
}
