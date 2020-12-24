/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
Desenvolva um programa que emule as características de uma agenda de contatos. A lista deve conter as seguintes características:1.(20%  da  nota)  Deve-se  ter  uma  lista  de  contatos  de  pessoas.  Para  criar  esta  lista  utilize  uma  LISTA ENCADEADA. Utilize como base o código apresentado em sala de aula e está no Github do Professor. Deve-se armazenar o nome completo de cada pessoa, e-mail para contato e telefone celular. Para inserção dos dados, você pode criar uma leitura dos dados através de um menu na tela ou já deixá-los armazenados em um arquivo e só carregar este arquivo; 2.(20% da nota) Deve-se existir um menu na tela. Este menu deve permitir a inserção e remoção de novos contatos. Deve-se também listar todos os contatos da lista e   permitir sair do programa. Para a inserção na lista, opte por uma das 3 possibilidades existentes de inserção (inicio, meio ou fim);   3.(30%  da  nota)  Ao  listar  os  contatos,  dê  para  o  usuário  a  opção  de  lista-los  na  ordem dos contatos cadastrados (ordem de inserção). Ao listar, liste todos os dados do usuário;  4.(30% da nota) Ao listar os contatos, dê para o usuário também a opção de lista-los por ordem alfabética  de  nomes  (A-Z).  Para  a  ordenação,  utilize  o  MERGE  SORT  ou  o  QUICK  SORT.  Para ordenar, não altere os dados dentro da lista, somente a listagem;   Observação: •Caso você  opte  por  ordenar  somente  os  endereços,  maneira  mais  eficiente,  irei  atribuir  mais  nota nesta atividade;
*/



#include<stdio.h>							   
#include<stdlib.h>
#include<string.h>

#define tamanhoNomeCompleto 256
#define tamanhoEmail 256
#define tamanhoTelefone 16



struct ElementoDaLista_Simples {
	char nomeCompleto[tamanhoNomeCompleto];
	char email[tamanhoEmail];
	char telefone[tamanhoTelefone];
	struct ElementoDaLista_Simples* prox;
} *Head;
//typedef struct ElementoDaLista_Simples Contatos;



int menu();
void InserirInicio(char nomeCompletof[tamanhoNomeCompleto], char emailf[tamanhoEmail], char telefonef[tamanhoTelefone]);
int Remover(char nomeCompletof[tamanhoNomeCompleto]);
void Listar();
void listarOrdemAlfabetica();
void quickSort(ElementoDaLista_Simples** Contatosf, int p, int u);
int particionar(ElementoDaLista_Simples** Contatosf, int p, int u); //encontra o pivo, faz varreduras e trocas
void trocar(ElementoDaLista_Simples** Contatosf, int i, int j);
void listarOrdemAlfabeticaPonteiros();
void quickSortPonteiro(ElementoDaLista_Simples** Contatosf, int p, int u);
int particionarPonteiro(ElementoDaLista_Simples** Contatosf, int p, int u); //encontra o pivo, faz varreduras e trocas
void trocarPonteiro(ElementoDaLista_Simples** Contatosf, int i, int j);


int  main() {
	int op, c, ordemDeListagem;
	char nomeCompletoAux[tamanhoNomeCompleto];
	char emailAux[tamanhoEmail];
	char telefoneAux[tamanhoTelefone];
	Head = NULL;

	while (1) {
		op = menu();
		switch (op) {
			case 1:
				printf("Digite o nome completo: \n");
				fgets(nomeCompletoAux, sizeof(nomeCompletoAux), stdin);
				while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
				
				printf("\nDigite o email: \n");
				fgets(emailAux, sizeof(emailAux), stdin);
				while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

				printf("\nDigite o telefone: \n");
				fgets(telefoneAux, sizeof(telefoneAux), stdin);
				while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
				
				InserirInicio(nomeCompletoAux, emailAux, telefoneAux);

				printf("\n\nContato adicionado.\n\n");

				system("pause");

			break;
		
			case 2:
				int res;
				printf("Digite o nome completo do contato a ser removido: \n");
				fgets(nomeCompletoAux, sizeof(nomeCompletoAux), stdin);
				while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
				res = Remover(nomeCompletoAux);
				if (res == 1)
					printf("\nContato removido.\n\n");
				else
					printf("\nContato nao encontrado.\n\n");

				system("pause");
			break;
				
			case 3:
				do{
					system("cls");
					printf("De que forma deseja listar os contatos?\n\n");
					printf("1. Listar por ordem de insercao.\n");
					printf("2. Listar por ordem alfabetica.\n");
					printf("3. Listar por ordem alfabetica ordenado por enderecos.\n");
					printf("\nDigite o numero da sua escolha:\n");
					scanf_s("%i", &ordemDeListagem);
				} while (ordemDeListagem != 1 && ordemDeListagem != 2 && ordemDeListagem !=3);

				switch (ordemDeListagem){
					case 1:
						Listar();
					break;
					
					case 2:
						listarOrdemAlfabetica();
					break;

					case 3:
						listarOrdemAlfabeticaPonteiros();
					break;

					default:
						printf("Opcao invalida.");
					break;
				}				
				
			break;
			
			case 4:
				return 0;
			
			default:
				printf("Opcao invalida.\n");
		}
	}
	return 0;
}



