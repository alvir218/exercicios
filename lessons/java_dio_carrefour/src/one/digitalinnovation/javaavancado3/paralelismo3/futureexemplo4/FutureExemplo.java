package one.digitalinnovation.javaavancado3.paralelismo3.futureexemplo4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;
import java.util.stream.Collectors;

public class FutureExemplo {
    private static final ExecutorService pessoasParaExecutarAtividade = Executors.newFixedThreadPool(3);

    public static void main(String[] args) throws InterruptedException{
        Casa casa = new Casa(new Quarto());

        /*casa.obterAfazeresDaCasa().forEach(atividade ->
                threadPool.execute(() ->
                        atividade.realizar()));*/
        //exemplo1

        /*casa.obterAfazeresDaCasa().forEach(atividade ->
                threadPool.submit(() ->
                        atividade.realizar()));*/
        //tambem valido

        List<Future<String>> futuros =
        new CopyOnWriteArrayList<Future<String>>(casa.obterAfazeresDaCasa().stream()
                .map(atividade -> pessoasParaExecutarAtividade.submit(() -> {
                            return atividade.realizar();
                }))
                .collect(Collectors.toList()));


        while(true){
            int numeroDeAtividadesNaoFinalizadas = 0;
            for(Future<?> futuro : futuros){
                if(futuro.isDone()){
                    try{
                        System.out.println("parabens voce terminou de " + futuro.get());
                        futuros.remove(futuro);
                    } catch(InterruptedException e){
                        e.printStackTrace();
                    } catch (ExecutionException e) {
                        e.printStackTrace();
                    }
                } else{
                    numeroDeAtividadesNaoFinalizadas++;
                }
            }
            if(futuros.stream().allMatch(Future::isDone)){
                break;
            }

            System.out.println("numero de atividades nao finalizadas: " + numeroDeAtividadesNaoFinalizadas);
            Thread.sleep(500);
        }

        pessoasParaExecutarAtividade.shutdown();

    }
}

class Casa{
    private List<Comodo> comodos;

    Casa(Comodo... comodos){
        this.comodos = Arrays.asList(comodos);
    }

    List<Atividade> obterAfazeresDaCasa(){
        return this.comodos.stream().map(Comodo::obterAfazeresDoComodo)
                .reduce(new ArrayList<Atividade>(), (pivo, atividades) ->{
                    pivo.addAll(atividades);
                    return pivo;
                });
    }
}

interface Atividade{
    String realizar();
}

abstract class Comodo{
    abstract List<Atividade> obterAfazeresDoComodo();
}

class Quarto extends Comodo{
    @Override
    List<Atividade> obterAfazeresDoComodo(){

        /*ArrayList<Atividade> objects = new ArrayList<>();
        objects.add(this::arrumarACama);
        objects.add(this::varrerOQuarto);
        objects.add(this::arrumarGuardaRoupa);*/
        //tambem valido

        /*ArrayList<Atividade> objects = new ArrayList<>();
        objects.add(() -> this.arrumarACama());
        objects.add(() -> this.varrerOQuarto());
        objects.add(() -> this.arrumarGuardaRoupa());*/
        //tambem valido

        /*return Arrays.asList(
                () -> this.arrumarACama(),
                () -> this.varrerOQuarto(),
                () -> this.arrumarGuardaRoupa()
        );*/
        //tambem valido

        return Arrays.asList(
              this::arrumarACama,
              this::varrerOQuarto,
              this::arrumarGuardaRoupa
      );
    }

    private String arrumarGuardaRoupa(){
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
            }
        return "arrumar o guarda roupa\n";
    }

    private String varrerOQuarto(){ try {
        Thread.sleep(7000);
    } catch (InterruptedException e) {
        e.printStackTrace();
        }
        return "varrer o quarto\n";
    }

    private String arrumarACama(){
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
            }
        return "arrumar a cama\n";
    }
}