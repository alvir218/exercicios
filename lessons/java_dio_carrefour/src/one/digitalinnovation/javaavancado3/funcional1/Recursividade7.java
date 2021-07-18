package one.digitalinnovation.javaavancado3.funcional1;

public class Recursividade7 {
    public static void main(String[] args) {
        System.out.println(fatorial(5));
        System.out.println(fatorialTailCall(5, 1));
    }

    public static int fatorial(int value){
        if(value == 1){
            return value;
        } else{
            return value * fatorial((value -1));
        }
    }

    public static double fatorialTailCall(double valor, double numero){
        if(valor == 0){
            return numero;
        }
        return fatorialTailCall(valor - 1, numero * valor);
    }
}
