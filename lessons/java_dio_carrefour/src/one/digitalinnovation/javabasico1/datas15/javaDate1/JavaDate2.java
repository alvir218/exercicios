package one.digitalinnovation.javabasico1.datas15.javaDate1;

import java.util.Date;

public class JavaDate2 {
    public static void main(String[] args) {

        Long currentTimeMillis = System.currentTimeMillis();
        System.out.println(currentTimeMillis);
          //1613096442762

        Date novaData = new Date(currentTimeMillis);
        System.out.println(novaData);
          //Thu Feb 11 23:20:42 BRT 2021
    }
}
