/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019
exercicio: 
sort ordenar vetor crescentemente
adaptado de: 
https://www.informaticode.com.br/c-ordenar-um-vetor-em-ordem-crescente
*/



#include <stdio.h>
#include <stdlib.h>



int main() {

	int i, j, temp, vetor[12] = { 5, 2, 10, 54, 30, 22, 60, 31, 1, 45, 33, 12 };

	for (i = 0; i < 12; i++) {
		for (j = i + 1; j < 12; j++) {
			if (vetor[i] > vetor[j]) {
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}

	for (int i = 0; i < 12; i = i + 1) {
		printf("%i\t", vetor[i]);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}