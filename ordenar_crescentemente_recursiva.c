/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019
exercicio: 
sort ordenar crescentemente recursivamente
*/



#include <stdio.h>
#include <stdlib.h>

#define tamanhoDoVetorD 12

int vetor[tamanhoDoVetorD] = { 5, 2, 10, 54, 30, 22, 60, 31, 1, 45, 33, 12 };

int ordenarVetor(int tamanhoDoVetorf, int iteracaoi, int iteracaoj) {
	int temporario;

	if (iteracaoi > tamanhoDoVetorf - 2) {
		return 0;
	}
	else if (vetor[iteracaoi] > vetor[iteracaoj]) {
		temporario = vetor[iteracaoi];
		vetor[iteracaoi] = vetor[iteracaoj];
		vetor[iteracaoj] = temporario;
	}

	if (iteracaoj > tamanhoDoVetorf - 2) {
		iteracaoi = iteracaoi + 1;
		return ordenarVetor(tamanhoDoVetorf, iteracaoi, iteracaoi + 1);
	}
	else {
		return ordenarVetor(tamanhoDoVetorf, iteracaoi, iteracaoj + 1);
	}

}


int main() {



	ordenarVetor(tamanhoDoVetorD, 0, 1);

	printf("vetor ordenado em ordem crescente...\n\n");

	for (int i = 0; i < 12; i = i + 1) {
		printf("%i  ", vetor[i]);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}