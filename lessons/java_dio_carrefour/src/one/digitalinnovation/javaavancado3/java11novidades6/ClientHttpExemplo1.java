package one.digitalinnovation.javaavancado3.java11novidades6;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.stream.Collectors;

public class ClientHttpExemplo1 {
    public static void main(String[] args) {
        connectAndPrintUrlJavaOracle();
    }

    public static void connectAndPrintUrlJavaOracle(){
        try{
            URL url = new URL("https://docs.oracle.com/javase/10/language/");
            URLConnection urlConnection = url.openConnection();

            try{
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));{
                    System.out.println(bufferedReader.lines().collect(Collectors.joining()).replaceAll(">", "<\n"));

                }
            } catch(Exception e){
                e.printStackTrace();
            }
        } catch(Exception e){
            e.printStackTrace();
            }
    }
}
