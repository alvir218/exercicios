Algoritmo "maiordeidade"
// Data atual  : 21/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo em pseudoc�digo para ler o ano de nascimento de uma pessoa e calcular se a pessoa � maior de idade. Mostre uma mensagem na tela informando sua idade  e  se  ele  �  de  maior.  Despreze  o m�sde  nascimento  e  assume  a  maior  idade brasileira.

Var
// Se��o de Declara��es das vari�veis 
   anonascimento,anoatual,idade:inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("qual � o ano de seu nascimento?")
   leia(anonascimento)
   escreval("qual � o ano atual?")
   leia(anoatual)
   idade<-anoatual-anonascimento
   se idade>=18 entao
      escreval("voce � maior de idade.")
   senao
        escreval("voce � menor de idade")
   fimse
Fimalgoritmo