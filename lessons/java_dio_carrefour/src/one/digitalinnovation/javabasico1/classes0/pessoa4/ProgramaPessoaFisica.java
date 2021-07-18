package one.digitalinnovation.javabasico1.classes0.pessoa4;

public class ProgramaPessoaFisica {
    public static void main(String[] args) {

        final PessoaFisica pessoaFisica = new PessoaFisica(33, 100.1f);

        System.out.println(pessoaFisica.relatorio());
    }
}
