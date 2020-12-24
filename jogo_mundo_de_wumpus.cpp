/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
MUNDO DE WUMPUS:O mundo de Wumpus é um jogo/problema onde você é um jogador que está dentro de uma caverna. Este jogador possui uma visão limitada ao seu redor.Dentro da caverna temos buracos, um tesouro, um monstro (Wumpus) e uma saída.  Objetivo do Jogo:O objetivo do jogo é coletar o tesouro e depois achar a saída da caverna. Regras do Jogo:Ao redor do buraco existe uma brisa. A brisa ajuda a identificar buracos próximos;  Se o jogador cair em um buraco, ele morre; O monstro exala um fedor ao seu redor;Se o monstro pegar o jogador, ele morre;O jogador pode se mover somente para um de seus espaços vizinhos; Quando o jogador já tiver pego o tesouro e for em direção a saída o Wumpus começa a se  mover.  Após  cada  jogada  do  jogador,  o  Wumpus  faz  um  movimento.  O  movimento  do  Wumpus acontece sempre buscando o MENOR CAMINHO em direção ao jogador.

Desenvolva um MUNDO DE WUMPUS  com as seguintes características: •Crie um tabuleiro para o jogo com dimensão 10x10. Para montar o tabuleiro utilize um grafo e  armazene  a  LISTA  DE  ADJACÊNCIAS  deste  grafo.  Utilizem  o  código  de  sala  de  aula  do  Github; •Posicione, aleatoriamente ou não (fica a seu critério), o jogador dentro do grafo, o monstro, o tesouro e pelo menos 2 poços. Não esqueça de inserir a brisa e o fedor quando necessárioao redor; •Lembre-se! A caverna é escura! Então o jogador consegue enxergar somente o que está ao seu  redor.  Ou  seja,  enxerga  somente os  vizinhos  daquele  vértice  do  grafo  a  qual  ele  está  colocado;Cada requisito do projeto abaixo vale 20% da nota total da atividade.1.(30%  da  nota)  Crie  um  grafo  e  mantenha  sua  lista  de  adjacências.  Dentro  de  cada  vértice  do  grafo  você  deve  manter  atualizado  o  objeto  que  está  ali  (poço,  monstro,  jogador,  etc.).  Por exemplo,  se  um  poço  estiver  naquele  vértice,  armazene  esta  informação. Utilize  LISTA  DE  ADJACÊNCIAS;2.(20% da nota) Crie a movimentação do jogador pelo grafo. 3.(20%  da  nota)  Crie  a  movimentação  do  Wumpus.  O  monstro  não  precisa  se  mover  toda  a  rodada  (gere  uma  probabilidade  dele  se  mover).  Caso  ele  se  mova,  o  monstro  sempre  se  movimentará depois do jogador e vai em direção aquele jogador pelo MENOR CAMINHO. Utilize o algoritmo de Djikstra para este menor caminho.4.(30% da nota) Interface para o usuário. Gere uma interface que mostre ao usuário os possíveis movimentos que ele pode fazer. Ou seja, mostre na tela o que tem em cada um dos vizinhos do vértice que seu jogador está posicionado. 
*/



#include <stdio.h>
#include <stdlib.h> //rand() e srand()
#include <time.h> //time()

	//numero de vertices do grafo
#define MAX 100 
	//infinito
#define INFINITY 32766


struct ListaDeVizinhos
{
	int vertice;
	bool brisa = false;
	bool buraco = false;
	bool fedor = false;
	bool jogador = false;
	bool monstro = false;
	bool saida = false;
	bool tesouro = false;
	ListaDeVizinhos* prox;
};

struct Grafo
{
	int TotalVertices;
	struct ListaDeVizinhos** ListaAdj; //Será um ponteiro para um vetor do tamanho do numero de vértices
									   //alocado dinamicamente, por isso o **
};

struct Grafo* CriarGrafo(int vertices);
void AdicionarAresta(struct Grafo* Grafo, int origem, int destino);
void inicializar_estrutura(struct Grafo* grafof);
void atribuir_objetos(struct Grafo* grafof,
	int verticef,
	bool brisaf,
	bool buracof,
	bool fedorf,
	bool jogadorf,
	bool monstrof,
	bool saidaf,
	bool tesourof);
