/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
adaptacao do codigo de busca em profundidade criado originalmente pelo vinicius 
para uma versao de busca em profundidade
a versao usada como base para este algoritmo encontra-se em:
https://github.com/borinvini/EstruturaDeDados_2020-2
*/



#include <stdio.h>
#include <stdlib.h>

struct ListaDeVizinhos
{
	int vertice;
	ListaDeVizinhos* prox;
};

struct Grafo
{
	int TotalVertices;
	struct ListaDeVizinhos** ListaAdj; //Será um vetor do tamanho do numero de vértices
};

struct Fila //Fila dos vértices a serem visitados
{
	int vertice;
	Fila* prox;
}*top = NULL;

struct Grafo* CriarGrafo(int vertices);
void AdicionarAresta(struct Grafo* Grafo, int origem, int destino);
void MostrarGrafo(struct Grafo* Grafo);
void busca_largura(Grafo* Vizinhos, int v, int marcado[]);
void push(int y);
void pop();



int main()
{
	int NUMERO_VERTICES;
	int origem;
	int* marcado;
	
	NUMERO_VERTICES = 6;

	marcado = (int*) malloc(NUMERO_VERTICES * sizeof(int));

	for (int iteracao = 0; iteracao < NUMERO_VERTICES; iteracao = iteracao + 1) {
		marcado[iteracao] = 0;
	}

	Grafo* GrafoTeste = CriarGrafo(NUMERO_VERTICES);
	
	AdicionarAresta(GrafoTeste, 0, 1);
	AdicionarAresta(GrafoTeste, 0, 2);
	AdicionarAresta(GrafoTeste, 1, 3);
	AdicionarAresta(GrafoTeste, 2, 3);
	AdicionarAresta(GrafoTeste, 3, 4);
	AdicionarAresta(GrafoTeste, 3, 5);
	
	printf("Escolha um vertice para iniciar a busca:\n");
	scanf_s("%d", &origem);
	
	push(origem);

	

	MostrarGrafo(GrafoTeste);

	printf("\nVertices visitados do grafo, iniciando em V%d:\n", origem);
		
	busca_largura(GrafoTeste, origem, marcado);

	printf("\n");
	system("pause");
	return 0;
}

struct Grafo* CriarGrafo(int TotalVertices)
{
	Grafo* Grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
	Grafo->TotalVertices = TotalVertices;
	Grafo->ListaAdj = (struct ListaDeVizinhos**)malloc(TotalVertices * sizeof(struct ListaDeVizinhos*));

	for (int i = 0; i < TotalVertices; i++)
		Grafo->ListaAdj[i] = NULL;

	return Grafo;
}

void AdicionarAresta(struct Grafo* Grafo, int origem, int destino)
{ //INSERÇÃO NO INICIO DA LISTA 
  // Adiciona uma aresta da origem para o  destino
	struct ListaDeVizinhos* NovoElemento = (struct ListaDeVizinhos*)malloc(sizeof(struct ListaDeVizinhos));
	NovoElemento->vertice = destino;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[origem];
	Grafo->ListaAdj[origem] = NovoElemento;

	// Adiciona uma aresta do destino para a origem
	NovoElemento = (struct ListaDeVizinhos*)malloc(sizeof(struct ListaDeVizinhos));
	NovoElemento->vertice = origem;
	NovoElemento->prox = NULL;

	NovoElemento->prox = Grafo->ListaAdj[destino];
	Grafo->ListaAdj[destino] = NovoElemento;
}

void MostrarGrafo(struct Grafo* Grafo)
{
	int v;
	for (v = 0; v < Grafo->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = Grafo->ListaAdj[v];
		printf("\n Lista de adjacencias do vertice %d:\n ", v);
		while (ElementoVarredura != NULL)
		{
			printf("%d -> ", ElementoVarredura->vertice);
			ElementoVarredura = ElementoVarredura->prox;
		}
		printf("\n");
	}
}

void push(int y)
{ //função push, coloca um elemento na fila
	Fila* NovoElemento;
	NovoElemento = (struct Fila*)malloc(sizeof(struct Fila));
	NovoElemento->vertice = y;
	NovoElemento->prox = NULL;

	if (top == NULL)
	{			
		top = NovoElemento;	
	}
	else{	
	
		Fila* elemento_varredura;
		elemento_varredura = (struct Fila*)malloc(sizeof(struct Fila));

		elemento_varredura = top;
		while (elemento_varredura->prox != NULL) {
			elemento_varredura = elemento_varredura->prox;
		}
		
		elemento_varredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}

void pop()
{ //função pop, remove um elemento na fila

	if (top != NULL){
		
		Fila* NovoElemento;
		NovoElemento = (struct Fila*)malloc(sizeof(struct Fila));

		NovoElemento = top;
		top = top->prox;
		free(NovoElemento);
		
	}
}
	//busca_largura(GrafoTeste, origem, marcado);
void busca_largura(Grafo* Vizinhos, int v, int marcado[]) {
	if (top != NULL && marcado[v] == 0) {

		int w;
		ListaDeVizinhos* ElementoVarredura;
		ElementoVarredura = (struct ListaDeVizinhos*)malloc(sizeof(struct ListaDeVizinhos));
		
		printf("V%d\t", v);

		marcado[v] = 1;
		
		ElementoVarredura = Vizinhos->ListaAdj[v];
	
		while (ElementoVarredura != NULL) {
			w = ElementoVarredura->vertice;
			if (marcado[w] != 1)
			{
				push(w);
			}

			ElementoVarredura = ElementoVarredura->prox;
		}

		
	}
	
	pop(); //desenfileira

	if (top != NULL) {
		busca_largura(Vizinhos, top->vertice, marcado);
	}

}