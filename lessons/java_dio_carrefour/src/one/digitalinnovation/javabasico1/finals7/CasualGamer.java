package one.digitalinnovation.javabasico1.finals7;

public class CasualGamer extends Gamer{

    @Override
    public String keyboard(){
        return "simple keyboard...\n";
    }

/*      //'mouse()' cannot override 'mouse()' in 'one.digitalinnovation.javabasico.finals7.Gamer'; overridden method is final
    @Override
    public String mouse(){
        return super.mouse();
    }*/

    public String play(final String game){
          //nao pode sobrescrever um atributo final
        //game = "wow";
        return "jogando " + game + "\n";
    }


}
