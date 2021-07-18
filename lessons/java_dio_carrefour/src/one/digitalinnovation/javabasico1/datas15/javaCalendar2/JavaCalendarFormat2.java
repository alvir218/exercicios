package one.digitalinnovation.javabasico1.datas15.javaCalendar2;

import java.util.Calendar;

public class JavaCalendarFormat2 {
    public static void main(String[] args) {

        Calendar agora = Calendar.getInstance();

        System.out.printf("%tc\n", agora);
          //qui. fev. 11 23:49:31 BRT 2021

        System.out.printf("%tF\n", agora);
          //2021-02-11

        System.out.printf("%tD\n", agora);
          //02/11/21

        System.out.printf("%tr\n", agora);
          //11:49:31 PM

        System.out.printf("%tT\n", agora);
          //23:49:31
    }
}
