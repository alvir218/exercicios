package one.digitalinnovation.javabasico1.poojava14.instancia1;

public class Instancia {
    public static void main(String[] args) {
          //instancia
        Pessoa pessoa = new Pessoa();

          //exemplo de metodo
        System.out.println(pessoa.getNome());
        pessoa.setNome("marco paulo");
        System.out.println(pessoa.falarMeuProprioNome());
    }
}
