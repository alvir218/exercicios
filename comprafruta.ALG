Algoritmo "comprafruta"
// Data atual  : 21/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo em pseudoc�digo em que o usu�rio escolhe se ele quer comprar ma�as ou laranjas. Dever� ser apresentado a tela um menu com a op��o 1 para ma�a e 2 para laranja. Ap�s escolhida a fruta, deve-se digitar quantas unidades se quer comprar. O  algoritmo  deve  calcular  o  pre�o  total  a  pagardo  produto  escolhido  e  mostra-lo  na tela. Considera que uma ma�a custa R$ 2,30 e uma laranja R$ 5,60.

Var
// Se��o de Declara��es das vari�veis 
   fruta,frutaquantidade:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("digite o numero da fruta que deseja comprar:")
   escreval("1 maca")
   escreval("2 laranja")
   leia(fruta)
   se ((fruta=1) ou (fruta=2)) entao
      escreval("quantas frutas deseja comprar?")
      leia(frutaquantidade)
         se fruta=1 entao
            escreval("sua compra custara ",2.3*frutaquantidade," reais")
         senao
            se fruta=2 entao
               escreval("sua compra custara ",5.6*frutaquantidade," reais")
            senao
               escreval ("escolha invalida")
            fimse
         fimse
   senao
      escreval("escolha invalida")
   fimse
Fimalgoritmo
