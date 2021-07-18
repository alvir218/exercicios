package one.digitalinnovation.javabasico1.datas15.javaDate1;

import java.util.Date;

public class JavaDate4 {
    public static void main(String[] args) {

        Date dataNoPassado = new Date(1513096442762l);
        //Tue Dec 12 14:34:02 BRST 2017

        Date dataNoFuturo = new Date(1713096442762l);
        Date mesmaDataNoFuturo = new Date(1713096442762l);
        //Sun Apr 14 09:07:22 BRT 2024

        boolean isEquals = dataNoFuturo.equals(mesmaDataNoFuturo);
        System.out.println(isEquals);

        int compareCase1 = dataNoPassado.compareTo(dataNoFuturo);
        System.out.println(compareCase1);
          //passado -> futuro
          //-1

        int compareCase2 = dataNoFuturo.compareTo(dataNoPassado);
        System.out.println(compareCase2);
          //futuro -> passado
          //1

        int compareCase3 = dataNoFuturo.compareTo(mesmaDataNoFuturo);
        System.out.println(compareCase3);
          //datas equivalentes
          //0
    }
}
