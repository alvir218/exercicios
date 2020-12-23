algoritmo "formadepagamento"

// Data : 4/14/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Uma   loja   de   departamentos   está   oferecendo   diferentes   formas   de   pagamento, conforme  opções  listadas  a  seguir. Faça  um  algoritmo  que  leia  o  valor  total  de  uma compra  e  calcule  o  valor  do  pagamento  final  de  acordo  com  a  opção  escolhida.  Se  a escolha for por pagamento parcelado, calcule também o valor de cadaparcela. Ao final, apresente o valor totalda compra e o valor das parcelas:?Pagamento àvista –conceder desconto de 5%;?Pagamento em 3x –o valor não sofre alterações;?Pagamento em 5x –acréscimode 2%;?Pagamento em 10x –acréscimo 8%;



var
   pagamento:inteiro
   compra,diferenca:real
   
inicio
// Seção de Comandos
   escreval("calculo de pagamento com desconto ou acrescimo")
   escreval
   escreval
   escreval("qual o valor total da compra?")
   leia(compra)
   escreval
   escreval("qual a forma de pagamento?")
   escreval
   escreval("1 pagamento a vista")
   escreval("2 pagamento em 3 vezes")
   escreval("3 pagamento em 5 vezes")
   escreval("4 pagamento em 10 vezes")
   leia(pagamento)
   escolha pagamento
   caso 1
      escreval("escolhido pagamento a vista")
      diferenca<-(compra-(compra*5/100))
      escreval("o valor da compra e de ",diferenca," reais")
   caso 2
      escreval("escolhido pagamento em 3 vezes")
      escreval("o valor da compra e de ",compra," reais")
   caso 3
      escreval("escolhido pagamento em 5 vezes")
      diferenca<-(compra+(compra*2/100))
      escreval("o valor da compra e de ",diferenca," reais")
   caso 4
      escreval("escolhido pagamento em 10 vezes")
      diferenca<-(compra+(compra*8/100))
      escreval("o valor da compra e de ",diferenca," reais")
   outrocaso
      escreval("forma de pagamento invalida")
   fimescolha
fimalgoritmo
