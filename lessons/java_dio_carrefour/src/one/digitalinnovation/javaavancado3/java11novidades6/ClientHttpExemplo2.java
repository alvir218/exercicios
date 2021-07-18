package one.digitalinnovation.javaavancado3.java11novidades6;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class ClientHttpExemplo2 {
    public static void main(String[] args) throws IOException, InterruptedException {
        connectAndPrintUrlJavaOracle();
    }

    private static void connectAndPrintUrlJavaOracle() throws IOException, InterruptedException {
        HttpRequest request = HttpRequest.newBuilder()
                .GET().uri(URI.create("https://docs.oracle.com/javase/10/language/"))
                .build();

        HttpClient httpClient = HttpClient.newHttpClient();

        HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());

        System.out.println("status code: " + response.statusCode());
        System.out.println("headers response: " + response.headers());
        System.out.println(response.body());

    }
}
