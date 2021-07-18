package one.digitalinnovation.javabasico1.datas15.datajava8plus4;

import java.time.LocalDateTime;

public class LocalDateTime2 {
    public static void main(String[] args) {

        LocalDateTime agora = LocalDateTime.now();
        System.out.println(agora);
          //2021-02-12T01:41:16.225745600

        LocalDateTime futuro = agora.plusHours(1).plusDays(2).plusSeconds(12);
        System.out.println(futuro);
          //2021-02-14T02:41:28.225745600
    }
}
