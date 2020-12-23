#include <stdio.h>
#include <stdlib.h>

//calculo de idade
//comparacao maior ou menor de idade

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Escreva um algoritmo em pseudocódigo para ler o ano de nascimento de uma pessoa e calcular se a pessoa é maior de idade. Mostre uma mensagem na tela informando sua idade  e  se  ele  é  de  maior.  Despreze  o mêsde  nascimento  e  assume  a  maior  idade brasileira.

int main()

{
	int anonascimento, anoatual, idade;

	printf("qual e o ano atual?\n");
	scanf_s("%i", &anoatual);
//	printf("o ano atual e %i",anoatual);
	printf("qual e o seu ano de nascimento?\n");
	scanf_s("%i", &anonascimento);
//	printf("voce nasceu em %i", anonascimento);
	

	idade = anoatual - anonascimento;
 	printf("voce tem %i anos\n",idade);
	if (idade>= 18) 
	{
		printf("voce e maior de idade\n");
	}
	else 
	{
		printf("voce e menor de idade\n");
	}
	printf("\n");
	system("pause");
	return 0;

}