//altera a classe barra de carregamento de extend thread para implements runnable

package one.digitalinnovation.javaavancado3.paralelismo3.threadexemplo3;

public class ThreadExemplo3 {
    public static void main(String[] args) {

        GeradorDePdf iniciarGeradorDePdf = new GeradorDePdf();
        BarraDeCarregamento iniciarBarraDeCarregamento = new BarraDeCarregamento(iniciarGeradorDePdf);

        iniciarGeradorDePdf.start();
        iniciarBarraDeCarregamento.start();

    }
}


class GeradorDePdf extends Thread{
    @Override
    public void run(){
        try {
            System.out.println("o gerador de pdf foi iniciado");
            Thread.sleep(5000);

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("pdf gerado");
    }
}

class BarraDeCarregamento extends Thread{
    private Thread iniciarGeradorDePdf;

    public BarraDeCarregamento(Thread iniciarGeradorDePdf){
        this.iniciarGeradorDePdf = iniciarGeradorDePdf;
    }

    @Override
    public void run(){

        //while(iniciarGeradorDePdf.isAlive())
        //nao e bom se tiver parado gera falso positivo
        while(true){
            try {
                Thread.sleep(600);

                if(!iniciarGeradorDePdf.isAlive()){
                    break;
                }

                System.out.println("loading...");

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }


    }
}