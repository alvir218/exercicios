//altera a classe barra de carregamento de extend thread para implements runnable

package one.digitalinnovation.javaavancado3.paralelismo3.runnableexemplo2;

public class RunnableExemplo2 {
    public static void main(String[] args) {

        Thread thread = new Thread(new BarraDeCarregamento2());
        Thread thread2 = new Thread(new BarraDeCarregamento3());

        thread.start();
        thread2.start();
        System.out.println("nome da thread: " +thread.getName());
        System.out.println("nome da thread2: " +thread2.getName());
//        nome da thread: Thread-0
//        nome da thread2: Thread-1
//        rodei barra de carregamento 3:
//        rodei barra de carregamento 2:

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

class BarraDeCarregamento2 implements Runnable{
    @Override
    public void run(){

        try {
            Thread.sleep(3000);
            System.out.println("rodei barra de carregamento 2: ");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }


    }
}

class BarraDeCarregamento3 implements Runnable{
    @Override
    public void run(){

        try {
            Thread.sleep(1000);
            System.out.println("rodei barra de carregamento 3: ");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}