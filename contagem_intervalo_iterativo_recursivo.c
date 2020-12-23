/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio: 
Faça um algoritmo em linguagem C que contenha dois números inteiros digitados na tela pelo usuário: 

	a. O primeiro número marca um início; 

	b. O segundo número marca um fim; 

O algoritmo vai contar quantos números existem entre o início  (primeira entrada)  e  o  fim (segunda entrada). A impressão na tela do usuário deve ser realizada de duas formas: 

	a. Iterativa; 

	b. Recursiva; 

Ao colocar no seu relatório uma imagem do seu código funcionando, coloque ele rodando utilizando como valor de início os 2 últimos valores do seu RU e valor final o número 99.

*/



#include <stdio.h>
#include <stdlib.h>


void contar(int ninicialf, int nfinalf, int contadorf) {
	
	if ((nfinalf - ninicialf) > contadorf) {
		printf("%i\t", (contadorf + 1));
		contadorf = contadorf + 1;
		contar(ninicialf, nfinalf, contadorf);
	}
	else {
		printf("\n\nsao %i numeros contados recursivamente.\n\n", (contadorf));
	}
}


int main() {

	printf("linguagem de programacao\nlista de exercicios 1\nexercicio 5\n\n");


	int ninicial;
	int nfinal;
	unsigned int contador = 0;

	printf("\n\ndigite um numero inicial: \n");
	scanf_s("%i", &ninicial);

	printf("\n\ndigite um numero final: \n");
	scanf_s("%i", &nfinal);

	printf("\n\ncontando iterativamente...\n\n\t");

	while (   (nfinal - ninicial) > (contador)   ) {
		
		printf("%i\t", (contador + 1));
		contador = contador + 1;
	}

	printf("\n\nsao %i numeros contados iterativamente.\n\n", (contador));


	printf("\n\ncontando recursivamente...\n\n\t");

	contar(ninicial, nfinal, 0);



	printf("\n\n\n");
	system("pause");
	return 0;
}