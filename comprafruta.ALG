Algoritmo "comprafruta"
// Data atual  : 21/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo em pseudocódigo em que o usuário escolhe se ele quer comprar maças ou laranjas. Deverá ser apresentado a tela um menu com a opção 1 para maça e 2 para laranja. Após escolhida a fruta, deve-se digitar quantas unidades se quer comprar. O  algoritmo  deve  calcular  o  preço  total  a  pagardo  produto  escolhido  e  mostra-lo  na tela. Considera que uma maça custa R$ 2,30 e uma laranja R$ 5,60.

Var
// Seção de Declarações das variáveis 
   fruta,frutaquantidade:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
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
