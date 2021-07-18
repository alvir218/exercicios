package one.digitalinnovation.javabasico1.poojava14.instancia1;

public class Pessoa {

      //caso nao informe um nome na construcao do objeto
      //esse sera iniciado com marco
    private String nome = "marco";

      //construtor vazio opcional quando so existe esse
    public Pessoa(){

    }

      //pode ter mais de um construtor
    public Pessoa(String nome){
        this.nome = nome;
    }

      //para nao expor o dado usa-se get set como boas praticas
    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

      //metodos, quantos forem necessarios
    public String falarMeuProprioNome(){
        return "ola, meu nome e " + getNome();
    }

}
