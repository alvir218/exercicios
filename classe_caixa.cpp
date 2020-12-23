/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercício:
Crie uma classe chamada Caixa.
Essa class deve possuir atributos privados e encapsulados altura, largura e comprimento.
Deve possuir um método volume que retorne o volume
Sobrescrever o operador + para somar os três atributos
Crie também um construtor adequado para os 3 atributos.
*/



#include<iostream>

using namespace std;

class Caixa{
  private:
    float comprimento, largura, altura;

  public:
    float calcularVolume(float x, float y, float z){
      return x * y * z;
    }

    //construtor
    Caixa(float x, float y, float z){
      comprimento = 0;
      largura = 0;
      altura = 0;
      setComprimento(x);
      setLargura(y);
      setAltura(z);

    }
    
    //getters
    float getComprimento(){
      return comprimento;
    }

    float getLargura(){
      return largura;
    }

    float getAltura(){
      return altura;
    }

    //setters
    void setComprimento(float x){
      if(x > 0){
        comprimento = x;
      }
    }

    void setLargura(float y){
      if(y > 0){
        largura = y;
      }
    }

    void setAltura(float z){
      if(z > 0){
        altura = z;
      }
    }

    //overload operator
    Caixa operator+(const Caixa &algumaCaixa){
      //return Caixa(getComprimento() + algumaCaixa.altura, getLargura() + algumaCaixa.largura, getAltura() + algumaCaixa.altura);
      return Caixa(comprimento + algumaCaixa.comprimento, largura + algumaCaixa.largura, altura + algumaCaixa.altura);
    }

};

int main(){

  Caixa caixa1(3,4,5);
  Caixa caixa2(1,2,6);
  Caixa caixa3(7,7,7);

  caixa3 = caixa1 + caixa2;

  cout << "\n\nvolume da caixa com get: " 
    << caixa1.calcularVolume(
      caixa1.getComprimento(), 
      caixa1.getLargura(), 
      caixa1.getAltura()  ) 
  << endl;

  cout << "\n\nvolume da caixa com parametros: " << caixa1.calcularVolume(2,3,4) << endl;
  
  cout << "\n\nsoma das medidas com overload operator: "
    << "\ncomprimento: " << caixa3.getComprimento() 
    << "\nlargura: " << caixa3.getLargura()
    << "\naltura: " << caixa3.getAltura()
  << endl;  



  cout << "\n\n";
  system("pause");
  return 0;
}