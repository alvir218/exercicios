package one.digitalinnovation.javabasico1.debug13.imc;

import one.digitalinnovation.javabasico1.debug13.pessoa.Pessoa;

public class CalculadorDeImc {
    public Double calcular(final Pessoa pessoa){
        final var altura = pessoa.getAltura();
        final var imc = pessoa.getPeso() / (altura * altura);
        return imc;
    }
}
