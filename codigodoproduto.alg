algoritmo "codigoproduto"

// Data : 4/13/2019
// le o codigo de um produto e reporta o relacionado a este

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Faça um algoritmo que lê o código de um produto e exibe seu nome na tela de acordo coma tabelaabaixo:Código do produtoNome do produto001Caderno002Lápis003BorrachaOutroDiversos

var
   codigo:inteiro
inicio
// Seção de Comandos
   escreval("informa um produto referente ao seu codigo")
   escreval
   escreval
   escreval("digite o codigo do produto com tres digitos:")
   leia(codigo)
   escolha codigo
      caso 001
         escreval("caderno")
      caso 002
         escreval("lapis")
      caso 003
         escreval("borracha")
      outrocaso
         escreval("diversos")
   fimescolha
fimalgoritmo
