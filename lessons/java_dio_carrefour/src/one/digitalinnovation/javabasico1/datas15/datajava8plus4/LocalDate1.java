package one.digitalinnovation.javabasico1.datas15.datajava8plus4;

import java.time.LocalDate;
import java.time.LocalTime;

public class LocalDate1 {
    public static void main(String[] args) {

        LocalDate hoje = LocalDate.now();
        System.out.println(hoje);
          //2021-02-12

        LocalDate ontem = hoje.minusDays(1);
        System.out.println(ontem);
          //2021-02-11

        LocalTime agora = LocalTime.now();
        System.out.println(agora);
          //01:35:02.545512

        LocalTime maisUmaHora = agora.plusHours(1);
        System.out.println(maisUmaHora);
          //02:36:54.029469500

    }
}
