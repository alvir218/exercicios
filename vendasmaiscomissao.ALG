Algoritmo "vendasmaiscomissao"
// Descrição   : calculo de salario com comissao
// Data atual  : 19/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo que lê o número de um vendedor, o seu salário fixo, o valor total de vendas por ele efetuadas e o percentual que ele ganha sobre o total de suas vendas. Calcular o salário total do vendedor, acrescido do seu percentual de vendas) e escrever o número e o salário do vendedor na tela.

Var
// Seção de Declarações das variáveis 
   vendedorn:inteiro
   salariobase,vendas,comissao,salariototal:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("digite o numero do vendedor:")
   leia(vendedorn)
   escreval("digite o salario base do vendedor ",vendedorn)
   leia(salariobase)
   escreval("digite o valor total de vendas do vendedor ",vendedorn)
   leia(vendas)
   escreval("digite a porcentagem de comissao do vendedor ",vendedorn)
   leia(comissao)
//todas as linhas a seguir funcionam perfeitamente
//   salariototal <- salariobase+((vendas*comissao)/100)
//   salariototal <- salariobase+(vendas*comissao/100)
   salariototal <- salariobase+vendas*comissao/100
   escreval ("o salario total de ",vendedorn," sera de ",salariototal)
Fimalgoritmo