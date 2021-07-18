package one.digitalinnovation.javabasico1.datas15.javaDateFormat3;

import java.text.DateFormat;
import java.util.Date;

public class JavaDateFormat {
    public static void main(String[] args) {

        Date agora = new Date();

        String dateToString = DateFormat.getDateInstance().format(agora);
        System.out.println(dateToString);
          //12 de fev. de 2021

        dateToString = DateFormat.getDateTimeInstance(DateFormat.LONG, DateFormat.SHORT).format(agora);
        System.out.println(dateToString);
          //12 de fevereiro de 2021 01:22

        dateToString = DateFormat.getDateTimeInstance(DateFormat.LONG, DateFormat.LONG).format(agora);
        System.out.println(dateToString);
          //12 de fevereiro de 2021 01:22:40 BRT

    }
}
