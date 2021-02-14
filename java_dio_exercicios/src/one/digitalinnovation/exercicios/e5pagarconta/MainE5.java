package one.digitalinnovation.exercicios.e5pagarconta;

import java.time.LocalDateTime;

public class MainE5 {
    public static void main(String[] args) {
        //sabado
        //LocalDateTime hoje = LocalDateTime.of(2021,2,3,1,2);
        //domingo
        //LocalDateTime hoje = LocalDateTime.of(2021,2,4,1,2);
        //agora
        LocalDateTime hoje = LocalDateTime.now();

        System.out.println(hoje);
        //2021-02-14T01:56:21.975692600

        LocalDateTime diaDoPagamento = hoje.plusDays(10);
        System.out.println(diaDoPagamento.getDayOfWeek());
        //2021-02-24T01:56:21.975692600

        if(diaDoPagamento.getDayOfWeek().getValue() == 6){
           diaDoPagamento = diaDoPagamento.plusDays(2);
        }else if(diaDoPagamento.getDayOfWeek().getValue() == 7){
           diaDoPagamento = diaDoPagamento.plusDays(1);
        }

        System.out.println("o vencimento da fatura e: \n" +
                diaDoPagamento.getDayOfWeek());
        //2021-02-24T01:56:21.975692600

    }
}
