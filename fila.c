/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
adatar um vetor normal para ser utilizado 
como a estrutura de dados fila
*/


//conceito de fila em c puro

#include<stdio.h>
#include<stdlib.h>
#define tamanhoVetor 3

void queue(int vetorf[], int* elementof, int* iniciof, int* fimf, int* indiceAtualf, int* quantidadeAtualf);
void dequeue(int* iniciof, int* fimf, int* indiceAtualf, int* quantidadeAtualf);
void listar(int vetorf[], int* iniciof, int* fimf, int* indiceAtualf, int* quantidadeAtualf);

int main() {
	char c;
	int menu = -1;
	int vetor[tamanhoVetor];
	int elemento;
	int inicio = 0;
	int fim = (tamanhoVetor - 1);
	int indiceAtual = 0;
	int quantidadeAtual = 0;

	while (1) {
		do {
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
				queue(vetor, &elemento, &inicio, &fim, &indiceAtual, &quantidadeAtual);
				break;

			case 2:
				system("cls");
				dequeue(&inicio, &fim, &indiceAtual, &quantidadeAtual);
				break;

			case 3:
				system("cls");
				listar(vetor, &inicio, &fim, &indiceAtual, &quantidadeAtual);
				break;

			default:
				printf("Escolha invalida.\n");
				break;
			}
		} while (menu != 0 && menu != 1 && menu != 2 && menu != 3);

	}
}

void queue(int vetorf[], int* elementof, int* iniciof, int* fimf, int* indiceAtualf, int* quantidadeAtualf) {
		//se tiver espaco para mais um numero
	if(*quantidadeAtualf < tamanhoVetor){
		vetorf[*indiceAtualf] = *elementof;
		*indiceAtualf = *indiceAtualf + 1;
			//se ja tiver chegado no fim o novo fim sera 0;
		if (*indiceAtualf == tamanhoVetor) {
			*indiceAtualf = 0;
		}
		*quantidadeAtualf = *quantidadeAtualf + 1;
		printf("\nElemento adicionado.\n\n");
		system("pause");
		
	} else {
		printf("\n\nMemoria insuficiente:\nConsidere remover ao menos um elemento.\n");
		printf("\n\n");
		system("pause");
	}
}

void dequeue(int* iniciof, int* fimf, int* indiceAtualf, int* quantidadeAtualf) {
		//se ja tiver algum dado ele sera removido
	if(*quantidadeAtualf > 0){
		*iniciof = *iniciof + 1;
		if (*iniciof == tamanhoVetor) {
			*iniciof = 0;
		}
		*quantidadeAtualf = *quantidadeAtualf - 1;
		printf("Elemento removido.\n\n");
		system("pause");
	} else {
		printf("Nao ha elementos a serem removidos.\n\n");
		system("pause");
	}
}

void listar(int vetorf[], int* iniciof, int* fimf, int* indiceAtualf, int* quantidadeAtualf) {
	int listados = 0;
	int listar = *iniciof;
		//enquanto tiver item nao listado
	while (listados < *quantidadeAtualf) {
		printf("%i\n", vetorf[listar]);
		listar = listar + 1;
			//se chegar no fim entao a fila continua no primeiro indice do vetor
		if (listar >= tamanhoVetor) {
			listar = 0;
		}
		listados = listados + 1;
	}
	printf("\n\n");
	system("pause");
}
