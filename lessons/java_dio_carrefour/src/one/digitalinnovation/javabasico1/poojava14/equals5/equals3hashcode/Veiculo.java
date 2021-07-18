package one.digitalinnovation.javabasico1.poojava14.equals5.equals3hashcode;

import java.util.Objects;

public abstract class Veiculo {

    private String modelo;
    private String marca;

    private double valorVenal;

    public Veiculo(String modelo, String marca, double valorVenal){
        this.modelo = modelo;
        this.marca = marca;
        this.valorVenal = valorVenal;
    }

    public String getModelo(){
        return modelo;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public String getMarca(){
        return marca;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public void acelera(){
        System.out.println("acelerando...");
    }

    public double getValorVenal(){
        return valorVenal;
    }

    public void setValorVenal(double valorVenal){
        this.valorVenal = valorVenal;
    }

      //metodo que sera sobrescrito
      //na id aparece um icone com flecha para baixo
      //na sobrescrita a flecha esta para cima
    public double calculaImposto(){
        return this.valorVenal * 0.01;
    }

    @Override
    public int hashCode(){
        return Objects.hash(modelo, marca, valorVenal);
    }

    @Override
    public boolean equals(Object obj){
        if(obj == null){
            return false;
        }

        Veiculo comparavel;
        if(obj instanceof Veiculo){
            comparavel = (Veiculo)obj;
        } else{
            return false;
        }

        if(this.hashCode() == obj.hashCode()){
            return true;
        }

        return false;
    }
}
