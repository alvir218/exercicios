/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
adatar um vetor normal para ser utilizado 
como a estrutura de dados pilha
*/



#include<stdio.h>
#include<stdlib.h>
#define tamanhoVetor 10

int push(int vetorf[], int elemento, int topof);
int pop(int topof);

int main() {
	char c;
	int menu = -1;
	int vetor[tamanhoVetor];
	int topo = 0;
	int elemento;

	while(true){
		do{
			system("cls");
			printf("O que deseja fazer? \nDigite um numero:\n\n");
			printf("1. Inserir elemento.\n");
			printf("2. Remover elemento.\n");
			printf("3. Listar elementos.\n");
			printf("0. Sair.\n");
			scanf_s("%i", &menu);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

			switch (menu) {
			case 0:
				return 0;
			break;

			case 1:
				system("cls");
				printf("Qual numero deseja adicionar?\n");
				scanf_s("%i", &elemento);
				while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
				topo = push(vetor, elemento, topo);
			break;

			case 2:
				system("cls");
				topo = pop(topo);
			break;

			case 3:
				system("cls");
				for (int iteracao = 0; iteracao < topo; iteracao = iteracao + 1) {
					printf("%i \n", vetor[iteracao]);
				}
				system("pause");
			break;

			default:
				printf("Escolha invalida.\n");
			break;
			}
		} while (menu != 0 && menu != 1 && menu != 2 && menu != 3);
		
	}
}

int push(int vetorf[], int elemento, int topof) {
	if(topof < tamanhoVetor){
		vetorf[topof] = elemento;
		topof = topof + 1;
		return topof;
	}
	else {
		printf("Memoria insuficiente:\nTente remover ao menos um elemento.\n");
		printf("\n\n");
		system("pause");
		return topof;
	}

}

int pop(int topof) {
	if(topof >= 1){
		topof = topof - 1;
		printf("Ultimo elemento removido.\n\n");
		system("pause");
		return topof;
	}
	else {
		printf("Nao ha elementos a serem removidos.\n\n");
		system("pause");
		return topof;

	}
}

