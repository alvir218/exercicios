package one.digitalinnovation.javabasico1.classes0.tipos3.wrappers2;

public class Wrappers {
    public static void main(String[] args) {
        //autoboxing

        Byte b = 127;
        Byte b2 = -128;
        Byte nullByte = null;

          //char
        Character c = 'A';
        Character c2 = 15;

        Short s = 32767;
        Short s2 = -32768;

          //int
        Integer i = 2147483647;
        Integer i2 = -2147483648;

        Long l = 9223372036854775807L;
        Long l2 = -9223372036854775808l;

        Float f = 65f;
        Float f2 = 65.0f;
        Float f3 = -0.5f;

        Double d = 1024.99;
        Double d2 = 10.2456;

        Boolean bo = true;
        Boolean bo2 = false;
        Boolean bo3 = Boolean.getBoolean("false");
        Boolean bo4 = Boolean.valueOf("true");

    }
}
