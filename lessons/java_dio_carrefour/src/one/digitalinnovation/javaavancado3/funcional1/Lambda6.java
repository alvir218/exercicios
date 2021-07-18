package one.digitalinnovation.javaavancado3.funcional1;

public class Lambda6 {
    public static void main(String[] args) {

        //Funcao1 gerarUmaSaida = valor -> valor;
        //tambem funciona

        //implementando interface com funcao
        Funcao colocarPrefixoSenhorNaStringFuncao = new Funcao(){
            @Override
            public String gerar(String valor){
                return "sr. "+ valor;
            }
        };

        System.out.println(colocarPrefixoSenhorNaStringFuncao.gerar("joao"));
        //sr. joao



        //implementando interface usando lambda
        Funcao colocarPrefixoSenhorNaStringLambda = valor -> {
            String valorComPrefixo = "sr. " + valor;
            String valorComPrefixoEPontoFinal = valorComPrefixo + ".";
            return valorComPrefixoEPontoFinal;
        };

        System.out.println(colocarPrefixoSenhorNaStringLambda.gerar("joao"));
        //sr. joao

    }

    @FunctionalInterface
    interface Funcao {
        String gerar(String valor);
        //Integer gerarNumero(String valor);
        /*default Integer gerarNumero(String valor){
        }*/
        //String gerarN(Integer valor);
    }
}
