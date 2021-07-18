package one.digitalinnovation.javabasico1.strings10;

public class ExercicioFinal {
    public static void main(String[] args) {
        System.out.println("a b c d e f g".toCharArray());
        System.out.println("aula de java".split(" "));
        System.out.println("aula".concat(" de java"));
          //aula de java
        System.out.println("1234 asda qw".replaceAll("[0-9]", "#"));
          //#### asda qw
    }
}
