package one.digitalinnovation.javabasico1.datas15.javaCalendar2;

import java.util.Calendar;

public class JavaCalendar1 {
    public static void main(String[] args) {

        Calendar agora = Calendar.getInstance();

        System.out.println(agora);
          //java.util.GregorianCalendar[time=1613097838784,areFieldsSet=true,areAllFieldsSet=true,lenient=true,zone=sun.util.calendar.ZoneInfo[id="America/Sao_Paulo",offset=-10800000,dstSavings=0,useDaylight=false,transitions=93,lastRule=null],firstDayOfWeek=1,minimalDaysInFirstWeek=1,ERA=1,YEAR=2021,MONTH=1,WEEK_OF_YEAR=7,WEEK_OF_MONTH=2,DAY_OF_MONTH=11,DAY_OF_YEAR=42,DAY_OF_WEEK=5,DAY_OF_WEEK_IN_MONTH=2,AM_PM=1,HOUR=11,HOUR_OF_DAY=23,MINUTE=43,SECOND=58,MILLISECOND=784,ZONE_OFFSET=-10800000,DST_OFFSET=0]

        System.out.println("a data corrente e: " + agora.getTime());
          //a data corrente e: Thu Feb 11 23:41:57 BRT 2021

        agora.add(Calendar.DATE, -15);
        System.out.println("15 dias atras: " + agora.getTime());
          //15 dias atras: Wed Jan 27 23:41:57 BRT 2021

        agora.add(Calendar.MONTH, 4);
        System.out.println("4 meses depois: " + agora.getTime());
          //4 meses depois: Thu May 27 23:41:57 BRT 2021

        agora.add(Calendar.YEAR, 2);
        System.out.println("2 anos depois: " + agora.getTime());
          //2 anos depois: Sat May 27 23:41:57 BRT 2023


    }
}
