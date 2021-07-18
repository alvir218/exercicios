package com.gft.atividade2;

public abstract class Produto {
    private String nome;
    private Double preco;
    private Integer qtd;

    public Produto(){}

    public Produto(String nome, Double preco, Integer qtd){
        this.nome = nome;
        this.preco = preco;
        this.qtd = qtd;
    }

    public String getNome(){
        return nome;
    }

    public Double getPreco(){
        return preco;
    }

    public Integer getQtd(){
        return qtd;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    public void setPreco(Double preco){
        this.preco = preco;
    }
    public void setQtd(Integer qtd){
        this.qtd = qtd;
    }
}
