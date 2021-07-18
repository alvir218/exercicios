package one.digitalinnovation.javaavancado3.interfacesfuncionais2;

public class FuncaoAltaOrdem1 {
    public static void main(String[] args) {
        Calculo soma = (a, b) -> a + b;
        Calculo subtracao = (a, b) -> a - b;
        Calculo multiplicacao = (a, b) -> a * b;
        Calculo divisao = (a, b) -> a / b;

        System.out.println(executarOperacao(soma, 1, 3));
        //4
        System.out.println(executarOperacao(subtracao, 4, 3));
        //1
        System.out.println(executarOperacao(multiplicacao, 7, 3));
        //21
        System.out.println(executarOperacao(divisao, 4, 2));
        //2

    }

    public static int executarOperacao(Calculo calculo, int a, int b){
        return calculo.calcular(a, b);
    }

    public int soma(int a, int b){
        return a + b;
    }

    @FunctionalInterface
    interface Calculo{
        public int calcular(int a, int b);
    }
    //por parametro recebe outra funcao
    //ou que ela retorna uma funcao
}