int posicionar_jogador(struct Grafo* grafof, int origem, int destino, bool tesouro);
int exibir_caminhos(struct Grafo* grafof, int posicao_do_jogador);
int movimentar(struct Grafo* grafof, int origem, int destino, bool tesouro);
int checar_jogo(struct Grafo* grafof, int posicao);
bool encontrou_tesouro(struct Grafo* grafof, int posicao);
int posicionar_monstro(struct Grafo* grafof, int origem, int destino);
int posicionar_monstro(struct Grafo* grafof, int origem, int destino);
int dijkstra(struct Grafo* Grafo, int VerticeOrigem, int posicao_do_monstrof);



int main()
{
	int posicao_jogador = 70;
	int proximo_passo = -1;
	int quantos_caminhos = -1;
	bool com_tesouro = false;
	int posicao_monstro = 52;
	int sorteio = -1;
	Grafo* caverna = CriarGrafo(100);
	
	AdicionarAresta(caverna, 0,10);
	AdicionarAresta(caverna, 0, 1);
	AdicionarAresta(caverna, 1, 11);
	AdicionarAresta(caverna, 1, 2);
	AdicionarAresta(caverna, 2, 12);
	AdicionarAresta(caverna, 2, 3);
	AdicionarAresta(caverna, 3, 13);
	AdicionarAresta(caverna, 3, 4);
	AdicionarAresta(caverna, 4, 14);
	AdicionarAresta(caverna, 4, 5);
	AdicionarAresta(caverna, 5, 15);
	AdicionarAresta(caverna, 5, 6);
	AdicionarAresta(caverna, 6, 16);
	AdicionarAresta(caverna, 6, 7);
	AdicionarAresta(caverna, 7, 17);
	AdicionarAresta(caverna, 7, 8);
	AdicionarAresta(caverna, 8, 18);
	AdicionarAresta(caverna, 8, 9);
	AdicionarAresta(caverna, 9, 19);
	AdicionarAresta(caverna, 10, 20);
	AdicionarAresta(caverna, 10, 11);
	AdicionarAresta(caverna, 11, 21);
	AdicionarAresta(caverna, 11, 12);
	AdicionarAresta(caverna, 12, 22);
	AdicionarAresta(caverna, 12, 13);
	AdicionarAresta(caverna, 13, 23);
	AdicionarAresta(caverna, 13, 14);
	AdicionarAresta(caverna, 14, 24);
	AdicionarAresta(caverna, 14, 15);
	AdicionarAresta(caverna, 15, 25);
	AdicionarAresta(caverna, 15, 16);
	AdicionarAresta(caverna, 16, 26);
	AdicionarAresta(caverna, 16, 17);
	AdicionarAresta(caverna, 17, 27);
	AdicionarAresta(caverna, 17, 18);
	AdicionarAresta(caverna, 18, 28);
	AdicionarAresta(caverna, 18, 19);
	AdicionarAresta(caverna, 19, 29);
	AdicionarAresta(caverna, 20, 30);
	AdicionarAresta(caverna, 20, 21);
	AdicionarAresta(caverna, 21, 31);
	AdicionarAresta(caverna, 21, 22);
	AdicionarAresta(caverna, 22, 32);
	AdicionarAresta(caverna, 22, 23);
	AdicionarAresta(caverna, 23, 33);
	AdicionarAresta(caverna, 23, 24);
	AdicionarAresta(caverna, 24, 34);
	AdicionarAresta(caverna, 24, 25);
	AdicionarAresta(caverna, 25, 35);
	AdicionarAresta(caverna, 25, 26);
	AdicionarAresta(caverna, 26, 36);
	AdicionarAresta(caverna, 26, 27);
	AdicionarAresta(caverna, 27, 37);
	AdicionarAresta(caverna, 27, 28);
	AdicionarAresta(caverna, 28, 38);
	AdicionarAresta(caverna, 28, 29);
	AdicionarAresta(caverna, 29, 39);
	AdicionarAresta(caverna, 30, 40);
	AdicionarAresta(caverna, 30, 31);
	AdicionarAresta(caverna, 31, 41);
	AdicionarAresta(caverna, 31, 32);
	AdicionarAresta(caverna, 32, 42);
	AdicionarAresta(caverna, 32, 33);
	AdicionarAresta(caverna, 33, 43);
	AdicionarAresta(caverna, 33, 34);
	AdicionarAresta(caverna, 34, 44);
	AdicionarAresta(caverna, 34, 35);
	AdicionarAresta(caverna, 35, 45);
	AdicionarAresta(caverna, 35, 36);
	AdicionarAresta(caverna, 36, 46);
	AdicionarAresta(caverna, 36, 37);
	AdicionarAresta(caverna, 37, 47);
	AdicionarAresta(caverna, 37, 38);
	AdicionarAresta(caverna, 38, 48);
	AdicionarAresta(caverna, 38, 39);
	AdicionarAresta(caverna, 39, 49);
	AdicionarAresta(caverna, 40, 50);
	AdicionarAresta(caverna, 40, 41);
	AdicionarAresta(caverna, 41, 51);
	AdicionarAresta(caverna, 41, 42);
	AdicionarAresta(caverna, 42, 52);
	AdicionarAresta(caverna, 42, 43);
	AdicionarAresta(caverna, 43, 53);
	AdicionarAresta(caverna, 43, 44);
	AdicionarAresta(caverna, 44, 54);
	AdicionarAresta(caverna, 44, 45);
	AdicionarAresta(caverna, 45, 55);
	AdicionarAresta(caverna, 45, 46);
	AdicionarAresta(caverna, 46, 56);
	AdicionarAresta(caverna, 46, 47);
	AdicionarAresta(caverna, 47, 57);
	AdicionarAresta(caverna, 47, 48);
	AdicionarAresta(caverna, 48, 58);
	AdicionarAresta(caverna, 48, 49);
	AdicionarAresta(caverna, 49, 59);
	AdicionarAresta(caverna, 50, 60);
	AdicionarAresta(caverna, 50, 51);
	AdicionarAresta(caverna, 51, 61);
	AdicionarAresta(caverna, 51, 52);
	AdicionarAresta(caverna, 52, 62);
	AdicionarAresta(caverna, 52, 53);
	AdicionarAresta(caverna, 53, 63);
	AdicionarAresta(caverna, 53, 54);
	AdicionarAresta(caverna, 54, 64);
	AdicionarAresta(caverna, 54, 55);
	AdicionarAresta(caverna, 55, 65);
	AdicionarAresta(caverna, 55, 56);
	AdicionarAresta(caverna, 56, 66);
	AdicionarAresta(caverna, 56, 57);
	AdicionarAresta(caverna, 57, 67);
	AdicionarAresta(caverna, 57, 58);
	AdicionarAresta(caverna, 58, 68);
	AdicionarAresta(caverna, 58, 59);
	AdicionarAresta(caverna, 59, 69);
	AdicionarAresta(caverna, 60, 70);
	AdicionarAresta(caverna, 60, 61);
	AdicionarAresta(caverna, 61, 71);
	AdicionarAresta(caverna, 61, 62);
	AdicionarAresta(caverna, 62, 72);
	AdicionarAresta(caverna, 62, 63);
	AdicionarAresta(caverna, 63, 73);
	AdicionarAresta(caverna, 63, 64);
	AdicionarAresta(caverna, 64, 74);
	AdicionarAresta(caverna, 64, 65);
	AdicionarAresta(caverna, 65, 75);
	AdicionarAresta(caverna, 65, 66);
	AdicionarAresta(caverna, 66, 76);
	AdicionarAresta(caverna, 66, 67);
	AdicionarAresta(caverna, 67, 77);
	AdicionarAresta(caverna, 67, 68);
	AdicionarAresta(caverna, 68, 78);
	AdicionarAresta(caverna, 68, 69);
	AdicionarAresta(caverna, 69, 79);
	AdicionarAresta(caverna, 70, 80);
	AdicionarAresta(caverna, 70, 71);
	AdicionarAresta(caverna, 71, 81);
	AdicionarAresta(caverna, 71, 72);
	AdicionarAresta(caverna, 72, 82);
	AdicionarAresta(caverna, 72, 73);
	AdicionarAresta(caverna, 73, 83);
	AdicionarAresta(caverna, 73, 74);
	AdicionarAresta(caverna, 74, 84);
	AdicionarAresta(caverna, 74, 75);
	AdicionarAresta(caverna, 75, 85);
	AdicionarAresta(caverna, 75, 76);
	AdicionarAresta(caverna, 76, 86);
	AdicionarAresta(caverna, 76, 77);
	AdicionarAresta(caverna, 77, 87);
	AdicionarAresta(caverna, 77, 78);
	AdicionarAresta(caverna, 78, 88);
	AdicionarAresta(caverna, 78, 79);
	AdicionarAresta(caverna, 79, 89);
	AdicionarAresta(caverna, 80, 90);
	AdicionarAresta(caverna, 80, 81);
	AdicionarAresta(caverna, 81, 91);
	AdicionarAresta(caverna, 81, 82);
	AdicionarAresta(caverna, 82, 92);
	AdicionarAresta(caverna, 82, 83);
	AdicionarAresta(caverna, 83, 93);
	AdicionarAresta(caverna, 83, 84);
	AdicionarAresta(caverna, 84, 94);
	AdicionarAresta(caverna, 84, 85);
	AdicionarAresta(caverna, 85, 95);
	AdicionarAresta(caverna, 85, 86);
	AdicionarAresta(caverna, 86, 96);
	AdicionarAresta(caverna, 86, 87);
	AdicionarAresta(caverna, 87, 97);
	AdicionarAresta(caverna, 87, 88);
	AdicionarAresta(caverna, 88, 98);
	AdicionarAresta(caverna, 88, 89);
	AdicionarAresta(caverna, 89, 99);
	AdicionarAresta(caverna, 90, 91);
	AdicionarAresta(caverna, 91, 92);
	AdicionarAresta(caverna, 92, 93);
	AdicionarAresta(caverna, 93, 94);
	AdicionarAresta(caverna, 94, 95);
	AdicionarAresta(caverna, 95, 96);
	AdicionarAresta(caverna, 96, 97);
	AdicionarAresta(caverna, 97, 98);
	AdicionarAresta(caverna, 98, 99);

	inicializar_estrutura(caverna);
	
	//struct Grafo* Grafof,	int verticef, bool brisaf, bool buracof, bool fedorf, bool jogadorf, bool monstrof, bool saidaf, bool tesourof
	atribuir_objetos(caverna, 70, false, false, false, true, false, false, false); //jogador
	atribuir_objetos(caverna, 52, false, false, false, false, true, false, false); //monstro
	atribuir_objetos(caverna, 6, false, false, false, false, false, true, false); //saida
	atribuir_objetos(caverna, 67, true, false, false, false, false, false, true); //tesouro brisa
	//brisa
	atribuir_objetos(caverna, 83, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 81, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 72, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 92, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 58, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 47, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 56, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 24, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 44, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 33, true, false, false, false, false, false, false);
	atribuir_objetos(caverna, 35, true, false, false, false, false, false, false);
	//buraco
	atribuir_objetos(caverna, 82, false, true, false, false, false, false, false); 
	atribuir_objetos(caverna, 57, false, true, false, false, false, false, false);
	atribuir_objetos(caverna, 34, false, true, false, false, false, false, false);
	//fedor
	atribuir_objetos(caverna, 53, false, false, true, false, false, false, false);
	atribuir_objetos(caverna, 51, false, false, true, false, false, false, false);
	atribuir_objetos(caverna, 42, false, false, true, false, false, false, false);
	atribuir_objetos(caverna, 62, false, false, true, false, false, false, false);



	printf("\nbem vindo ao mundo de wumpus,\nencontre o tesouro e saia da caverna\ntudo isso antes do monstro wumpus te encontrar,\no monstro pode ser detectado pelo fedor ao seu redor,\nnao caia nos buracos\nos buracos possuem uma brisa ao seu redor,\nporem nao tem como enxerga-los.\n");

	while (true) {
		quantos_caminhos = exibir_caminhos(caverna, posicao_jogador);
		
		do{
			printf("\ndigite o numero de qual caminho deseja seguir:\n");
			scanf_s("%i", &proximo_passo);

			if (proximo_passo < 0 || proximo_passo > quantos_caminhos) {
				printf("\ncaminho invalido,\ndigite o caminho novamente\no caminho escolhido deve estar entre 0 e %i\n", quantos_caminhos);
			}

		} while (proximo_passo < 0 || proximo_passo > quantos_caminhos);
		
		posicao_jogador = movimentar(caverna, posicao_jogador, proximo_passo, com_tesouro);

		com_tesouro = encontrou_tesouro(caverna, posicao_jogador);

		srand(time(NULL));

		int sorteio = ((rand() % 5) + 1);

		if (com_tesouro == true && sorteio > 2) {
			posicao_monstro = posicionar_monstro(caverna, posicao_monstro, dijkstra(caverna, posicao_jogador, posicao_monstro));
		}

		if (checar_jogo(caverna, posicao_jogador) != 0) {
			break;
		}

	}

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


void inicializar_estrutura(struct Grafo* grafof) {
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];

		while (ElementoVarredura != NULL)
		{
			ElementoVarredura->brisa = false;
			ElementoVarredura->buraco = false;
			ElementoVarredura->fedor = false;
			ElementoVarredura->jogador = false;
			ElementoVarredura->monstro = false;
			ElementoVarredura->saida = false;
			ElementoVarredura->tesouro = false;

			ElementoVarredura = ElementoVarredura->prox;
		}
	}
}

