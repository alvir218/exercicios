//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Elabore um algoritmo que recebe uma frase de até 100 caracteres e armazena em uma variável. Imprima em seguida esta variável na tela. Depois, verifiquese a frase tem mais do que 50 caracteres. Se tiver, imprima na tela na tela uma mensagem.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char frase[101];
	int tamanho;

	
	printf("\nrecebe uma frase e testa se e maior que 50 caracteres\n\n\n");




	printf("\ndigite uma frase:\n");
	gets_s(frase);
	puts(frase);

	tamanho = strlen(frase);

	if (tamanho > 50) 
	{
		printf("\nfrase maior que 50 caracteres\n");

	}

	printf("\n\n");
	system("pause");
	return 0;
}