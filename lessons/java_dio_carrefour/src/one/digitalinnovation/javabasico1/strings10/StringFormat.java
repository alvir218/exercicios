package one.digitalinnovation.javabasico1.strings10;

public class StringFormat {
    public static void main(String[] args) {

        var nome = "andre";
        var sobreNome = "gomes";
        final var nomeCompleto = nome + sobreNome;

        System.out.println(nome);
          //andre
        System.out.println("nome do cliente: " + nome);
          //nome do cliente: andre
        System.out.println("nome completo do cliente: " + nomeCompleto);
          //nome completo do cliente: andregomes
        final var mensagem = String.format("o cliente %s possui sobrenome %s", nome, sobreNome);
        System.out.println(mensagem);
          //o cliente andre possui sobrenome gomes

        System.out.println(String.format("numero %.2f arredondado com 2 casas decimais", 1.2375d));
          //numero 1,24 arredondado com 2 casas decimais
    }
}
