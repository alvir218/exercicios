package one.digitalinnovation.exercicios.e7momentoarbitrario;

import java.time.LocalDateTime;

public class MainE7 {
    public static void main(String[] args) {
        LocalDateTime momento = LocalDateTime.of(2010,05,15,10,0,0);
        System.out.println(momento);
        //2010-05-15T10:00

        momento = momento.plusYears(4).plusMonths(6).plusHours(13);
        System.out.println(momento);
        //2010-05-15T10:00
    }
}
