package com.gft.atividade2;

import java.util.ArrayList;
import java.util.List;

public class Loja {
    private String nome;
    private String cnpj;
    private List<Livro> livros;
    private List<VideoGame> videoGames;

    Loja(){}
    Loja(String nome, List<Livro> livros, List<VideoGame> videogames){
        this.nome = nome;
        this.livros = new ArrayList<>();
        this.videoGames = new ArrayList<>();
    }

    public String getNome(){
        return this.nome;
    }

    public String getCnpj(){
        return cnpj;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCnpj(String cnpj){
        this.cnpj = cnpj;
    }

    public void listaLivros(){
        for(Livro livroAtual : this.livros){
            System.out.println("listando livros\n");
            System.out.println(livroAtual.getNome());

        }
    }

    public void listaVideoGames(){
        for(VideoGame videoGameAtual : this.videoGames){
            System.out.println("listando video games\n");
            System.out.println(videoGameAtual.getNome());

        }
    }

    public Double calculaPatrimonio(){
        Double patrimonio = 0.0;
        for(Livro livroAtual : this.livros){
            patrimonio = patrimonio + livroAtual.getPreco();
        }

        for(VideoGame videoGameAtual : this.videoGames){
            patrimonio = patrimonio + videoGameAtual.getPreco();
        }

        return patrimonio;
    }
}
