package one.digitalinnovation.javabasico1.poojava14.encapsulamento2;

public class Exemplo1 {
    public static void main(String[] args) {

        Pessoa eu = new Pessoa("marco", 19, 05, 1990);

        System.out.println(eu.getNome());
        System.out.println(eu.getDataNascimento());
        System.out.println(eu.calculaIdade());

        eu.setNome("marco paulo");

        System.out.println(eu.getNome());
    }
}
