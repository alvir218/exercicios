package com.gft.atividade2;

public class VideoGame extends Produto implements Imposto{

    private String marca;
    private String modelo;
    private Boolean isUsado;

    VideoGame(){}

    VideoGame(String nome, Double preco, Integer qtd, String marca, String modelo, Boolean isUsado){
        this.setNome(nome);
        this.setPreco(preco);
        this.setQtd(qtd);
        this.marca = marca;
        this.modelo = modelo;
        this.isUsado = isUsado;
    }

    public String getNome(){
        return super.getNome();
    }

    public Double getPreco(){
        return super.getPreco();
    }

    public Integer getQtd(){
        return super.getQtd();
    }

    public String getMarca(){
        return this.marca;
    }

    public String getModelo(){
        return this.modelo;
    }

    public Boolean getIsUsado(){
        return this.isUsado;
    }

    public void setNome(String nome){
        super.setNome(nome);
    }
    public void setPreco(Double preco){
        super.setPreco(preco);
    }
    public void setQtd(Integer qtd){
        super.setQtd(qtd);
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    @Override
    public Double calculaImposto(){
        if(this.isUsado == true){
            return this.getPreco() * (25.0 / 100.0);
        }else{
            return this.getPreco() * (45.0 / 100.0);
        }

    }
}
