package one.digitalinnovation.exercicios.e4aniversario;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Date;

public class MainE4 {
    public static void main(String[] args) {

        //nascimento
        LocalDateTime nascimento = LocalDateTime.of(1990,6,14,1,2);
        Long nascimentoMillis = nascimento.atZone(ZoneId.systemDefault()).toInstant().toEpochMilli();
        Date nascimentoDate = new Date(nascimentoMillis);
        System.out.println("nascimento");
        System.out.println("nascimento local date time\n" + nascimento);
        //1990-06-14T01:02
        System.out.println("nascimento millis\n" + nascimentoMillis);
        //645336120000
        System.out.println("nascimento date\n" + nascimentoDate);
        //Thu Jun 14 01:02:00 BRT 1990

        //15 de maio de 2010
        LocalDateTime arbitraria = LocalDateTime.of(2010,5,15,1,1);
        Long arbitrariaMillis = arbitraria.atZone(ZoneId.systemDefault()).toInstant().toEpochMilli();
        Date arbitrariaDate = new Date(arbitrariaMillis);
        System.out.println("\narbitraria");
        System.out.println("arbitraria local date time\n" + arbitraria);
        //2010-05-15T01:01
        System.out.println("arbitraria millis\n" + arbitrariaMillis);
        //1273896060000
        System.out.println("arbitraria date\n" + arbitrariaDate);
        //Sat May 15 01:01:00 BRT 2010

        Boolean anteriorAoNascimento = nascimentoDate.before(arbitrariaDate);
        System.out.println("o nascimento e anterior a 15 de maio de 2010? " + anteriorAoNascimento);
        //true

        Boolean posteriorAoNascimento = nascimentoDate.after(arbitrariaDate);
        System.out.printf("o nascimento e posterior a 15 de maio de 2010? " + posteriorAoNascimento);
        //false

    }
}
