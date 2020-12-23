/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio: 
Faça um algoritmo em linguagem C com as seguintes funcionalidades:

    Receba um registro, com dois campos, como dados de entrada. 
    O primeiro campo é um vetor que vai armazenar o nome do aluno. 
    O segundo campo é uma variável do tipo inteiro que vai armazenar o RU do aluno.
    Imprimir na tela os dados armazenados na estrutura.
*/



#include <stdio.h>
#include <stdlib.h>


int main() {

	printf("linguagem de programacao\nlista de exercicios 1\nexercicio 3\n\n");


	struct cadastrodealuno {
		char nome[42];
		unsigned int ru;

	}; struct cadastrodealuno caluno;

	printf("\n\ndigite o nome do aluno: \n\n");
	fflush(stdin);
	fgets(caluno.nome, 42, stdin);

	printf("\n\ndigite o ru: \n\n");
	scanf_s("%i", &caluno.ru);

	printf("\n\no nome do aluno e: \n%s\n\n\n\no ru do aluno e: \n%i", caluno.nome, caluno.ru);

	printf("\n\n\n");
	system("pause");
	return 0;
}