void atribuir_objetos(struct Grafo* grafof, 
int verticef, 
bool brisaf, 
bool buracof, 
bool fedorf, 
bool jogadorf, 
bool monstrof, 
bool saidaf, 
bool tesourof){

	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL) {
			if (ElementoVarredura->vertice == verticef) {
				ElementoVarredura->brisa = brisaf;
				ElementoVarredura->buraco = buracof;
				ElementoVarredura->fedor = fedorf;
				ElementoVarredura->jogador = jogadorf;
				ElementoVarredura->monstro = monstrof;
				ElementoVarredura->saida = saidaf;
				ElementoVarredura->tesouro = tesourof;
			}

			ElementoVarredura = ElementoVarredura->prox;
		}
	}
}

int posicionar_jogador(struct Grafo* grafof, int origem, int destino, bool tesouro) {
		//tira o jogador de um ponto e coloca em outro
		//se estiver com o tesouro movimenta o tesouro junto

		//remove jogador da posicao de origem
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL) {
			if (ElementoVarredura->vertice == origem) {
				ElementoVarredura->jogador = false;
				if (tesouro == true) {
					ElementoVarredura->tesouro = false;
				}
			}

			ElementoVarredura = ElementoVarredura->prox;
		}
	}

		//move o jogador para posicao destino
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL) {
			if (ElementoVarredura->vertice == destino) {
				ElementoVarredura->jogador = true;
				if (tesouro == true) {
					ElementoVarredura->tesouro = true;
				}
			}

			ElementoVarredura = ElementoVarredura->prox;
		}
	}

	return destino;
}

