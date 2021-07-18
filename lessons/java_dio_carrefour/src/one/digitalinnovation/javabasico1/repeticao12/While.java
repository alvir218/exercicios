package one.digitalinnovation.javabasico1.repeticao12;

public class While {
    public static void main(String[] args) {

        var x = 0;

          //testa a condicao antes
        while(x < 1){
            System.out.println("dentro do while");
            x++;
        }
        //dentro do while


        var y = 0;

          //testa condicao depois
        do{
            System.out.println("dentro do do/while");
        } while(y++ < 1);

/*
        dentro do do/while
        dentro do do/while
*/

    }
}
