/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019
exercicio:
busca binaria
em vetor
ordenado crescentemente;
*/



#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int vetorf[], int numeroProcurado, int inicio, int fim) {
	int meio = (inicio + fim) / 2;

	if (vetorf[meio] == numeroProcurado) {
		return meio;
	}
	else
		if (vetorf[meio] != numeroProcurado && meio == inicio && meio == fim) {
			return -1;
		}
		else
			if (vetorf[meio] > numeroProcurado) {
				fim = meio - 1;
				buscarNumero(vetorf, numeroProcurado, inicio, fim);
			}
			else
				if (vetorf[meio] < numeroProcurado) {
					inicio = meio + 1;
					buscarNumero(vetorf, numeroProcurado, inicio, fim);

				}
				
}



int main() {
	//0~14;
	int vetor[15] = { 1,2,4,5,8,10,11,20,25,32,33,37,39,46,50 };

	int encontrarNumero = 999999;

	int resultadoDaBusca;

	printf("digite o numero que quer encontrar: \n");
	scanf_s("%i", &encontrarNumero);

	resultadoDaBusca = buscarNumero(vetor, encontrarNumero, 0, 15 - 1);
	
	if (resultadoDaBusca == -1) {
		printf("\n\no numero nao esta contido no vetor");
	}
	else {
		printf("\n\no numero esta contido no vetor no indice %i", resultadoDaBusca);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}


