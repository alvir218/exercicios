package one.digitalinnovation.exercicios.e14ordenacao;

import one.digitalinnovation.exercicios.e1carro.Carro;

import java.util.Comparator;

public class CarrosComparator implements Comparator<Carro> {

    @Override
    public int compare(Carro carro1, Carro carro2){
        return carro1.getModelo().compareTo(carro2.getModelo());
    }
}
