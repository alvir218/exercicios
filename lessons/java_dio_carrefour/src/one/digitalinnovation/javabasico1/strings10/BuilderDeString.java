package one.digitalinnovation.javabasico1.strings10;

public class BuilderDeString {
    public static void main(String[] args) {

        var nome = "andre";

        final var builder = new StringBuilder(nome);
        System.out.println(builder.append("luis"));
          //andreluis

        final var reverse = builder.reverse();
        System.out.println(reverse);
          //siulerdna

        final var insert = reverse.insert(0, "#").insert(reverse.length(), "#");
        System.out.println(insert);
          //#siulerdna#
    }
}
