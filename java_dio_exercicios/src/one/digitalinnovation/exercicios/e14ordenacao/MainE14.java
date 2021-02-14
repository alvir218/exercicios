package one.digitalinnovation.exercicios.e14ordenacao;

import one.digitalinnovation.exercicios.e1carro.Carro;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class MainE14 {
    public static void main(String[] args) {
        List<Carro> carros = new ArrayList<>();

        carros.add(new Carro("volkswagen", "gol", 1990));
        carros.add(new Carro("general motors", "corsa", 2000));
        carros.add(new Carro("ford", "fiesta", 2004));
        carros.add(new Carro("nissan", "march", 2018));
        carros.add(new Carro("hyunday","hb20",2018));

        System.out.println("ordem de insercao:\n" + carros);

        /*
        Collections.sort(carros, new CarrosComparator());
        System.out.println("\nordenando por comparator");
        */

        /*
        Collections.sort(carros);
        System.out.println("\nordenado por interface comparable");
        */

        /*carros.sort((carro1, carro2) -> carro1.getModelo().compareTo(carro2.getModelo()));
        System.out.println("ordenando por lambda crescente\n" + carros);

        carros.sort((carro1, carro2) -> carro2.getModelo().compareTo(carro1.getModelo()));
        System.out.println("ordenando por lambda decrescente\n" + carros);*/

        carros.sort(Comparator.comparing(carro -> carro.getMarca()));
        System.out.println("ordenado por method reference\n" + carros);

        carros.sort(Comparator.comparing(Carro::getModelo).reversed());
        System.out.println("ordenado por method reference reverso\n" + carros);

        //System.out.println(carros);



    }
}
