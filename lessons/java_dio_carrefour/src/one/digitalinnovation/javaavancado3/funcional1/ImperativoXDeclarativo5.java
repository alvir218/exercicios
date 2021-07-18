package one.digitalinnovation.javaavancado3.funcional1;

import java.util.function.Function;

public class ImperativoXDeclarativo5 {
    public static void main(String[] args) {
        System.out.println(buscarUsuario(15));

        //com lambda
        Function<Integer, Object> buscarUsuario2 = idUsuario ->
        //busca o usuario
        new Object();
    }

    public static Object buscarUsuario(int idUsuario){
        //retorna usuario
        return new Object();
    }
}
