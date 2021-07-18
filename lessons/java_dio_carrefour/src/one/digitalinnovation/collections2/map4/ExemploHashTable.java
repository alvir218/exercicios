package one.digitalinnovation.collections2.map4;

import java.util.Hashtable;
import java.util.Map;

public class ExemploHashTable {
    public static void main(String[] args) {

        Hashtable<String, Integer> estudantes = new Hashtable<>();

        estudantes.put("carlos", 21);
        estudantes.put("mariana", 33);
        estudantes.put("rafaela", 18);
        estudantes.put("pedro", 44);
        System.out.println(estudantes);
        //{carlos=21, pedro=44, mariana=33, rafaela=18}

        estudantes.put("pedro", 55);
        System.out.println(estudantes);
        //{carlos=21, pedro=55, mariana=33, rafaela=18}

        //remove um estudante no indice 0
        estudantes.remove("pedro");
        System.out.println(estudantes);
        //{carlos=21, mariana=33, rafaela=18}


        int idadeEstudante = estudantes.get("mariana");
        System.out.println(idadeEstudante);
        //33

        System.out.println(estudantes.size());
        //3

        //varredura
        for(Map.Entry<String, Integer> entry : estudantes.entrySet()){
            System.out.println("for1: " +
                    entry.getKey() +
                    " - " +
                    entry.getValue());
        }

        //navega nos registros do mapa
        for(String key : estudantes.keySet()){
            System.out.println("for2: " +
                    key +
                    " - " +
                    estudantes.get(key));
        }
        /*for2: carlos - 21
        for2: mariana - 33
        for2: rafaela - 18*/

        System.out.println(estudantes);
        //{carlos=21, mariana=33, rafaela=18}
    }
}
