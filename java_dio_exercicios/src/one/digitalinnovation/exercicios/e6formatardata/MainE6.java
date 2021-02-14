package one.digitalinnovation.exercicios.e6formatardata;

import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.util.Date;

public class MainE6 {
    public static void main(String[] args) {
        Date agora = new Date();
        SimpleDateFormat formatador = new SimpleDateFormat("dd/MM/YYYY HH:mm:ss:mmm");
        String dataFormatada = formatador.format(agora);
        System.out.println(dataFormatada);

    }
}
