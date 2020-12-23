/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio:
escreva um programa em c que solicita ao usuário
um número n e então lê um vetor de n notas e calcula
a média aritimética
*/


#include <stdio.h>
#include <stdlib.h>



int main(){

	int numeroDeNotas = 0;
	int somaDeNotas = 0;

	int *pNumeroDeNotas;

	printf("digite o numero de total de notas para preencher o vetor:\n");
	
	scanf_s("%i", &numeroDeNotas);

	printf("\n\nentre com as notas uma a uma:\n");

	pNumeroDeNotas = (int*)malloc(numeroDeNotas * sizeof(int));

	for (int i = 0; i < numeroDeNotas; i = i + 1) {
		scanf_s("%i", &pNumeroDeNotas[i]);
		somaDeNotas = somaDeNotas + pNumeroDeNotas[i];
	}
	
	printf("\n\na media aritimetica e: %i", somaDeNotas / numeroDeNotas);

	free(pNumeroDeNotas);

	pNumeroDeNotas = NULL;


	printf("\n\n\n");
	system("pause");
	return 0;
}