int menu() {
	int op, c;
	system("cls");

	printf("Agenda...\n\nO que deseja fazer?\n\n");

	printf("1. Inserir contato.\n");
	printf("2. Remover contato.\n");
	printf("3. Listar contatos.\n");
	printf("4. Sair.\n");
	printf("\n\nDigite o numero da sua escolha:\n");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("cls");

	return op;
}



void InserirInicio(char nomeCompletof[tamanhoNomeCompleto], char emailf[tamanhoEmail], char telefonef[tamanhoTelefone]){
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	strcpy_s(NovoElemento->nomeCompleto, nomeCompletof);
	strcpy_s(NovoElemento->email, emailf);
	strcpy_s(NovoElemento->telefone, telefonef);

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
	//free(NovoElemento);
	//ira iliminar o registro, quebrar a lista e o programa
	NovoElemento = NULL;
}



int Remover(char nomeCompletof[tamanhoNomeCompleto]){
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* Anterior;
	Anterior = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (strcmp(nomeCompletof, ElementoVarredura->nomeCompleto) == 0) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}

	return 0;
}



void Listar()
{
	system("cls");

	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("Nome: \n%s", ElementoVarredura->nomeCompleto);
		printf("\nEmail: \n%s", ElementoVarredura->email);
		printf("\nTelefone: \n%s", ElementoVarredura->telefone);
		
		printf("\n\n");
				
		ElementoVarredura = ElementoVarredura->prox;
	}
	
	free(ElementoVarredura);

	printf("\n\n");
	system("pause");
	return;
}



void listarOrdemAlfabetica() {

	int numeroDeContatos = 0;

	system("cls");

	ElementoDaLista_Simples* ElementoVarredura;

	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;

	if (ElementoVarredura == NULL) {
		return;
	}

	while (ElementoVarredura != NULL) {
		numeroDeContatos = numeroDeContatos + 1;
		ElementoVarredura = ElementoVarredura->prox;
	}
		
	
	//criar um vetor de struct dinamico e copia a lista encadeada pra la
	
	struct ElementoDaLista_Simples** Contatos;

	Contatos = (ElementoDaLista_Simples**)malloc(sizeof(struct ElementoDaLista_Simples*) * numeroDeContatos);

	for (int iteracao = 0; iteracao < numeroDeContatos; iteracao = iteracao + 1) {
		Contatos[iteracao] = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	}


	ElementoVarredura = Head;

	for (int iteracao = 0; iteracao < numeroDeContatos; iteracao = iteracao + 1) {

		strcpy_s(Contatos[iteracao]->nomeCompleto, ElementoVarredura->nomeCompleto);
		strcpy_s(Contatos[iteracao]->email, ElementoVarredura->email);
		strcpy_s(Contatos[iteracao]->telefone, ElementoVarredura->telefone);
		Contatos[iteracao]->prox = ElementoVarredura->prox;
		ElementoVarredura = ElementoVarredura->prox;
	}

	quickSort(Contatos, 0, numeroDeContatos - 1);

	for (int iteracao = 0; iteracao < numeroDeContatos; iteracao = iteracao + 1) {
		printf("Nome: \n%s", Contatos[iteracao]->nomeCompleto);
		printf("\nEmail: \n%s", Contatos[iteracao]->email);
		printf("\nTelefone: \n%s", Contatos[iteracao]->telefone);
		printf("\n\n");
	}

	free(Contatos);

	printf("\n\n");
	system("pause");
}



void quickSort(ElementoDaLista_Simples** Contatosf, int p, int u){
	int m;
	if (p < u)
	{
		m = particionar(Contatosf, p, u);
		quickSort(Contatosf, p, m);
		quickSort(Contatosf, m + 1, u);
	}
}



int particionar(ElementoDaLista_Simples** Contatosf, int p, int u) //encontra o pivo, faz varreduras e trocas
{
	int pivo_pos, i, j;
	char pivo[tamanhoNomeCompleto];

	pivo_pos = (p + u) / 2;
	strcpy_s(pivo, Contatosf[pivo_pos]->nomeCompleto);

	i = p - 1;
	j = u + 1;
	while (i < j)
	{
		do //testa os valores � direita
		{
			j--;
		} while (strcmp(Contatosf[j]->nomeCompleto, pivo) > 0);
		//while (vet[j] > pivo);

		do //testa os valores � esquerda
		{
			i++;
		} while (strcmp(Contatosf[i]->nomeCompleto, pivo) < 0);
		//while (vet[i] < pivo);

		if (i < j)
			trocar(Contatosf, j, i);
	}
	return j;
}



