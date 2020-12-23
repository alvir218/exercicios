/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
calcula a media e determina se foi aprovado, ficou em exame, foi reprovado
*/



//codigo continuado do leonardo
//adicionado reprovaçao por faltas

#include <iostream>

using namespace std;

class Nota
{  
    float nota1, nota2;
    int faltas;

  public:
    Nota(float n1, float n2, int faltas)
    {
        nota1 = 0;
        nota2 = 0;
        faltas = 0;
        setNota1(n1);
        setNota2(n2);
        setFaltas(faltas);
    }

    void setNota1(float n)
    {
        if (n > 10 || n < 0)
            return;
        nota1 = n;
    }
    void setNota2(float n)
    {
        if (n > 10 || n < 0)
            return;
        nota2 = n;
    }
    void setFaltas(int f){
      if(faltas > 0 && faltas < 100){
        faltas = f;
      }
    }
    float getNota1()
    {
        return nota1;
    }
    float getNota2()
    {
        return nota2;
    }

    int getFaltas(){
      return faltas;
    }

    void resultado()
    {
        if(faltas > 7){
          cout<<"\nReprovado por " << faltas << "faltas" << endl;
        }else{

          float media = (nota1 + nota2) / 2;
          cout << "Media: " << media << endl;
          if (media < 4)
          {
              cout << "Reprovado por nota" << endl;
          }
          else if (media < 7)
          {
              cout << "Exame final" << endl;
              cout << "Para ser aprovado faltam: " << (10 - media) << endl;
          }
          else
          {
              cout << "Aprovado direto" << endl;
          }
        }
      }
};



int main(){

  Nota mario(8, 5.5, 5);

  mario.resultado();

  mario.setNota1(3);
  mario.resultado();

  mario.setNota1(10);
  mario.resultado();

  cout << "\n\n";
  system("pause");
  return 0;
}