package one.digitalinnovation.javaavancado3.paralelismo3.threadexemplo1;

public class ThreadExemplo1 {
    public static void main(String[] args) {

        BarraDeCarregamento2 barraDeCarregamento2a = new BarraDeCarregamento2();
        //BarraDeCarregamento2 barraDeCarregamento2b = new BarraDeCarregamento2();
        BarraDeCarregamento3 barraDeCarregamento3 = new BarraDeCarregamento3();

        barraDeCarregamento2a.start();
        barraDeCarregamento3.start();
        barraDeCarregamento2a.run();
        barraDeCarregamento3.run();
//        rodei barra de carregamento 3: Thread-1
//        rodei barra de carregamento 2: Thread-0
//        rodei barra de carregamento 2: Thread-0
//        rodei barra de carregamento 3: Thread-1
        //usar start para modo assincrono

    }
}


class GerarPdf implements Runnable{
    @Override
    public void run(){
        System.out.println("gerar pdf");
    }
}

class BarraDeCarregamento implements Runnable{
    @Override
    public void run(){
        System.out.println("loading...");
    }
}

class BarraDeCarregamento2 extends Thread{
    @Override
    public void run(){
        super.run();

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("rodei barra de carregamento 2: " + this.getName());
    }
}

class BarraDeCarregamento3 extends Thread{
    @Override
    public void run(){
        super.run();

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("rodei barra de carregamento 3: " + this.getName());
    }
}