int exibir_caminhos(struct Grafo* grafof, int posicao_do_jogador) {
		//mostra o que pode ser visto nas adjacencias
	int caminho = 0;

	printf("\ncaminhos a vista:\n");

		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[posicao_do_jogador];
		while (ElementoVarredura != NULL){	

			printf("\n%i.\n", caminho);
			if (ElementoVarredura->brisa == false
			&& ElementoVarredura->fedor == false
			&& ElementoVarredura->monstro == false
			&& ElementoVarredura->saida == false
			&& ElementoVarredura->tesouro == false){
				printf("aparentemente nada por ali.\n");
			}
			else {
				if (ElementoVarredura->brisa == true) {
					printf("brisa.\n");
				}

				if (ElementoVarredura->fedor == true) {
					printf("fedor.\n");
				}

				if (ElementoVarredura->monstro == true) {
					printf("monstro.\n");
				}

				if (ElementoVarredura->saida == true) {
					printf("saida.\n");
				}

				if (ElementoVarredura->tesouro == true) {
					printf("tesouro.\n");
				}
			}

			ElementoVarredura = ElementoVarredura->prox;
			caminho = caminho + 1;
		}
	
	return (caminho - 1);
}

int movimentar(struct Grafo* grafof, int origem, int destino, bool tesouro) {
		//movimenta o jogador de acordo com a escolha do menu
	struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[origem];
	int adjacencia = 0;

	while (adjacencia < destino){
		ElementoVarredura = ElementoVarredura->prox;
		adjacencia = adjacencia + 1;
	}

	return posicionar_jogador(grafof, origem, ElementoVarredura->vertice, tesouro);
}

