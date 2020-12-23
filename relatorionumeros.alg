algoritmo "relatorionumeros"

// Data : 4/25/2019
// Seção de Declarações
// estrutura de repeticao com relatorio sobre intervalo entre numeros

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: A partir de um conjunto de números inteiros sequenciais, obtidos com base em dados fornecidos pelo usuário (número inicial e final), identifique e apresente: a.A quantidade de números inteiros e positivos; b.A quantidade de números pares; c.A quantidade de números ímpares; d.A quantidade de números ímpares e divisíveis por 3 e por 7; e.A respectiva média de cada um dos items.


 
var
   numero1,numero2,numero1bkp:inteiro
   positivo,par,impar,divisivel3e7:inteiro
   contadorpositivo,contadorpar,contadorimpar,contadordivisivel3e7:inteiro
inicio
// Seção de Comandos 
   escreval("relatorio de numeros")
   escreval
   escreval
   escreval("digite um intervalo de numeros")
   escreval
   escreval("digite o numero menor")
   leia(numero1)
   numero1bkp<-numero1
   escreval("digite o numero maior")
   leia(numero2)
   enquanto (numero1>numero2) faca
      escreval("o primeiro numero deve ser menor que o segundo")
      escreval("digite o numero menor")
      leia(numero1)
      escreval("digite o numero maior")
      leia(numero2)
   fimenquanto
   positivo<-0
   par<-0
   impar<-0
   divisivel3e7<-0
   contadorpositivo<-0
   contadorpar<-0
   contadorimpar<-0
   contadordivisivel3e7<-0

   escreval("contando numeros inteiros positivos")
   enquanto (numero1<numero2) faca
      se (numero1>=0) entao
         positivo<-positivo+1
         contadorpositivo<-contadorpositivo+1
      fimse
   numero1<-numero1+1

   fimenquanto

   numero1<-numero1bkp

   escreval("contando os numeros pares")
   enquanto (numero1<=numero2) faca
      se (numero1 mod 2 = 0) entao
         par<-par+1
         contadorpar<-contadorpar+1
      fimse
   numero1<-numero1+1
   fimenquanto

numero1<-numero1bkp

   escreval("contando os numeros impares")
   enquanto (numero1<=numero2) faca
      se ((numero1 mod 2=1) ou (numero1 mod 2=-1)) entao
         impar<-impar+1
         contadorimpar<-contadorimpar+1
      fimse
   numero1<-numero1+1
   fimenquanto

numero1<-numero1bkp

   escreval("contando os numeros impares divisiveis por 3 e por 7")
   enquanto (numero1<numero2) faca
      se (numero1=0) entao
         //nada a fazer
      senao
         se ((numero1 mod 3 = 0) e (numero1 mod 7 = 0)) entao
         divisivel3e7<-divisivel3e7+1
         contadordivisivel3e7<-contadordivisivel3e7+1
         fimse
      fimse
   numero1<-numero1+1
   fimenquanto




   escreval
   escreval
   escreval("relatorio:")
   escreval
   escreval("total de numeros inteiros positivos = ",positivo)
   escreval("total de numeros pares = ",par)
   escreval("total de numeros impares = ",impar)
   escreval("total de numeros divisiveis por 3 e por 7 = ",divisivel3e7)
   escreval
   escreval
   se (numero1bkp>=0) entao
   escreval("media de numeros inteiros positivos = ",(numero2-numero1bkp)\contadorpositivo)
   escreval("media de numeros pares = ",(numero2-numero1bkp)\contadorpar)
   escreval("media de numeros impares = ",(numero2-numero1bkp)\contadorimpar)
   escreval("media de numeros divisiveis por 7 = ",(numero2-numero1bkp)\contadordivisivel3e7)
   senao
      se (numero1bkp<0) entao
         escreval("media de numeros inteiros positivos = ",(numero2+(numero1bkp*(-1)))\contadorpositivo)
         escreval("media de numeros pares = ",(numero2+(numero1bkp*(-1)))\contadorpar)
         escreval("media de numeros impares = ",(numero2+(numero1bkp*(-1)))\contadorimpar)
         escreval("media de numeros divisiveis por 7 = ",(numero2+(numero1bkp*(-1)))\contadordivisivel3e7)
      senao
         se ((numero1bkp<0)e(numero2<0)) entao
            escreval("media de numeros inteiros positivos = ",((numero2*(-1))+(numero1bkp*(-1)))\contadorpositivo)
            escreval("media de numeros pares = ",((numero2*(-1))+(numero1bkp*(-1)))\contadorpar)
            escreval("media de numeros impares = ",((numero2*(-1))+(numero1bkp*(-1)))\contadorimpar)
            escreval("media de numeros divisiveis por 7 = ",(numero2+(numero1bkp*(-1)))\contadordivisivel3e7)
         fimse
      fimse
   fimse
fimalgoritmo
