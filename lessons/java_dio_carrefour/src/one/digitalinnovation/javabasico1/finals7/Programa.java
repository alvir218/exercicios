package one.digitalinnovation.javabasico1.finals7;

public class Programa {
    public static void main(String[] args) {

        final HardcoreGamer hardcoreGamer = new HardcoreGamer();

        final Gamer gamer = new Gamer();

        final CasualGamer casualGamer = new CasualGamer();

        final var game = "pubg";

        //game = "wow";

        System.out.println(casualGamer.play(game));
    }
}