int checar_jogo(struct Grafo* grafof, int posicao) {
		//checa se o jogo continua ou acabou

	struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[0];

		//faz a varredura ate encontrar o vertice da posicao do jogador
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL && ElementoVarredura->vertice != posicao)
		{	
			ElementoVarredura = ElementoVarredura->prox;
		}

		if (ElementoVarredura != NULL && ElementoVarredura->vertice == posicao) {
			break;
		}
	}
		//checa os criterios de fim de jogo
	if (ElementoVarredura->monstro == true) {
		printf("\no monstro wumpus te pegou!\nfim de jogo.\n");
		return 1;
	}
	else if (ElementoVarredura->buraco == true) {
		printf("\ntu caiu no buraco!\nfim de jogo.\n");
		return 2;

	}
	else if (ElementoVarredura->saida == true && ElementoVarredura->tesouro == true) {
		printf("\nvitoria merecida,\ncomemore a conquista desse tesouro!\nfim de jogo.\n");
		return 3;
	}
	else {
		printf("\nnada demais por aqui, continue explorando a caverna.\n");
		return 0;
	}

}

bool encontrou_tesouro(struct Grafo* grafof, int posicao) {
	//verifica se na posicao atual esta o tesouro e marca como encontrado caso positivo
	struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[0];

	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL && ElementoVarredura->vertice != posicao)
		{
			ElementoVarredura = ElementoVarredura->prox;
		}

		if (ElementoVarredura != NULL && ElementoVarredura->vertice == posicao) {
			break;
		}
	}
	
	if (ElementoVarredura->tesouro == true) {
		return true;
	} else {
		return false;
	}
	
}


