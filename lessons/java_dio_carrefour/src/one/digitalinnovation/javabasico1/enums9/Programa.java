package one.digitalinnovation.javabasico1.enums9;

public class Programa {
    public static void main(String[] args) {

        //final TipoVeiculo tipoVeiculo = new TipoVeiculo();
          //Enum types cannot be instantiated

        System.out.println(TipoVeiculo.TERRESTRE);
          //TERRESTRE
        System.out.println(TipoVeiculo.AQUATICO);
          //AQUATICO

        //System.out.println(TipoVeiculo.valueOf("aereo"));
        System.out.println(TipoVeiculo.valueOf("AEREO"));
          //AEREO

        for(TipoVeiculo tipo : TipoVeiculo.values()){
            System.out.println("tipo: " + tipo);
        }
        /*tipo: TERRESTRE
        tipo: AQUATICO
        tipo: AEREO*/

        System.out.println("codigo do status CLOSE: " + Status.CLOSE.getCod());
          //codigo do status CLOSE: 2

        System.out.println("texto do status OPEN: " + Status.OPEN.getTexto());
          //texto do status OPEN: aberto
    }
}
