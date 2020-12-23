//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: funcao recursiva no calculo de divisao



#include <stdio.h>
#include <stdlib.h>

int divisao(int a, int b) {
	if (a == 0 || b == 0 || a < b) {
		return 0;
	}
	else {
		if (b == 1) {
			return a;
		}
		else {
			return (1 + divisao(a - b, b));
		}
	}
}


int main() {
	int a, b, resul;
	printf("forneca os valores de a e b (a / b) : \n");
	scanf_s("%d %d", &a, &b);
	resul = divisao(a, b);
	printf("\n\n(a / b) = %d \n", resul);
	
	printf("\n\n\n");
	system("pause");
	return 0;
}



/*



*/
