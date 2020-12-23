/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019
exercicio: 
escreva uma função recursiva que procura um
elemento num array nao ordenado, com N valores
inteiros e retorna a sua posicao ou -1 se nao
encontrar
utilize o seguinte protótipo
int elemento(int X[], int numProc, int N)
*/



int vetor[55];

#include <stdio.h>
#include <stdlib.h>



int ordenarEBuscar(int numeroProcurado, int inicio, int fim, int iteracaoi, int iteracaoj) {
	
	int temporario;
	
	if (iteracaoi > fim - 2) {
				
		int meio = (inicio + fim) / 2;

		if (vetor[meio] == numeroProcurado) {
			return meio + 1;
		}
		else
			if (vetor[meio] != numeroProcurado && meio == inicio && meio == fim) {
				return -1;
			}
			else
				if (vetor[meio] > numeroProcurado) {
					fim = meio - 1;
					ordenarEBuscar(numeroProcurado, inicio, fim, iteracaoi, iteracaoj);
				}
				else
					if (vetor[meio] < numeroProcurado) {
						inicio = meio + 1;
						ordenarEBuscar(numeroProcurado, inicio, fim, iteracaoi, iteracaoj);

					}

	}

	else if (vetor[iteracaoi] > vetor[iteracaoj]) {
		temporario = vetor[iteracaoi];
		vetor[iteracaoi] = vetor[iteracaoj];
		vetor[iteracaoj] = temporario;
	}

	if (iteracaoj > fim - 2) {
		iteracaoi = iteracaoi + 1;
		return ordenarEBuscar(numeroProcurado, inicio, fim, iteracaoi, iteracaoi + 1);
	}
	else {
		return ordenarEBuscar(numeroProcurado, inicio, fim, iteracaoi, iteracaoj + 1);
	}

}



int main() {

	int tamanhoDoVetor = 55;
	int encontrarNumero = 999;
	int resultadoDaBusca = 999;

	printf("qual e o tamanho do vetor? \ndigite um numero qualquer entre 2 e 55:\n");
	do {
		scanf_s("%i", &tamanhoDoVetor);
	} while (tamanhoDoVetor < 2 || tamanhoDoVetor > 55);

	printf("\n\npreencha o vetor com numeros inteiros: \n");

	for (int iteracao = 0; iteracao < tamanhoDoVetor; iteracao = iteracao + 1) {
		scanf_s("%i", &vetor[iteracao]);
	}

	printf("\n\ndigite o numero que quer encontrar: \n");
	scanf_s("%i", &encontrarNumero);

	printf("\n\nordenando vetor e buscando... \n");

	resultadoDaBusca = ordenarEBuscar(encontrarNumero, 0, tamanhoDoVetor - 1, 0, 1);
	
	if (resultadoDaBusca == -1) {
		printf("\n\no numero nao esta contido no vetor");
	}
	else {
		printf("\n\no numero esta contido no vetor \numa vez ordenado encontra-se no indice %i", resultadoDaBusca);
	}



	printf("\n\n\n");
	system("pause");
	return 0;
}


