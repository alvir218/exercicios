Algoritmo "carroderevenda"
// Descri��o   : valor total de um carro de revenda
//               revenda considerando impostos a media entre 48,2% a 54,8%
//               mais lucro do revendedor
// Data atual  : 19/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: O custo de um carro ao consumidor � a soma do custo de f�brica com a percentagem do distribuidor e o percentual dos impostos (aplicados ao custo da f�brica). Escrever um algoritmo  que  l�  o  custo  de  f�brica,  o  percentual  do  distribuidor  e  o  percentual  dos impostos e calcula e escreve o valor a ser pago pelo consumidor por este carro.

Var
// Se��o de Declara��es das vari�veis 
   cvfabrica,cvimpostos,cvrevendedor,cvconsumidor:real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   escreval("qual � o valor de fabrica do carro?")
   leia(cvfabrica)
   escreval("qual � a porcentagem de comissao do revendedor?")
   leia(cvrevendedor)
   cvrevendedor <- cvfabrica*cvrevendedor/100
   cvimpostos <- cvfabrica*(((48.2+54.8)/2)/100)
   cvconsumidor <- cvfabrica+cvimpostos+cvrevendedor
   escreval("esse carro custara: ",cvconsumidor," ao consumidor final.")
Fimalgoritmo