void trocar(ElementoDaLista_Simples** Contatosf, int i, int j) {
	
	//int aux;
	char nomeCompletoAux[tamanhoNomeCompleto];
	char emailAux[tamanhoEmail];
	char telefoneAux[tamanhoTelefone];

	//aux = vet[i];
	strcpy_s(nomeCompletoAux, Contatosf[i]->nomeCompleto);
	strcpy_s(emailAux, Contatosf[i]->email);
	strcpy_s(telefoneAux, Contatosf[i]->telefone);

	//vet[i] = vet[j];
	strcpy_s(Contatosf[i]->nomeCompleto, Contatosf[j]->nomeCompleto);
	strcpy_s(Contatosf[i]->email, Contatosf[j]->email);
	strcpy_s(Contatosf[i]->telefone, Contatosf[j]->telefone);

	//vet[j] = aux;
	strcpy_s(Contatosf[j]->nomeCompleto, nomeCompletoAux);
	strcpy_s(Contatosf[j]->email, emailAux);
	strcpy_s(Contatosf[j]->telefone, telefoneAux);
}



void listarOrdemAlfabeticaPonteiros() {

	int numeroDeContatos = 0;

	system("cls");

	ElementoDaLista_Simples* ElementoVarredura;

	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;

	if (ElementoVarredura == NULL) {
		return;
	}

	while (ElementoVarredura != NULL) {
		numeroDeContatos = numeroDeContatos + 1;
		ElementoVarredura = ElementoVarredura->prox;
	}


	//criar um vetor de ponteiro para struct dinamico e copia os enderecos da lista encadeada pra la
	
	//alocar dinamicamente um vetor de enderecos de struct
	ElementoDaLista_Simples** pContatos;

	pContatos = (ElementoDaLista_Simples**)malloc(numeroDeContatos * sizeof(ElementoDaLista_Simples*));

	for (int iteracao = 0; iteracao < numeroDeContatos; iteracao = iteracao + 1) {
		pContatos[iteracao] = (ElementoDaLista_Simples*)malloc(sizeof(ElementoDaLista_Simples*));

	}

	ElementoVarredura = Head;

	for (int iteracao = 0; iteracao < numeroDeContatos; iteracao = iteracao + 1) {
		pContatos[iteracao] = ElementoVarredura;
		ElementoVarredura = ElementoVarredura->prox;
	}

	//ordenar apenas enderecos
	quickSortPonteiro(pContatos, 0, numeroDeContatos - 1);

	for (int iteracao = 0; iteracao < numeroDeContatos; iteracao = iteracao + 1) {
		printf("Nome: \n%s", pContatos[iteracao]->nomeCompleto);
		printf("\nEmail: \n%s", pContatos[iteracao]->email);
		printf("\nTelefone: \n%s", pContatos[iteracao]->telefone);
		printf("\n\n");
	}

	free(pContatos);

	printf("\n\n");
	system("pause");
}



void quickSortPonteiro(ElementoDaLista_Simples** pContatosf, int p, int u) {
	int m;
	if (p < u)
	{
		m = particionarPonteiro(pContatosf, p, u);
		quickSortPonteiro(pContatosf, p, m);
		quickSortPonteiro(pContatosf, m + 1, u);
	}
}



int particionarPonteiro(ElementoDaLista_Simples** pContatosf, int p, int u) //encontra o pivo, faz varreduras e trocas
{
	int pivo_pos, i, j;
	char pivo[tamanhoNomeCompleto];

	pivo_pos = (p + u) / 2;
	strcpy_s(pivo, pContatosf[pivo_pos]->nomeCompleto);

	i = p - 1;
	j = u + 1;
	while (i < j)
	{
		do //testa os valores � direita
		{
			j--;
		} while (strcmp(pContatosf[j]->nomeCompleto, pivo) > 0);
		//while (vet[j] > pivo);

		do //testa os valores � esquerda
		{
			i++;
		} while (strcmp(pContatosf[i]->nomeCompleto, pivo) < 0);
		//while (vet[i] < pivo);

		if (i < j)
			trocarPonteiro(pContatosf, j, i);
	}
	return j;
}



void trocarPonteiro(ElementoDaLista_Simples** pContatosf, int i, int j) {

	//int aux;
	ElementoDaLista_Simples* ponteiroAux;
	
	//aux = vet[i];
	ponteiroAux = pContatosf[i];

	//vet[i] = vet[j];
	pContatosf[i] = pContatosf[j];

	//vet[j] = aux;
	pContatosf[j] = ponteiroAux;
}