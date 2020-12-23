//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: exemplo de funcao recursiva no calculo de multiplicacao

//a1e1

#include <stdio.h>
#include <stdlib.h>

int multiplica(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	else {
		return (a + multiplica(a, b - 1));
	}
}


int main() {
	int a, b, resul;
	printf("forneca os valores de a e b (a x b) : \n");
	scanf_s("%d %d", &a, &b);
	resul = multiplica(a, b);
	printf("\n\n(a x b) = %d \n", resul);
	
	printf("\n\n\n");
	system("pause");
	return 0;
}



/*



*/
