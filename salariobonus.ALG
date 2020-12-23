Algoritmo "salariobonus"
// Data atual  : 21/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo em pseudocódigo e em fluxograma em que se necessita conhecer o valor do salário e o tempo de serviço de um funcionário. Casoo funcionário esteja a mais de 5 anos na empresa, ele receberá uma bonificação de 20% em seu salário. Caso contrário, somente de 10%. Mostre na tela o bônus do funcionário calculado a partir do seu salário.

Var
// Seção de Declarações das variáveis 
   salario,tempodeservico,bonus:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("qual é o salario do funcionario?")
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