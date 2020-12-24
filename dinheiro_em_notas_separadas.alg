//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2
//data: 26.03.18

//exercicio: 
//distribui um valor monetario inteiro na quantidade minima de notas



algoritmo "dinheiro"

var

v:inteiro
// nao aceita trabalhar divisoes inteira com variaveis do tipo real
inicio
// Seção de Comandos 
   escreva("valor (r$):")
   leia(v)
   escreval(v\100, " notas de 100")
   v <- v % 100
   // sobrescrevendo o valor da variavel para o resto da divisao do valor por 100
   escreval(v\50, " notas de 50")
   v <- v % 50
   escreval(v\20, " notas de 20")
   v <- v % 20
   escreval(v\10, " notas de 10")
   v <- v % 10
   escreval(v\5, " notas de 5")
   v <- v % 5
   escreval(v\2, " notas de 2")
   v <- v % 2
   escreval(v\1, " moedas de 1")
   v <- v % 1
fimalgoritmo
