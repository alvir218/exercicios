//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: escreva uma funcao recursiva para somar os elementos de um array
//lp.t2e3somavetorrecursividade.c.txt



#include <stdio.h>
#include <stdlib.h>

int somarvetor(int vetorf[], int i) {
	if (i > 3) {
		return vetorf[i];
	}
	else {
		return vetorf[i] + somarvetor(vetorf, i+1);
	}
}


int main() {
	int vetor[5] = { 11,2,3,14,7 };
	int n, soma;
	
	printf("somando os elementos do vetor...\n");
	soma = somarvetor(vetor, 0);
	printf("\n\na soma dos elementos do vetor e %d \n", soma);
	
	printf("\n\n\n");
	system("pause");
	return 0;
}


