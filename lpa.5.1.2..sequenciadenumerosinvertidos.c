//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Dada uma sequência de n números digitados pelo usuário, imprimi-los na ordem inversa à de leitura.



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int contador1=0, contador2=9, vetor[10];
	
	printf("\nexibe os numeros em ordem inversa ao digitado\n\n\n");

	for (contador1; contador1 < 10; contador1 = contador1 + 1)
	{
		printf("digite um numero: \n");
		scanf_s("%d",&vetor[contador1]);
			   		 
	}

	printf("\nnumeros em ordem inversa:\n\n");

	for (contador2; contador2>=0; contador2=contador2-1)
	{
		printf("%d \n",vetor[contador2]);
			   
	}




	printf("\n");
	system("pause");
	return 0;
}