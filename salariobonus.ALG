Algoritmo "salariobonus"
// Data atual  : 21/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo em pseudoc�digo e em fluxograma em que se necessita conhecer o valor do sal�rio e o tempo de servi�o de um funcion�rio. Casoo funcion�rio esteja a mais de 5 anos na empresa, ele receber� uma bonifica��o de 20% em seu sal�rio. Caso contr�rio, somente de 10%. Mostre na tela o b�nus do funcion�rio calculado a partir do seu sal�rio.

Var
// Se��o de Declara��es das vari�veis 
   salario,tempodeservico,bonus:real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("qual � o salario do funcionario?")
   leia(salario)
   escreval("quantos anos de servico tem o funcionario")
   leia(tempodeservico)
   se tempodeservico>5 entao
      bonus<-salario*20/100
      escreval("o funcionario recebera ",bonus," reais de bonus.")
   senao
        bonus<-salario*10/100
        escreval("o funcionario recebera ",bonus," reais de bonus.")
   fimse
Fimalgoritmo