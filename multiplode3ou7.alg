algoritmo "multiplode3eou7"

// Data : 4/13/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Em  pseudoc�digo,  fa�a  um  algoritmo e  um  fluxograma que  verifique  se  um n�mero inteiro digitado � m�ltiplo de 3, ou m�ltiplo 7. Apresente uma mensagem mostrando o n�mero digitado e o resultado do teste.



var
   numero:inteiro
inicio
// Se��o de Comandos 
   escreval("determine se um numero inteiro qualquer e multiplo de 3 ou 7")
   escreval
   escreval
   escreval("digite um numero inteiro:")
   leia(numero)
   se ( (numero mod 3=0) e (numero mod 7=0) ) entao
      escreval("o numero e multiplo de 3 e de 7")
   senao
      se ((numero mod 3=0)) entao
         escreval("o numero e multiplo de 3")
      senao
         se ((numero mod 7=0)) entao
            escreval("o numero � multiplo de 7")
         senao
            escreval("o numero nao e multiplo de 3 nem de 7")
         fimse
      fimse
   fimse
fimalgoritmo
