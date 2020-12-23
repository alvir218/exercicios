/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio: 
Escreva um algoritmo em linguagem C com as seguintes instruções: 

1. Declare três variáveis (inteiro, real e char); 
2. Declare três ponteiros; 
3. Associe as variáveis aos ponteiros; 
4. Modifique os valores de cada variável indiretamente usando os ponteiros associados. Para armazenar os valores nas variáveis, armazene na variável char a primeira letra do seu nome, na variável inteira os dois últimos dígitos do seu RU e na variável real os 4 últimos dígitos do seu RU, sendo os 2 últimos os valores com vírgula; 
5. Imprima na tela os valores das variáveis antes e após a modificação.
*/



#include <stdio.h>
#include <stdlib.h>

int main() {

	printf("linguagem de programacao\nlista de exercicios 1\nexercicio 1\n\n");

	int inteiro = 1;
	float real = 1.2;
	char caractere = 'z';

	printf("\nvariavel inteiro previamente inicializada: \n%i\n\n", inteiro);
	printf("\nvariavel real previamente inicializada: \n%f\n\n", real);
	printf("\nvariavel caractere previamente inicializada: \n%c\n\n", caractere);

	int* pinteiro;
	float* preal;
	char* pcaractere;

	pinteiro = &inteiro;
	preal = &real;
	pcaractere = &caractere;

	*pinteiro = 25;
	*preal = 95.25;
	*pcaractere = 'a';


	printf("\nvariavel inteiro modificada por ponteiro: \n%i\n\n", *pinteiro);
	printf("\nvariavel real modificada por ponteiro: \n%f\n\n", *preal);
	printf("\nvariavel caractere modificada por ponteiro: \n%c", *pcaractere);

	printf("\n\n\n");
	system("pause");
	return 0;
}