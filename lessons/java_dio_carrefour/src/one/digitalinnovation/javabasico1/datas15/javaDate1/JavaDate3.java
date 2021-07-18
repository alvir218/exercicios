package one.digitalinnovation.javabasico1.datas15.javaDate1;

import java.util.Date;

public class JavaDate3 {
    public static void main(String[] args) {

        Date dataNoPassado = new Date(1513096442762l);
        System.out.println(dataNoPassado);
          //Tue Dec 12 14:34:02 BRST 2017

        Date dataNoFuturo = new Date(1713096442762l);
        System.out.println(dataNoFuturo);
          //Sun Apr 14 09:07:22 BRT 2024

          //compara se a data no passado e posterior a data no futuro
        boolean isAfter = dataNoPassado.after(dataNoFuturo);
        System.out.println(isAfter);
          //false

          //compara se a data no passado e anterior a data no futuro
        boolean isBefore = dataNoPassado.before(dataNoFuturo);
        System.out.println(isBefore);
          //true

    }
}
