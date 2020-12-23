//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: escreva uma funcao recursiva para calcular a sequencia de fibonacci
//lp.t2b.fibonaccirecursividade.txt



#include <stdio.h>
#include <stdlib.h>


int fibonacci(int f1, int f2, int i, int iteracaomaximaf) {
	if (i > iteracaomaximaf - 1) {
		return f2;
	}
	else {
		return fibonacci(f2, f2 + f1, i + 1, iteracaomaximaf);
	}
}
	
	


int main() {
	int iteracaomaxima = 1;

	printf("digite o numero maximo de iteracoes: \n");
	scanf_s("%i", &iteracaomaxima);
		
	printf("\na sequencia de fibonacci de %i iteracoes e %i", iteracaomaxima, fibonacci(1,1,0,iteracaomaxima));
	

	printf("\n\n\n");
	system("pause");
	return 0;
}


