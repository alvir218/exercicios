Algoritmo "vendasmaiscomissao"
// Descri��o   : calculo de salario com comissao
// Data atual  : 19/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva um algoritmo que l� o n�mero de um vendedor, o seu sal�rio fixo, o valor total de vendas por ele efetuadas e o percentual que ele ganha sobre o total de suas vendas. Calcular o sal�rio total do vendedor, acrescido do seu percentual de vendas) e escrever o n�mero e o sal�rio do vendedor na tela.

Var
// Se��o de Declara��es das vari�veis 
   vendedorn:inteiro
   salariobase,vendas,comissao,salariototal:real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
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