package one.digitalinnovation.collections2.comparadores5;

import java.util.Comparator;

public class EstudanteOrdemReversaComparator implements Comparator<Estudante> {

    @Override
    public int compare(Estudante o1, Estudante o2){
        return o2.getIdade() - o1.getIdade();
    }
}
