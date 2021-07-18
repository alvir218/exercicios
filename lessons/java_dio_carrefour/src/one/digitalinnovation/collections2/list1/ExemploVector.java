package one.digitalinnovation.collections2.list1;

import java.util.List;
import java.util.Vector;

public class ExemploVector {
    public static void main(String[] args) {

        List<String> esportes = new Vector<>();

        //adiciona itens
        esportes.add("futebol");
        esportes.add("basquetebol");
        esportes.add("tenis de mesa");
        esportes.add("handebol");
        System.out.println(esportes);
        //[futebol, basquetebol, tenis de mesa, handebol]

        //altera o valor da posicao 2 no vetor
        esportes.set(2, "ping pong");
        System.out.println(esportes);
        //[futebol, basquetebol, ping pong, handebol]

        //remocao por index ou valor
        esportes.remove(2);
        esportes.remove("handebol");
        System.out.println(esportes);
        //[futebol, basquetebol]

        //retorna o primeiro do vetor
        System.out.println(esportes.get(0));
        //futebol

        //varredura
        for(String esporte : esportes){
            System.out.println(esporte);
        }
        /*futebol
        basquetebol
        */

    }
}
