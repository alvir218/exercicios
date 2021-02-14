package one.digitalinnovation.exercicios.e2carropessoas;

public class Carro {
    private String marca;
    private String modelo;
    private Integer ano;
    private String variante;
    private Integer pessoas;

    public Carro(String marca, String modelo, Integer ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }

    public Integer adicionarPessoas(Integer quantasPessoas){
        return this.pessoas = this.pessoas + quantasPessoas;
    }

    public Integer removerPessoas(Integer quantasPessoas){
        this.pessoas = this.pessoas - quantasPessoas;

        if(this.pessoas < 0){
            this.pessoas = 0;
        }
        return this.pessoas;
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

    public Integer getPessoas(Integer pessoas){ return this.pessoas; }

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

    public void setPessoas(Integer pessoas){ this.pessoas = pessoas; }
}