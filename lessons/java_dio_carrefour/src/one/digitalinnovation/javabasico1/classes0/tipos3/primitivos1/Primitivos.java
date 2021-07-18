package one.digitalinnovation.javabasico1.classes0.tipos3.primitivos1;

public class Primitivos {
    public static void main(String[] args) {

        //inteiros

          //8bits 127 ~ -128
        byte b;
        byte b1 = 127;
        byte b2 = -128;

          //caractere de 16bits
          //somente um caractere
          //numero sem aspas representa um caractere ascii
        char c;
        char c1 = 'a';
        char c2 = 15;

          //16bits -32768 ~ 32767
        short s;
        short s1 = 32767;
        short s2 = -32768;

          //32bits -2147483648 ~ -2147483647
        int i = 2147483647;
        int i2 = -2147483648;

          //64bits -9223372036854775808 ~ 9223372036854775807
          //tem que colocar L ou l no final do numero
        long l = 9223372036854775807L;
        long l2 = -9223372036854775808l;

        //flutuantes

          //32bits 1.4E-45 ~ 3.4028235E+38
          //tem que colocar f no final
        float f = 65f;
        float f2 = 65.0f;
        float f3 = -0.5f;

          //64bits 1.7976E+308 ~ 4.9E-324
          //precisa colocar .0 se for inteiro
        double d = 1024.99;
        double d2 = 10.2456;

        //booleano

        boolean bo = true;
        boolean bo2 = false;
          //errado
        //boolean bo3 = "false";
        //boolean bo4 = 'true';

        //void v; //palavra reservada

        //System.out.println("byte : " + b);
          //nao e possivel usar uma variavel nao inicializada

    }
}
