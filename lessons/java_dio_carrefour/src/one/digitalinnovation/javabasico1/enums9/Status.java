package one.digitalinnovation.javabasico1.enums9;

public enum Status {

    OPEN(13, "aberto"),
    CLOSE(02, "fechado");

    private int cod;
    private String texto;

    Status(final int cod, final String texto){

        this.cod = cod;
        this.texto = texto;
    }

    public int getCod(){
        return cod;
    }

    public String getTexto(){
        return texto;
    }
}
