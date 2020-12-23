//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: exercicio 2 escreva uma funcao recursiva para inverter uma linha de texto
//lp.t2e2inverterfraserecursividade.c.txt



#include <stdio.h>
#include <stdlib.h>

int inverterfrase(char vetorf[], int i) {
	if (i < 0) {
		return 0;
	}
	else {
		printf("%c", vetorf[i]);
		return inverterfrase(vetorf, i-1);
	}
}


int main() {
	char frase[31] = "existe alguem mais belo que eu";
	
	inverterfrase(frase, 29);


	printf("\n\n\n");
	system("pause");
	return 0;
}


