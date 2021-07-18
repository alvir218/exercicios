package one.digitalinnovation.javaavancado3.java11novidades6;

import java.io.IOException;
import java.net.ProxySelector;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class ClientHttpExemplo3 {

    static ExecutorService executor = Executors.newFixedThreadPool(6, new ThreadFactory() {
        @Override
        public Thread newThread(Runnable runnable) {
            Thread thread = new Thread(runnable);
            System.out.println("nova thread criada: " + (thread.isDaemon() ? "daemon" : "") + "thread group: " + thread.getThreadGroup());
            return thread;
        }
    });

    public static void main(String[] args) throws IOException, InterruptedException {
        //connectAndPrintUrlJavaOracle();
        connectAkamaiHttp1Client();
    }

    private static void connectAkamaiHttp1Client(){
        System.out.println("running http/1.1 example...");
        try{
            HttpClient httpClient = HttpClient.newBuilder()
                    .version(HttpClient.Version.HTTP_1_1)
                    .proxy(ProxySelector.getDefault())
                    .build();

            long start = System.currentTimeMillis();

            HttpRequest mainRequest = HttpRequest.newBuilder()
                    .uri(URI.create("https://http2.akamai.com/demo/h2_demo_frame.html"))
                    .build();

            HttpResponse<String> response = httpClient.send(mainRequest, HttpResponse.BodyHandlers.ofString());

            System.out.println("status code: " + response.statusCode());
            System.out.println("response headers: " + response.headers());
            String responseBody = response.body();
            System.out.println(responseBody);

            List<Future<?>> future = new ArrayList<>();

            responseBody
                    .lines()
                    .filter(line -> line.trim().startsWith("<img height"))
                    .map(line -> line.substring(line.indexOf("src='") + 5, line.indexOf("'/>")))
                    //.forEach(image -> System.out.println(image));
                    .forEach(image -> {
                        Future<?> imgFuture = executor.submit(() ->{
                            HttpRequest imgRequest = HttpRequest.newBuilder()
                                    .uri(URI.create("https://http2.akamai.com" + image))
                                    .build();

                            try {
                                HttpResponse<String> imageResponse = httpClient.send(imgRequest, HttpResponse.BodyHandlers.ofString());
                                System.out.println("imagem carregada: " + image + ", status code: " + imageResponse.statusCode());
                            } catch (IOException | InterruptedException e) {
                                System.out.println("erro durante requisicao para recuperar a imagem" + image);

                            }
                        });

                        future.add(imgFuture);
                        System.out.println("imagens futuras submitidas: " + image);

                    });

            future.forEach(f -> {
                try {
                    f.get();
                } catch (InterruptedException | ExecutionException e) {
                    System.out.println("erro ao esperar carregar imagem do futuro");
                }
            });

            long end = System.currentTimeMillis();
            System.out.println("tempo de carregamento total: " + (end - start) + " ms");

        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }
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