int posicionar_monstro(struct Grafo* grafof, int origem, int destino) {
		//move o monstro e atualiza as novas adjacencias da posicao com fedor
	
	int fedores[4] = {-1, -1, -1, -1};
	int iteracao;
	
		//remove o monstro da posicao de origem
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL) {
			if (ElementoVarredura->vertice == origem) {
				ElementoVarredura->monstro = false;
			}

			ElementoVarredura = ElementoVarredura->prox;
		}
	}

		//atualiza a posicao do monstro
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL) {
			if (ElementoVarredura->vertice == destino) {
				ElementoVarredura->monstro = true;
			}

			ElementoVarredura = ElementoVarredura->prox;
		}
	}

		//desmarcar o fedor da posicao de origem
	for (int v = 0; v < grafof->TotalVertices; v++)
	{
		struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
		while (ElementoVarredura != NULL) {
			if (ElementoVarredura->fedor == true) {
				ElementoVarredura->fedor = false;
			}

			ElementoVarredura = ElementoVarredura->prox;
		}
	}

		//obter adjacencias do monstro
	struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[destino];
	iteracao = 0;
	while (ElementoVarredura != NULL) {
		fedores[iteracao] = ElementoVarredura->vertice;
		iteracao = iteracao + 1;
		ElementoVarredura = ElementoVarredura->prox;
	}

		//aplicar o fedor nas adjacencias do monstro
	for(iteracao = 0; iteracao < 4; iteracao = iteracao + 1){
		if (fedores[iteracao] == -1) {
			continue;
		}

		for (int v = 0; v < grafof->TotalVertices; v++)
		{
			struct ListaDeVizinhos* ElementoVarredura = grafof->ListaAdj[v];
			while (ElementoVarredura != NULL) {
				if (ElementoVarredura->vertice == fedores[iteracao]) {
					ElementoVarredura->fedor = true;
				}

				ElementoVarredura = ElementoVarredura->prox;
			}
		}
	}

	return destino;

}


int dijkstra(struct Grafo* Grafo, int VerticeOrigem, int posicao_do_monstrof)
{

	int Distancia[MAX], Predecessor[MAX], Visitados[MAX];
	int TotalVisitados, minDistancia, ProxVertice, i, j;

	for (i = 0; i < Grafo->TotalVertices; i++)
	{
		Distancia[i] = INFINITY;
		Predecessor[i] = VerticeOrigem;
		Visitados[i] = 0;
	}
	Distancia[VerticeOrigem] = 0;
	TotalVisitados = 0;

	struct ListaDeVizinhos* ElementoVarredura = Grafo->ListaAdj[VerticeOrigem];
	while (TotalVisitados < (Grafo->TotalVertices - 1))
	{
		minDistancia = INFINITY;
		// ProxVertice é o nó com a menor distância
		for (i = 0; i < Grafo->TotalVertices; i++)
		{
			if ((Distancia[i] < minDistancia) && (Visitados[i] == 0))
			{
				minDistancia = Distancia[i];
				ProxVertice = i;
			}
		}
		//Verifica se existe um melhor caminho pelo ProxVertice
		Visitados[ProxVertice] = 1;
		ElementoVarredura = Grafo->ListaAdj[ProxVertice];
		while (ElementoVarredura != NULL)
		{
			if (Visitados[ElementoVarredura->vertice] == 0 && ElementoVarredura->buraco == false)
			{
				if ((minDistancia + 1) < Distancia[ElementoVarredura->vertice])
				{
					Distancia[ElementoVarredura->vertice] = (minDistancia + 1);
					Predecessor[ElementoVarredura->vertice] = ProxVertice;
				}
			}
			ElementoVarredura = ElementoVarredura->prox;
		}
		TotalVisitados++;
	}
	
	return Predecessor[posicao_do_monstrof];
}