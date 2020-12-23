//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: escreva uma funcao recursiva para encontrar o maior elemento em um array exemplo v = [10,5,7,3,11,27,8,9,4] ressposta: "27, posicao 5 do array."
//lp.t2e4maiorvalordovetorrecursividade.c.txt



#include <stdio.h>
#include <stdlib.h>

int maiorvalor(int vetorf[], int i, int maiorvalordovetor, int imaior) {
	
	if (i > 8) {
		return imaior;
	}
	else {
		if(vetorf[i] > maiorvalordovetor){
			maiorvalordovetor = vetorf[i];
			imaior = i;
			return maiorvalor(vetorf, i+1, maiorvalordovetor, imaior);
		}
		else {
			return maiorvalor(vetorf, i + 1, maiorvalordovetor, imaior);
		}
			
	}
}


int main() {
	int vetor[9] = {10, 5, 7, 3, 11, 27, 8, 9, 4};
	int posicaodomaior;

	posicaodomaior = maiorvalor(vetor, 0, 0, 0);

	printf("%d, posicao %d do array.", vetor[posicaodomaior], posicaodomaior);

	printf("\n\n\n");
	system("pause");
	return 0;
}


