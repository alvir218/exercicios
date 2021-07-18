package one.digitalinnovation.javaavancado3.java10novidades5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.stream.Collectors;

public class InferenciaExemplo1 {
    public static void main(String[] args) throws IOException {
        URL url = new URL("https://docs.oracle.com/javase/10/language/");
        URLConnection urlConnection = url.openConnection();
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));

        System.out.println(bufferedReader.lines().collect(Collectors.joining()).replaceAll(">", "<\n"));

    }

    public static void completarNome(String nome, String sobrenome){
        var nomeCompleto = String.format("%s %s", nome, sobrenome);
        System.out.println(nomeCompleto);
    }

    public static int printarSoma(int a, int b){
        var soma = a + b;
        return soma;
    }
}
