Algoritmo "maiordeidade"
// Data atual  : 21/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo em pseudocódigo para ler o ano de nascimento de uma pessoa e calcular se a pessoa é maior de idade. Mostre uma mensagem na tela informando sua idade  e  se  ele  é  de  maior.  Despreze  o mêsde  nascimento  e  assume  a  maior  idade brasileira.

Var
// Seção de Declarações das variáveis 
   anonascimento,anoatual,idade:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("qual é o ano de seu nascimento?")
   leia(anonascimento)
   escreval("qual é o ano atual?")
   leia(anoatual)
   idade<-anoatual-anonascimento
   se idade>=18 entao
      escreval("voce é maior de idade.")
   senao
        escreval("voce é menor de idade")
   fimse
Fimalgoritmo