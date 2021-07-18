package one.digitalinnovation.javabasico1.datas15.javaDate1;

import java.time.Instant;
import java.util.Date;

public class JavaDate5 {
    public static void main(String[] args) {

        Date dataInicio = new Date(1613096442762L);
        System.out.println(dataInicio);
          //Thu Feb 11 23:20:42 BRT 2021

        Instant instant = dataInicio.toInstant();
        System.out.println(instant);
          //2021-02-12T02:20:42.762Z
    }
}
