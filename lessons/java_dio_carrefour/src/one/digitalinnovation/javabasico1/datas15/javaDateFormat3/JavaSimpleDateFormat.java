package one.digitalinnovation.javabasico1.datas15.javaDateFormat3;

import java.text.SimpleDateFormat;
import java.util.Date;

public class JavaSimpleDateFormat {
    public static void main(String[] args) {

        Date agora = new Date();

        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

        String dataFormatada = formatter.format(agora);

        System.out.println(dataFormatada);
          //12/02/2021
    }
}
