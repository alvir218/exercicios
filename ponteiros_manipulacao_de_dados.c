/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio: 
Escreva um algoritmo em LINGUAGEM C que armazene na memória o seu RU e o valor 1234567, ambos digitados pelo usuário na tela. 
Em seguida, imprima na tela ambos RU usando ponteiros. O algoritmo também vai ter que comparar os dois RU usando ponteiros e imprimir na tela qual é o maior.
*/



#include <stdio.h>
#include <stdlib.h>


int main() {

	printf("linguagem de programacao\nlista de exercicios 1\nexercicio 2\n\n");

	unsigned int ru;
	unsigned int valorqualquer;

	printf("\n\ndigite seu ru : \n");
	scanf_s("%i", &ru);

	printf("\n\ndigite um valor qualquer: \n");
	scanf_s("%i", &valorqualquer);

	unsigned int* pru;
	unsigned int* pvalorqualquer;

	pru = &ru;
	pvalorqualquer = &valorqualquer;

	printf("\n\nimprimindo seu ru por ponteiro:\n%i", *pru);

	printf("\n\nimprimindo um valor qualquer por ponteiro:\n%i", *pvalorqualquer);

	if (*pru > * pvalorqualquer) {
		printf("\n\no seu ru: %i e maior que o segundo valor digitado.\n\n", *pru);
	}
	else {
		if (*pvalorqualquer > * pru) {
			printf("\n\no segundo valor digitado: %i e maior que o seu ru.", *pvalorqualquer);
		}
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}