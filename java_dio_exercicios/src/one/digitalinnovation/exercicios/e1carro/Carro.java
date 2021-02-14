package one.digitalinnovation.exercicios.e1carro;

public class Carro implements Comparable<Carro>{
    private String marca;
    private String modelo;
    private Integer ano;
    private String variante;

    public Carro(String marca, String modelo, Integer ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }

    @Override
    public int compareTo(Carro carro){
        return this.getModelo().compareTo(carro.getModelo());
    }

    @Override
    public String toString(){
        return getMarca() + " - " + getModelo() + " - " + getAno().toString();
    }

    public String getMarca(){
        return this.marca;
    }

    public String getModelo(){
        return this.modelo;
    }

    public Integer getAno(){
        return this.ano;
    }

    public String getVariante(){
        return this.variante;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public void setAno(Integer ano){
        this.ano = ano;
    }

    public void setVariante(String variante){
        this.variante = variante;
    }
}