//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Elabore um algoritmo que crie dois vetores A e B de 10 elementos e, a partir deles, crie um vetor C, composto pela soma dos elementos de cada posição de A e B.



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int contador, vetora[10], vetorb[10], vetorc[10];

	printf("\nsoma vetora vetorb envia resultado para vetorc\n\n\n");

	for (contador=0; contador <= 9; contador = contador + 1)
	{
		printf("\ndigite o numero a: \n");
		scanf_s("%d",&vetora[contador]);
		
		printf("\ndigite o numero b: \n");
		scanf_s("%d", &vetorb[contador]);

		vetorc[contador] = (vetora[contador] + vetorb[contador]);
		printf("\na + b = %d\n",vetorc[contador]);
	}




	printf("\n");
	system("pause");
	return 0;
}