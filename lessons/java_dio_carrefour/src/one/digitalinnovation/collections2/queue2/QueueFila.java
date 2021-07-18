package one.digitalinnovation.collections2.queue2;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class QueueFila {
    public static void main(String[] args) {

        Queue<String> filaBanco = new LinkedList<>();

        filaBanco.add("patricia");
        filaBanco.add("roberto");
        filaBanco.add("flavio");
        filaBanco.add("pamela");
        filaBanco.add("anderson");

        System.out.println(filaBanco);
        //[patricia, roberto, flavio, pamela, anderson]

        String clienteASerAtendido = filaBanco.poll();
        System.out.println(clienteASerAtendido);
        //patricia
        System.out.println(filaBanco);
        //[roberto, flavio, pamela, anderson]

        String primeiroCliente = filaBanco.peek();
        System.out.println(primeiroCliente);
        //roberto
        System.out.println(filaBanco);
        //[roberto, flavio, pamela, anderson]

        String primeiroClienteOuErro = filaBanco.element();
        System.out.println(primeiroClienteOuErro);
        //roberto
        System.out.println(filaBanco);
        //[roberto, flavio, pamela, anderson]

        //varredura na fila
        Iterator<String> iteratorFilaBanco = filaBanco.iterator();
        while(iteratorFilaBanco.hasNext()){
            System.out.println("iterator: " + iteratorFilaBanco.next());
        }

        System.out.println(filaBanco.size());

        System.out.println(filaBanco.isEmpty());

        filaBanco.add("wesley");

        System.out.println(filaBanco);
        //wesley e o ultimo

    }
}
