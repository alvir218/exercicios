package one.digitalinnovation.javabasico1.poojava14.super4;

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
}
