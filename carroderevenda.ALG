Algoritmo "carroderevenda"
// Descrição   : valor total de um carro de revenda
//               revenda considerando impostos a media entre 48,2% a 54,8%
//               mais lucro do revendedor
// Data atual  : 19/03/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: O custo de um carro ao consumidor é a soma do custo de fábrica com a percentagem do distribuidor e o percentual dos impostos (aplicados ao custo da fábrica). Escrever um algoritmo  que  lê  o  custo  de  fábrica,  o  percentual  do  distribuidor  e  o  percentual  dos impostos e calcula e escreve o valor a ser pago pelo consumidor por este carro.

Var
// Seção de Declarações das variáveis 
   cvfabrica,cvimpostos,cvrevendedor,cvconsumidor:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("qual é o valor de fabrica do carro?")
   leia(cvfabrica)
   escreval("qual é a porcentagem de comissao do revendedor?")
   leia(cvrevendedor)
   cvrevendedor <- cvfabrica*cvrevendedor/100
   cvimpostos <- cvfabrica*(((48.2+54.8)/2)/100)
   cvconsumidor <- cvfabrica+cvimpostos+cvrevendedor
   escreval("esse carro custara: ",cvconsumidor," ao consumidor final.")
Fimalgoritmo