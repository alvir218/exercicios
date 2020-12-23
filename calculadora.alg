algoritmo "calculadora4operacoes"

// Data : 4/13/2019
// Seção de Declarações
// calculadora de 4 operacoes

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Faça um algoritmo que apresenta na tela um menu parauma calculadora simples que recebe como entrada dois valores reais,e que realiza uma das 4 operaçõesabaixo. Se o usuáriodigitar  qualquer  opção  fora  das  4  operações  permitidas,  seu  algoritmo  deve tratar isso.a.adição(operação 1);b.subtração(operação 2);c.divisão (operação 3);d.multiplicação(operação 4).

var
   operacao:inteiro
   numero1,numero2:real
inicio
// Seção de Comandos 
   escreval("calculadora de dois numeros e quatro operacoes")
   escreval
   escreval
   escreval("digite um numero de acordo com a operacao desejada:")
   escreval
   escreval("1 adicao")
   escreval("2 subtracao")
   escreval("3 divisao")
   escreval("4 multiplicacao")
   escreval
   leia (operacao)
   se ( (operacao=1) ou (operacao=2) ou (operacao=3) ou (operacao=4) ) entao
      escreval("digite o primeiro numero:")
      leia (numero1)
      escreval("digite o segundo numero:")
      leia (numero2)
      escolha operacao
         caso 1
            escreval("a adicao de ",numero1," mais ",numero2," é igual a ",numero1+numero2)
         caso 2
            escreval("a subtracao de ",numero1," menos ",numero2," é igual a ",numero1-numero2)
         caso 3
            escreval("a divisao de ",numero1," dividido por ",numero2," e igual a ",numero1/numero2)
         caso 4
            escreval("a multiplicacao de ",numero1," multiplicado por ",numero2," e igual a ",numero1*numero2)
         outrocaso
            escreval("operacao invalida")
      fimescolha
   senao
      escreval("operacao invalida")
   fimse
fimalgoritmo
