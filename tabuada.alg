algoritmo "tabuada"

// Data : 4/14/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo que calcule e exiba a tabuada deum número escolhido até um determinado número ‘n’, fornecido pelo usuário.



var
   base,denumero,atenumero,controle:inteiro
inicio
// Seção de Comandos
   escreval("tabuada automatica de numeros determinados")
   escreval
   escreval
   escreval("digite a base da tabuada")
   leia(base)
   escreval("calcular de")
   leia(denumero)
   escreval("calcular ate")
   leia(atenumero)
   escreval("tabuada do ",base)
   para controle de denumero ate atenumero faca
   escreval(base," x ",controle," = ",base*controle)
   fimpara
fimalgoritmo
