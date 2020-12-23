#include <stdio.h>
#include <stdlib.h>

// carro de revenda

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: O custo de um carro ao consumidor é a soma do custo de fábrica com a percentagem do distribuidor e o percentual dos impostos (aplicados ao custo da fábrica). Escrever um algoritmo  que  lê  o  custo  de  fábrica,  o  percentual  do  distribuidor  e  o  percentual  dos impostos e calcula e escreve o valor a ser pago pelo consumidor por este carro.



int main()
{
float cvfabrica, cvimpostos, cvrevendedor, cvconsumidor;

printf("\nqual e o valor de fabrica do carro?\n");
scanf_s("%f", &cvfabrica);
printf("\nqual e a porcentagem de comissao do revendedor\n");
scanf_s("%f",&cvrevendedor);
cvrevendedor = cvfabrica * cvrevendedor / 100;
cvimpostos = cvfabrica * (((48.2 + 54.8) / 2) / 100);
cvconsumidor = cvfabrica + cvimpostos + cvrevendedor;
printf("\nesse carro custara %.2f reais ao consumidor final\n", cvconsumidor);




printf("\n");
system("pause");
}