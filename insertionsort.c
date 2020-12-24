/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
algoritmo de ordenacao insertion sort
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VETORDESSETAMANHO 6

void insertionSort(int* vetorf);

int main() {

	int vetor[VETORDESSETAMANHO];

	  //preenchendo vetor com 0
	for (int iteracao = 0; iteracao < VETORDESSETAMANHO; iteracao = iteracao + 1) {
		vetor[iteracao] = 0;
	}

	  //criando uma semente aleatoria
	srand(time(NULL));

	  //preenchendo vetor com valores aleatorios
	for (int iteracao = 0; iteracao < VETORDESSETAMANHO; iteracao = iteracao + 1) {
		vetor[iteracao] = (rand() % 999) ;
	}

	printf("vetor sem ordenar:\n\n");

	for (int iteracao = 0; iteracao < VETORDESSETAMANHO; iteracao = iteracao + 1) {
		printf("%i \n", vetor[iteracao]);
	}

	//chama funcao de ordenar
	insertionSort(vetor);


	printf("\n\nvetor ordenado:\n\n");

	for (int iteracao = 0; iteracao < VETORDESSETAMANHO; iteracao = iteracao + 1) {
		printf("%i \n", vetor[iteracao]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}



void insertionSort(int* vetorf) {
	for (int iteracao1 = 1; iteracao1 < VETORDESSETAMANHO; iteracao1 = iteracao1 + 1) {
		int escolhido = vetorf[iteracao1];
		int iteracao2 = iteracao1 - 1;

		while (iteracao2 >= 0 && vetorf[iteracao2] > escolhido) {
			vetorf[iteracao2 + 1] = vetorf[iteracao2];
			iteracao2 = iteracao2 - 1;
		}

		vetorf[iteracao2 + 1] = escolhido;
	}
}


