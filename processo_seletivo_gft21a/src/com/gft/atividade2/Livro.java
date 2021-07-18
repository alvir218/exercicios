package com.gft.atividade2;

public class Livro extends Produto implements Imposto{

    private String autor;
    private String tema;
    private Integer qtdPag;

    Livro(){}

    Livro(String nome, Double preco, Integer qtd, String autor, String tema, Integer qtdPag){
        this.setNome(nome);
        this.setPreco(preco);
        this.setQtd(qtd);
        this.autor = autor;
        this.tema = tema;
        this.qtdPag = qtdPag;

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

    public String getAutor(){
        return this.autor;
    }

    public String getTema(){
        return this.tema;
    }

    public Integer getQtdPag(){
        return qtdPag;
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

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void setTema(String tema){
        this.tema = tema;
    }

    public void setQtdPag(Integer qtdPag){
        this.qtdPag = qtdPag;
    }

    @Override
    public Double calculaImposto(){
        if(this.tema == "educativo"){
            return 0.0;
        }else{
            return this.getPreco() * (10.0 / 100.0);
        }

    }

}
