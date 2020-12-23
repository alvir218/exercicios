//programador: allan stuart virmond
//programador: daniel guergolet baptistone
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: jogo de estrategia em tempo real para ate 6 jogadores






/******************************************************************************

age of cities v0.4.9

Alunos
Allan Stuart Virmond 2379525
Daniel Guergolet Baptistone 2012368

Professor
Winston Fung

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //////clock_t
#include <stdbool.h>
#include <locale.h> //////setlocale

#define empadrao "\033[0m"
#define emvermelho "\033[31m"

//////variaveis globais;

struct mapa {
	int madeira;
	int pedra;
	int alimento;
	int ocupadoJogador; // mapa ocupado por 

};
struct posicoes {
	int posicaox; // 0 a 19
	int posicaoy; // de 0 a 24
};
struct recursos_jogadores
{
	int casas = 1;
	int construindoCasa = 0; //turnos falta terminar
	int construindoCasaTurnoAguardado = 0;
	int construindoQuartel = 0; //turnos falat terminar
	int construindoQuartelTurnoAguardado = 0;
	int construindoMuralha = 0;
	int construindoMuralhaTurnoAguardado = 0;
	int construindoTemplo = 0;
	int construindoTemploTurnoAguardado = 0;

	long int habitantes = 10;
	int posicaoxIni = NULL; //posicao inicial até 20
	int posicaoyIni = NULL; //posicao inicial até 25
	long int madeira = 0;
	long int pedra = 0;
	long int alimento = 10*10;
	int habitantesAlimentos = 1; // quantos habitantes destinados a extrair alimentos 
	int habitantesMadeira = 0; // quanto habitantes extraindo madeira
	int habitantesPedra = 0; // quantos habitantes destinados a extrair pedra
	int habitantesOcupados = 0;
	int moverSalvox = NULL;
	int moverSalvoy = NULL;

	//////substituido por habitantesOcupados;
	//////int habitantesConstruindo = 0;
	//////se manter essa estrutura tem de ordenar coleta em cada turno;
	//////optado por coleta automatica ate segunda ordem;
	/*
	int alimentoColetando;
	int madeiraColetando;
	int pedraColetando;
	*/

	int cidades = 0; //tem 10 posicoes
	int posicoesConquistada = 0; // quantidade posicao consquistada no mapa ou numero de posicoes da cidade

	//////melhor solucao NULL;
	//////valores fora do alcance do mapa estoura a memoria
	//////nao pode ser inicializado pois adiciona a lista de posicoes conquistada;
	//////struct posicoes posicoes[500] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // pode ter ate 500 posicoes de 0 a 499
	struct posicoes posicoes[500]{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };

	int templo = 0;
	int muralha = 0;
	int quartel = 0;

	////// aviso de multiplicacao podendo estourar a memoria int de 4 bytes convertendo para double;
	//////int soldadoCidade; //quantidade
	//////int soldadoGuerra;
	double soldadoCidade = 0; //quantidade
	double soldadoGuerra = 0;


	int foraJogo = 1;		//1 - ainda jogando ; 0 fora do jogo
	int numeroJogador = 0; // numero do jogador
};

int numeroJogadores = 0;

//////struct recursos_jogadores recursos[7]; //máximo numero de jogadores 100 //////maximo numero de jogadores 6 o setimo nao pode existir;
struct recursos_jogadores recursos[6]; //máximo numero de jogadores 100 //////maximo numero de jogadores 6 teste;
struct mapa mapa[20][25]; // criação do matrix do mapa



//////funcoes

// baixa os recursos se houver disponibilidade
//baixo tudo solicitado ou somente o que tem na area
int baixarRecursosMadeira(struct mapa* mapa, int saldoBaixar)//passando por referencia
{
	int saldoRestante = 0;

	if ((*mapa).madeira >= saldoBaixar)
	{
		(*mapa).madeira = (*mapa).madeira - saldoBaixar;
		return 0;
	}
	else
	{
		saldoRestante = (*mapa).madeira;
		(*mapa).madeira = 0; // coletou tudo que o mapa ainda tinha
		return saldoRestante;
	}

}
int baixarRecursosPedra(struct mapa* mapa, int saldoBaixar)
{
	int saldoRestante = 0;
	if ((*mapa).pedra >= saldoBaixar)
	{
		(*mapa).pedra = (*mapa).pedra - saldoBaixar;
		return 0;
	}
	else
	{
		saldoRestante = (*mapa).pedra;
		(*mapa).pedra = 0; // coletou tudo que o mapa ainda tinha
		return saldoRestante; // mas ainda faltou
	}

}
void preencherMapa(struct mapa* mapa)
// preenchimento do mapa com recursos aleatório de 
{
	(*mapa).madeira = 400 + (rand() % 1600); //randomizando de 400 a 2000
	(*mapa).pedra = 400 + (rand() % 1600);
	//(*mapa).alimento = rand() %100;
	(*mapa).ocupadoJogador = -1;

}
void mostrarRecursos(struct recursos_jogadores recursos)
{
	int i = 0;
	//////nao tem variavel contando quantas casas estao sendo construidas
	//////printf("\n Tem %i casas e estão sendo construidas mais %i \t ", recursos.casas, recursos.construindoCasa);
	system("cls");
	printf(" Tem %i casas. \n", recursos.casas);
	if (recursos.construindoQuartel < 15 && recursos.construindoQuartel > 0 && recursos.quartel == 0) {
		printf("\n\n Construindo quartel faltando %i turno(s) para terminar. \n", 15 - recursos.construindoQuartel);
	}
	if (recursos.quartel == 0) {
		printf("\n\n Não possui quartel. \n");
	}
	if (recursos.quartel == 1) {
		printf("\n\n Possui quartel. \n");
	}

	if (recursos.construindoTemplo < 15 && recursos.construindoTemplo > 0 && recursos.templo == 0) {
		printf("\n\n Construindo o templo faltando %i turno(s) para terminar. \n", 15 - recursos.construindoTemplo);
	}
	if (recursos.templo == 1) {
		printf("\n\n possui templo. \n");
	}
	if (recursos.templo == 0) {
		printf("\n\n Não possui templo. \n");
	}

	if (recursos.construindoMuralha < 35 && recursos.construindoMuralha > 0 && recursos.muralha == 0) {
		printf("\n\n Construindo muralha faltando %i turno(s) para terminar. \n", 35 - recursos.construindoMuralha);
	}
	if (recursos.muralha == 1) {
		printf("\n\n possui muralha. \n");
	}
	if (recursos.muralha == 0) {
		printf("\n\n Não possui muralha. \n");
	}


	printf("\n\n possui em estoque %i em madeira. \n", recursos.madeira);

	printf("\n\n possui em estoque %i em pedra. \n", recursos.pedra);

	printf("\n\n possui em estoque %i em alimento. \n", recursos.alimento);

	printf("\n\n possui %i habitantes. \n", recursos.habitantes);

	printf("\n\n %i habitantes esta(ão) ocioso(s) \n", recursos.habitantes - recursos.habitantesOcupados);

	printf("\n\n Tem %.0lf soldados na cidade e %.0lf em guerra. \n", recursos.soldadoCidade, recursos.soldadoGuerra);

	printf("\n\n posição inicial (%i,%i) \n", recursos.posicaoxIni, recursos.posicaoyIni);

	//////mostra posicao (0,0) para jogador 1
	/*
	if (recursos.posicoesConquistada > 1) {
		printf("\n\n possui %i posições conquistadas são elas: \n\n", recursos.posicoesConquistada);
		for (i = 0; i <= recursos.posicoesConquistada; ++i)
		{
			printf("(%i,%i) \t", recursos.posicoes[i].posicaox, recursos.posicoes[i].posicaoy);
		}
	}
	*/

	printf("\n\n Você possui as seguintes posições ocupadas: \n\n");

	for (int forposicoesx = 0; forposicoesx < 20; forposicoesx = forposicoesx + 1) {
		for (int forposicoesy = 0; forposicoesy < 25; forposicoesy = forposicoesy + 1) {
			if (mapa[forposicoesx][forposicoesy].ocupadoJogador == recursos.numeroJogador) {
				printf("(%i , %i)\t", forposicoesx, forposicoesy);
			}
		}
	}

	printf("\n\n\n");
	system("pause");


}
void inicializandoRecursos(struct recursos_jogadores* recursos, int jogadores)
{
	(*recursos).foraJogo = 1;
	(*recursos).habitantes = 10;
	(*recursos).posicaoxIni = (rand() % 19); //0 até 19
	(*recursos).posicaoyIni = (rand() % 24); //0 até 24
	(*recursos).posicoes[0].posicaox = (*recursos).posicaoxIni;
	(*recursos).posicoes[0].posicaoy = (*recursos).posicaoyIni;

	(*recursos).madeira = 0;
	(*recursos).pedra = 0;
	// PARA NÃO MORRER NA PRIMEIRA JOGADA, para todo mundo ficar vivo até o fim da primeira rodada
	(*recursos).alimento = jogadores * 10;
	(*recursos).cidades = 0;
	(*recursos).posicoesConquistada = 1; // sem cidade mais ganha ganha uma posição inicial posicaoxini, posicaoyini

	(*recursos).casas = 1;
	(*recursos).quartel = 0;
	(*recursos).muralha = 0;
	(*recursos).templo = 0;
	(*recursos).construindoQuartel = 0;
	(*recursos).construindoCasa = 0;
	(*recursos).construindoMuralha = 0;
	(*recursos).construindoTemplo = 0;
	(*recursos).soldadoCidade = 0;
	(*recursos).soldadoGuerra = 0;
}
// batalha na posicao da cidade o retorno é o ganhador
int batalhaPosicao(struct recursos_jogadores ataque, struct recursos_jogadores defesa)
{
	////// calculos posteriores resultam em numero real alterar para float ou double; double escolhido; tem um ponto e virgula a mais;
	//////int fatorAtaque = 0, fatorDefesa = 0; ;
	double fatorAtaque = 0, fatorDefesa = 0;
	if (ataque.soldadoGuerra == 0)
	{
		return defesa.numeroJogador;

	}
	if ((defesa.soldadoCidade + defesa.soldadoGuerra) == 0)
	{
		return ataque.numeroJogador;

	}
	fatorAtaque = ataque.soldadoGuerra * 15;
	fatorDefesa = (defesa.soldadoCidade + defesa.soldadoGuerra) * 10;

	// se tem templo a defesa aumenta 10%
	if (defesa.templo == 1)
	{
		fatorDefesa = fatorDefesa * (1.10);
	}
	//se a defesa possui muralha aumenta 25%
	if (defesa.muralha == 1)
	{
		fatorDefesa = fatorDefesa * (1.25);
	}
	//conseguiu para o ataque
	if (fatorDefesa >= fatorAtaque)
	{
		return defesa.numeroJogador;
	}
	else
	{
		return ataque.numeroJogador;
	}

}
//verifica se a posicao escolhida para mover e posicao adjacente a cidade ou posicao inicial
//para ser uma posicao adjacente basta ser o x ou y igual e o outro eixo diferente é -1 ou mais 1
bool posicaoAdjacente(struct recursos_jogadores recursos, int x, int y)
{
	int i = 0;

	for (i = 0; i <= (recursos).posicoesConquistada; ++i)
	{
		if ((recursos.posicoes[i].posicaox == x && recursos.posicoes[i].posicaoy - 1 == y) ||
			(recursos.posicoes[i].posicaoy == y && recursos.posicoes[i].posicaox - 1 == x) ||

			(recursos.posicoes[i].posicaox == x && recursos.posicoes[i].posicaoy + 1 == y) ||
			(recursos.posicoes[i].posicaoy == y && recursos.posicoes[i].posicaox + 1 == x)

			)
		{ // e adjacente
			return true;
			break;
		}
	}
	return false;
}

// true se já esta conquistado, procurar outra posicao
bool posicaoJaConquistada(struct recursos_jogadores* recursos, int x, int y)
{
	int i = 0;

	for (i = 0; i <= (*recursos).posicoesConquistada; ++i)
	{
		if ((*recursos).posicoes[i].posicaox == x && (*recursos).posicoes[i].posicaoy == y)
		{ // ja conquistou 
			return 1;
			break;
		}
	}
	return 0;
}
// posicao existe no mapa
bool pontoExiste(int x, int y)
{
	/// x vai de 0 a 19 e  y vai de 0 a 24
	//////tentar icluir [0][0]
	//////return (x >= 0 && x < 20) && (y >= 0 && y < 25);
	return (x >= 0 && x < 20) && (y >= 0 && y < 25);
}
// ocupa x posicoes ao redor do ponto
void ocuparPosicao(struct recursos_jogadores* recursos, int x, int y, int posicoes)
{
	int i = 0, j = 0, voltas;
	int xtemp = 0, ytemp = 0;
	int vencedorBatalha = 0; //vencedor quando entre na posicao de uma cidade
	voltas = 1; //numero de voltas que deu para pegar os pontos ao redor

   // vai ocupando posicoes ao redor do ponto em sentido horario
   // se nao existe vai para proximo ponto
	for (i = 1; i <= posicoes; ++voltas)
	{
		for (j = 1; j != 4 && i <= posicoes; ++j)
		{
			switch (j)
			{
			case 1:  // j == 1 diminui x, igual y

				xtemp = x - voltas;
				ytemp = y;

				break;
			case 2:  //igual x, aumenta y

				xtemp = x;
				ytemp = y + voltas;
				break;

			case 3:  // aumenta x, igual y
				xtemp = x + voltas;
				ytemp = y;
				break;

			case 4: // igual x e diminui y
				xtemp = x;
				ytemp = y - voltas;
				break;

			}


			// se verifica se a posicao existe no mapa e ja nao foi conquistada pelo jogador
			if (pontoExiste(xtemp, ytemp) && !(posicaoJaConquistada(&(*recursos), xtemp, ytemp))) {
				++i; // encontrou uma coordenada que existe
				//porem a posicao nao esta sendo ocupado por outro jogador
				if (mapa[xtemp][ytemp].ocupadoJogador == -1) { // nao ocupado
					(*recursos).posicoes[(*recursos).posicoesConquistada].posicaox = xtemp; // adicionando a posicao lista de posicoes conquistadas
					(*recursos).posicoes[(*recursos).posicoesConquistada].posicaoy = ytemp; //
					//printf( " (%i,%i)\t ", (*recursos).posicoes[(*recursos).posicoesConquistada].posicaox,(*recursos).posicoes[(*recursos).posicoesConquistada].posicaoy);	
					++(*recursos).posicoesConquistada;  //posicoes conquistada
					//////o software deve continuar considerando o jogador 0 como primeiro e 1 como segundo... etc;
					//////mapa[xtemp][ytemp].ocupadoJogador = (*recursos).numeroJogador - 1;
					mapa[xtemp][ytemp].ocupadoJogador = (*recursos).numeroJogador;
				}
				// entrou em confronto por ter a mesma posicao de outro jogador
				else
				{
					vencedorBatalha = batalhaPosicao((*recursos), recursos[mapa[xtemp][ytemp].ocupadoJogador]);
					mapa[xtemp][ytemp].ocupadoJogador = vencedorBatalha;
					printf("\n\n posição (%i, %i) conquistada na batalha pelo jogador %i \n", xtemp, ytemp, vencedorBatalha + 1);
				}

				//	printf( " (%i,%i)\t ", xtemp,ytemp);
			}


		}
	}

}
/////revisando
//passando os turnos e verificando se contruio algo 

void construindo(struct recursos_jogadores* recursos) {
	int x = 0, y = 0;

	if ((*recursos).construindoCasa > 0) {
		(*recursos).construindoCasaTurnoAguardado = (*recursos).construindoCasaTurnoAguardado + 1;
	}

	for ((*recursos).construindoCasaTurnoAguardado; (*recursos).construindoCasaTurnoAguardado > 5; (*recursos).construindoCasaTurnoAguardado = (*recursos).construindoCasaTurnoAguardado - 5) {
		(*recursos).casas = (*recursos).casas + 1;
		(*recursos).construindoCasa = (*recursos).construindoCasa - 1;
		(*recursos).habitantesOcupados = (*recursos).habitantesOcupados - 5;
	}



	if ((*recursos).construindoMuralha > 0) {
		(*recursos).construindoMuralhaTurnoAguardado = (*recursos).construindoMuralhaTurnoAguardado + 1;
	}

	for ((*recursos).construindoMuralhaTurnoAguardado; (*recursos).construindoMuralhaTurnoAguardado > 35; (*recursos).construindoMuralhaTurnoAguardado = (*recursos).construindoMuralhaTurnoAguardado - 35) {
		(*recursos).muralha = (*recursos).muralha + 1;
		(*recursos).construindoMuralha = (*recursos).construindoMuralha - 1;
		(*recursos).habitantesOcupados = (*recursos).habitantesOcupados - 5;
	}



	if ((*recursos).construindoQuartel > 0) {
		(*recursos).construindoQuartelTurnoAguardado = (*recursos).construindoQuartelTurnoAguardado + 1;
	}

	for ((*recursos).construindoQuartelTurnoAguardado; (*recursos).construindoQuartelTurnoAguardado > 15; (*recursos).construindoQuartelTurnoAguardado = (*recursos).construindoQuartelTurnoAguardado - 15) {
		(*recursos).quartel = (*recursos).quartel + 1;
		(*recursos).construindoQuartel = (*recursos).construindoQuartel - 1;
		(*recursos).habitantesOcupados = (*recursos).habitantesOcupados - 5;
	}



	if ((*recursos).construindoTemplo > 0) {
		(*recursos).construindoTemploTurnoAguardado = (*recursos).construindoTemploTurnoAguardado + 1;
	}

	for ((*recursos).construindoTemploTurnoAguardado; (*recursos).construindoTemploTurnoAguardado > 15; (*recursos).construindoTemploTurnoAguardado = (*recursos).construindoTemploTurnoAguardado - 15) {
		(*recursos).templo = (*recursos).templo + 1;
		(*recursos).construindoTemplo = (*recursos).construindoTemplo - 1;
		(*recursos).habitantesOcupados = (*recursos).habitantesOcupados - 5;
	}



	for (int forcidade = ((*recursos).casas - ((*recursos).cidades * 3)); forcidade > 3; forcidade = forcidade - 3) {

		(*recursos).cidades = (*recursos).cidades + 1;
		x = (*recursos).posicaoxIni;
		y = (*recursos).posicaoyIni;
		ocuparPosicao(&(*recursos), x, y, 10);

	}

	for (int forocupacao = ((*recursos).habitantes - ((*recursos).posicoesConquistada) * 30); forocupacao > 30; forocupacao = forocupacao - 30) {

		ocuparPosicao(&(*recursos), x, y, 1);

	}
	//////fim do construindo;
}



//////nao pode atualizar o numero de habitantes dessa maneira 
//////vai criar habitantes que morreram
//////devem ser criados habitantes conforme nascem e nao quando constroi uma habitaçao;
//////(*recursos).habitantes = (*recursos).casas * 10;


//////depreciado
//////funcional mas nao correto pois executara todo final de rodada criando posicoes e cidades desenfreadamente;
//////2a tentativa so cria cidade a primeira vez
/*
if ((*recursos).cidades == 0 && (*recursos).casas > 3) {
int forcidade = (*recursos).casas;
	for (forcidade; forcidade > 3; forcidade = forcidade - 3) {

		(*recursos).cidades = (*recursos).cidades + 1;
		x = (*recursos).posicaoxIni;
		y = (*recursos).posicaoyIni;
		ocuparPosicao(&(*recursos), x, y, 9);
	}
}
*/





//////backup de construindo
//passando os turnos e verificando se contruio algo 
/*
void construindo(struct recursos_jogadores* recursos)
{
	int x = 0, y = 0;
	//se tiver contruindo casa
	if ((*recursos).construindoCasa > 0)
	{
		--(*recursos).construindoCasa;
		//casa pronta -- minha casa minha vida para 10 hab
		if ((*recursos).construindoCasa == 0)
		{
			++(*recursos).casas;
			printf("\n\n Parabéns mais uma casa terminada. \n\n Você possui %i casas. \n", (*recursos).casas);
			if ((*recursos).casas == 1)
			{
				(*recursos).cidades = 1; // inicio da cidade e 1 casa

				x = (*recursos).posicaoxIni;
				y = (*recursos).posicaoyIni;
				ocuparPosicao(&(*recursos), x, y, 9);

				//ocupara mais 9 posicoes no mapa além da posicao inical

			}
			(*recursos).habitantes = (*recursos).habitantes + 10;
			//cada 3 casas a cidade aumenta uma posicao
			if ((*recursos).casas % 3)// divisivel por 3  -- modulo
			{
				x = (*recursos).posicoes[(*recursos).posicoesConquistada - 1].posicaox; //ultima posicao do array
				y = (*recursos).posicoes[(*recursos).posicoesConquistada - 1].posicaoy;
				ocuparPosicao(&(*recursos), x, y, 1);
			}
		}
	}

	if ((*recursos).construindoQuartel > 0)
	{
		--(*recursos).construindoQuartel;
		//quartel pronto ?
		if ((*recursos).construindoQuartel == 0)
		{
			++(*recursos).quartel;
		}
	}
	if ((*recursos).construindoMuralha > 0)
	{
		--(*recursos).construindoMuralha;
		//quartel pronto ?
		if ((*recursos).construindoMuralha == 0)
		{
			++(*recursos).muralha;
		}
	}

	if ((*recursos).construindoTemplo > 0)
	{
		--(*recursos).construindoTemplo;
		//quartel pronto ?
		if ((*recursos).construindoTemplo == 0)
		{
			++(*recursos).templo;
		}
	}
}
*/

void construirCasa(struct recursos_jogadores* recursos)
{
	(*recursos).madeira = (*recursos).madeira - 25;
	(*recursos).pedra = (*recursos).pedra - 25;
	//////(*recursos).habitantesConstruindo = (*recursos).habitantesConstruindo + 5;
	(*recursos).construindoCasa = (*recursos).construindoCasa + 1; //turno para construir //////substituido por casas a construir;
	(*recursos).habitantesOcupados = (*recursos).habitantesOcupados + 5;
}
bool podeConstruirCasa(struct recursos_jogadores recursos)
{  // 25 madeira, 25 pedra e 5 turnos
 //tem recurso suficiente
	if ((recursos.habitantes - recursos.habitantesOcupados) < 5) {
		printf("\n\n %s Falta %i habitante(s) %s\n", emvermelho, (5 - recursos.habitantes - recursos.habitantesOcupados), empadrao);
	}
	if (recursos.madeira < 25) {
		printf("\n\n %sFalta %i madeira(as) %s\n", emvermelho, (25 - recursos.madeira), empadrao);
	}
	if (recursos.pedra < 25) {
		printf("\n\n %sFalta %i pedra(as) %s\n", emvermelho, (25 - recursos.pedra), empadrao);
	}

	return (recursos.madeira >= 25 && recursos.pedra >= 25 && (recursos.habitantes - recursos.habitantesOcupados) >= 5);

}

void construirQuartel(struct recursos_jogadores* recursos)
{
	(*recursos).madeira = (*recursos).madeira - 60;
	(*recursos).pedra = (*recursos).pedra - 50;
	//////(*recursos).habitantesConstruindo = (*recursos).habitantesConstruindo + 5;
	(*recursos).habitantesOcupados = (*recursos).habitantesOcupados + 5;
	(*recursos).construindoQuartel = 15;
}
bool podeConstruirQuartel(struct recursos_jogadores recursos)
{//60 madeira 15 turnos 50 pedras
	if ((recursos.habitantes - recursos.habitantesOcupados) < 5) {
		printf("\n\n %sFalta %i habitante(s) %s\n", emvermelho, (5 - (recursos.habitantes - recursos.habitantesOcupados)), empadrao);
	}
	if (recursos.madeira < 25) {
		printf("\n\n %sFalta %i madeira(as) %s\n", emvermelho, (60 - recursos.madeira), empadrao);
	}
	if (recursos.pedra < 25) {
		printf("\n\n %sFalta %i pedra(as) %s\n", emvermelho, (50 - recursos.pedra), empadrao);
	}

	return (recursos.madeira >= 60 && recursos.pedra >= 50 && (recursos.habitantes - recursos.habitantesOcupados) >= 5);

}
void contruirMuralha(struct recursos_jogadores* recursos)
{
	(*recursos).madeira = (*recursos).madeira - 120;
	(*recursos).pedra = (*recursos).pedra - 120;
	//////(*recursos).habitantesConstruindo = (*recursos).habitantesConstruindo + 5;
	(*recursos).habitantesOcupados = (*recursos).habitantesOcupados + 5;
	(*recursos).construindoMuralha = 35;
}
bool podeConstruirMuralha(struct recursos_jogadores recursos)
{//120 madeira 120 pedras 35 turnos
	if ((recursos.habitantes - recursos.habitantesOcupados) < 5) {
		printf("\n\n %sFalta %i habitante(s) %s\n", emvermelho, 5 - (recursos.habitantes - recursos.habitantesOcupados), empadrao);
	}
	if (recursos.madeira < 25) {
		printf("\n\n %sFalta %i madeira(as) %s\n", emvermelho, (120 - recursos.madeira), empadrao);
	}
	if (recursos.pedra < 25) {
		printf("\n\n %sFalta %i pedra(as) %s\n", emvermelho, (120 - recursos.pedra), empadrao);
	}


	return (recursos.madeira >= 120 && recursos.pedra >= 120 && (recursos.habitantes - recursos.habitantesOcupados) >= 5);

}
void construirTemplo(struct recursos_jogadores* recursos)
{
	(*recursos).madeira = (*recursos).madeira - 50;
	(*recursos).pedra = (*recursos).pedra - 50;
	//////(*recursos).habitantesConstruindo = (*recursos).habitantesConstruindo + 5;
	(*recursos).habitantesOcupados = (*recursos).habitantesOcupados + 5;
	(*recursos).construindoTemplo = 15;
}
bool podeConstruirTemplo(struct recursos_jogadores recursos)
{//50 madeiras e pedras e  15 turnos
	if ((recursos.habitantes - recursos.habitantesOcupados) < 5) {
		printf("\n\n %sFalta %i habitante(s) %s\n", emvermelho, 5 - (recursos.habitantes - recursos.habitantesOcupados), empadrao);
	}
	if (recursos.madeira < 25) {
		printf("\n\n %sFalta %i madeira(as) %s\n", emvermelho, (50 - recursos.madeira), empadrao);
	}
	if (recursos.pedra < 25) {
		printf("\n\n %sFalta %i pedra(as) %s\n", emvermelho, (50 - recursos.pedra), empadrao);
	}

	return (recursos.madeira >= 50 && recursos.pedra >= 50 && (recursos.habitantes - recursos.habitantesOcupados) >= 5);
}
//////funcao substituida por tempoDaPartida;
/*
int calculoTempoGasto(clock_t inicio)
{
	clock_t atual;
	atual = clock();
	unsigned long int segundos = 0;
	////// nao existe tempo negativo entao double foi substituido por unsigned long int que pode armazenar um tempo de até 1193 horas;
	segundos = (unsigned long int)(atual - inicio) / (unsigned long int)CLOCKS_PER_SEC;
	return segundos / 60;
}
*/

bool numeroParticipantescorreto(int numeroJogadores)
{
	if (numeroJogadores <= 1)
	{
		printf("\n\n %sDeve jogar mais de um jogador.%s\n", emvermelho, empadrao);
	}
	else
		if (numeroJogadores > 6)
		{
			printf("\n\n %sNúmero não pode ultrapassar de 6%s\n", emvermelho, empadrao);
		}
	return (numeroJogadores > 1 && numeroJogadores < 6);
}



int maiorNumeroDeHabitantes(int numeroJogadoresf, long int* precursosHabitantesf) {
	int quantidadeDeMaiorNumeroDeHabitantes = 0;
	for (int contador = 0; contador < numeroJogadoresf; contador = contador + 1) {
		if (*precursosHabitantesf > quantidadeDeMaiorNumeroDeHabitantes) {
			quantidadeDeMaiorNumeroDeHabitantes = *precursosHabitantesf;
		}
		precursosHabitantesf = precursosHabitantesf + 1;
	}
	return quantidadeDeMaiorNumeroDeHabitantes;
}

int houveEmpatef(int numeroJogadoresf, long int* recursosHabitantesf, int maiorNumeroDeHabitantesf) {
	int houveEmpatefv = 0;
	for (int forHouveEmpatef = 0; forHouveEmpatef < numeroJogadoresf; forHouveEmpatef = forHouveEmpatef + 1) {
		if (maiorNumeroDeHabitantesf == *recursosHabitantesf) {
			houveEmpatefv = houveEmpatefv + 1;
		}
		recursosHabitantesf = recursosHabitantesf + 1;
	}
	return houveEmpatefv;
}

void tempoDaPartida(unsigned long int tempoRegistradof) {
	unsigned int horasDePartidaf = 0;
	unsigned int minutosDePartidaf = 0;
	unsigned int segundosDePartidaf = 0;

	for (tempoRegistradof; tempoRegistradof >= 3600000; tempoRegistradof = tempoRegistradof - 3600000) { //2
		horasDePartidaf = horasDePartidaf + 1;
	}
	for (tempoRegistradof; tempoRegistradof >= 60000; tempoRegistradof = tempoRegistradof - 60000) { //34
		minutosDePartidaf = minutosDePartidaf + 1;
	}
	for (tempoRegistradof; tempoRegistradof >= 1000; tempoRegistradof = tempoRegistradof - 1000) { //16
		segundosDePartidaf = segundosDePartidaf + 1;
	}

	if (tempoRegistradof >= 500) {
		segundosDePartidaf = segundosDePartidaf + 1;
	}

	if (segundosDePartidaf > 59) {
		minutosDePartidaf = minutosDePartidaf + 1;
		segundosDePartidaf = segundosDePartidaf - 60;

	}

	if (minutosDePartidaf > 59) {
		horasDePartidaf = horasDePartidaf + 1;
		minutosDePartidaf = minutosDePartidaf - 60;
	}

	printf("\n\n %i hora(s), %i minuto(s) e %i segundo(s).\n", horasDePartidaf, minutosDePartidaf, segundosDePartidaf);
	printf("\n\n\n");
	system("pause");
}

int main(void)
{

	setlocale(LC_ALL, "Portuguese");

	int jogadoresRestantes = 6;
	unsigned long int tempoJogo = 0, tempoGasto = 0;
	int jogador = 0, jogadorTurno = 0;			// jogador atual
	int posicaox = 0, posicaoy = 0;
	int turnoDaPartida = 0;
	//////unsigned long int tempoInicial = 0; // removido por 'tempoInicial: redefinicao benigna de tipo' // 'unsigned long tempoInicial': redefinicao;
	////// variavel tempoAtual nao usada;
	////// clock_t tempoInicial, tempoAtual;
	//////clock_t tempoInicial;

	//////tempoInicial = clock(); ////// depreciado usando a variavel cronometro;
	int extrair = 0; //quando vai extrair de recursos
	//////srand((unsigned)time(NULL)); //inicializar o rand para mudar conforme o tempo ////// nao utilizado

	//////movido para struct do jogador em questao.
	/*
	int habitantesMadeira = 0; // quanto habitantes extraindo madeira
	int habitantesPedra = 0; // quantos habitantes destinados a extrair pedra
	int habitantesAlimentos = 0; // quantos habitantes destinados a extrair alimentos
	*/
	int vencedorBatalha = 0;
	int alistarSoldados = 0;
	int convocarSoldadosParaGuerra = 0;
	int moverNovamente = 1;
	int opcao2 = -2;
	do
	{
		printf(" Digite o número jogadores para esta partida.\n (6 jogadores são o máximo permitido): \n");
		scanf_s("%i", &numeroJogadores);
		if (numeroParticipantescorreto(numeroJogadores))
		{
			system("cls");
		}
	} while (numeroJogadores <= 1 || numeroJogadores > 6);
	//////while (numeroJogadores <= 1 && numeroJogadores > 6);

	printf(" Partida configurada para %i jogadores. \n\n", numeroJogadores);

	//////printf("Digite o tempo de jogo em minutos: \n");
	//////scanf_s("%i", &tempoJogo);
	tempoJogo = 25200000; ////// 7 horas de jogo no maximo;


	//prencher o mapa com recursos
	for (posicaox = 0; posicaox < 20; ++posicaox)
	{
		for (posicaoy = 0; posicaoy < 25; ++posicaoy)
		{  // preenche as posicoes do mapa com recursos aleatorios
			preencherMapa(&mapa[posicaox][posicaoy]);
		}
	}

	jogadoresRestantes = numeroJogadores;

	//iniciando as variaveis
	for (jogador = 0; jogador < numeroJogadores; ++jogador)
	{
		inicializandoRecursos(&recursos[jogador], numeroJogadores);
		mapa[recursos[jogador].posicaoxIni][recursos[jogador].posicaoyIni].ocupadoJogador = jogador;
		//////recursos[jogador].numeroJogador = jogador + 1; // o vetor começa em zero, mas numero do jogador em 1 a 100
		//////para nao sobrar um indice de vetor considerar jogadores de 0 a 5;
		//////o software deve considerar jogadores de 0~5 total 6;
		recursos[jogador].numeroJogador = jogador;
	}

	/*/ para teste
	do {
	  int pos = 9;
	  printf("digite x: ");
	  scanf_s("%i", &posicaox);
	  printf("\n digite y: ");
	  scanf_s("%i", &posicaoy);
		printf(" %i %i ", posicaox,posicaoy);
	 ocuparPosicao(&recursos[0],posicaox,posicaoy,pos);
	}
	 while ( 1==1);
	 */

	clock_t cronometro[2];
	cronometro[0] = clock();
	cronometro[1] = 0;
		
	

	while ((jogadoresRestantes > 1) && (tempoJogo > tempoGasto))
	{
		turnoDaPartida = turnoDaPartida + 1;
		system("cls");
		printf(" Restam %i jogador(es) \n\n", jogadoresRestantes);
		printf(" Apartida está no turno %i \n\n", turnoDaPartida);
		printf(" Tempo da partida: ");
		tempoDaPartida(tempoGasto);
		//loop da vez dos jogadores 
		// jogador = jogador da vez
		//////system("pause"); ja tem pause no relogio;
		for (jogador = 0; jogador < numeroJogadores; ++jogador)
		{
			system("cls");
			if (recursos[jogador].foraJogo == 0) { continue; } // jogador fora -passa a vez para proximo jogador
			printf(" Vez do jogador %i \n\n\n", jogador + 1);
			system("pause");
			int opcao = -1;

			do {
				system("cls");
				do {

					printf(" Digite a opcao de jogo jogador %i: \n", jogador + 1);
					printf("\n\n 1 - Coletar \n");
					printf("\n\n 2 - Construir \n");
					printf("\n\n 3 - Alistar habitante (soldados) \n");
					printf("\n\n 4 - Mover para posição \n");
					printf("\n\n 5 - Convocar soldado para Guerra \n");
					printf("\n\n 6 - Status do jogo \n");
					printf("\n\n 0 - Passar a vez \n");
					scanf_s("%i", &opcao);
					//////system("cls");
				} while (opcao < 0 || opcao > 6);
				switch (opcao)
				{
				case 1: //coletar 
					do {
						system("cls");
						printf(" Você tem %i habitantes. \n\n %i habitantes podem coletar. \n\n Como deseja dividir as tarefas? \n", recursos[jogador].habitantes, (recursos[jogador].habitantes / 10) - recursos[jogador].habitantesOcupados);
						printf("\n\n Quantos habitantes devem extrair alimento? \n");
						do{
						scanf_s("%i", &recursos[jogador].habitantesAlimentos);
						} while (recursos[jogador].habitantesAlimentos < 0 || (recursos[jogador].habitantesAlimentos > recursos[jogador].habitantes)   );
						printf("\n\n Quantos habitantes devem extrair madeira? \n");
						do {
						scanf_s("%i", &recursos[jogador].habitantesMadeira);
						} while (recursos[jogador].habitantesAlimentos < 0 || (recursos[jogador].habitantesMadeira > recursos[jogador].habitantes)   );
						printf("\n\n Quantos habitantes devem extrair pedra? \n");
						do {
						scanf_s("%i", &recursos[jogador].habitantesPedra);
						} while (recursos[jogador].habitantesAlimentos < 0 || (recursos[jogador].habitantesPedra > recursos[jogador].habitantes)   );

						if ((recursos[jogador].habitantesAlimentos + recursos[jogador].habitantesMadeira + recursos[jogador].habitantesPedra) > ((recursos[jogador].habitantes / 10) - recursos[jogador].habitantesOcupados)) {
							printf("\n\n %sNúmero de habitantes insuficiente para cumprir esta ordem. %s\n", emvermelho, empadrao);
							printf("\n\nDeseja redistribuir as tarefas?\n\n Digite 0 para sair ou 1 para redistribuir as tarefas.\n");
							scanf_s("%i", &opcao2);
						}
						else {
							printf("\n\nSalvar ordem de coleta?\n\n Digite 0 para sair ou 1 para redistribuir as tarefas.\n");
							scanf_s("%i", &opcao2);
							recursos[jogador].habitantesOcupados = recursos[jogador].habitantesOcupados + recursos[jogador].habitantesAlimentos + recursos[jogador].habitantesMadeira + recursos[jogador].habitantesPedra;
						}
						//////esta atribuindo todos os habitantes em cada ordem de coleta isso multiplica os habitantes indevidamente;
						/*
						else
						{
							habitantesMadeira = recursos[jogador].habitantes;
							habitantesPedra = recursos[jogador].habitantes;
							habitantesAlimentos = recursos[jogador].habitantes;
						}
						*/
						// verificar se o numero de habitantes total que vao coletar está correto
						//////melhor resolvido com >=;
						//////while (habitantesMadeira + habitantesPedra + habitantesAlimentos != recursos[jogador].habitantes);
					} while (opcao2 !=0);

					break;


					//////deve ser contabilizado no fim do turno e nao durante a ordem;
					/*
					//extrair madeira ou multiplas coletas
					if (opcao == 1 || opcao == 4)
					{
						extrair = (10 * habitantesMadeira); // quanto vai coletar 1/10 habitantes

							// verificacao se no mapa tem os recursos senao passa para proximas posicoes ate completar ou
							// varrer todo as posicoes do jogador
						for (posicaox = 0; posicaox < 20 && extrair > 0; ++posicaox)
						{
							for (posicaoy = 0; posicaoy < 25 && extrair > 0; ++posicaoy)
							{
								if (mapa[posicaox][posicaoy].ocupadoJogador == jogador) //COLETAR SOMENTE recursos/POSICAO EM SUA POSSE
								{
									extrair = baixarRecursosMadeira(&mapa[posicaox][posicaoy], extrair);
								}
							}
						}
						//vai receber tudo que puder extrair de suas terras desconsiderando o que não conseguiu extrair
						// pois varreu todas suas posicoes, mas nao completou tudo que poderia extrair
						recursos[jogador].madeiraColetando = recursos[jogador].madeiraColetando + (10 * habitantesMadeira) - extrair;
					}
					//extraindo pedra ou multipla extracao
					if (opcao == 2 || opcao == 4)
					{
						extrair = (10 * habitantesPedra); // quanto vai coletar 1/10 habitantes
						for (posicaox = 0; posicaox <= 20 && extrair > 0; ++posicaox)
						{
							for (posicaoy = 0; posicaoy <= 25 && extrair > 0; ++posicaoy)
							{
								if (mapa[posicaox][posicaoy].ocupadoJogador == jogador) //COLETAR SOMENTE recursos/POSICAO EM SUA POSSE
								{
									extrair = baixarRecursosPedra(&mapa[posicaox][posicaoy], extrair);
								}
							}
						}
						recursos[jogador].pedraColetando = recursos[jogador].pedraColetando + (10 * habitantesPedra) - extrair;
					}
					// extraindo recursos alimentos
					 //recursos ilimitados
					if (opcao == 3 || opcao == 4)
					{
						recursos[jogador].alimentoColetando = recursos[jogador].alimentoColetando + (10 * habitantesAlimentos);
					}


					break; // fim switch-coletar-opcoes
					*/
					// contruir o que 
				case 2:
					do {
						system("cls");
						printf(" Jogador %i. \n O que deseja construir? \n\n", jogador + 1);
						printf("\n\n 1 - Casa \n");
						printf("\n\n 2 - Quartel \n");
						printf("\n\n 3 - Muralha \n");
						printf("\n\n 4 - Templo \n");
						scanf_s("%i", &opcao);
					} while (opcao < 1 || opcao >4);
					switch (opcao)
					{
					case 1:
						if (podeConstruirCasa(recursos[jogador]))
						{
							construirCasa(&recursos[jogador]);

						}
						else
						{
							printf("\n\n %sRecursos insuficientes para construção da(s) casa(s). %s\n", emvermelho, empadrao);

							printf("\n\n\n");
							system("pause");
						}
						break;

					case 2:
						if (recursos[jogador].quartel == 1)
						{
							printf("\n\n Já possui quartel\n");
							printf("\n\n\n");
							system("pause");
						}
						else
							if (podeConstruirQuartel(recursos[jogador]))
							{
								construirQuartel(&recursos[jogador]);
							}
							else
							{
								printf("\n\n %sRecursos insuficientes para construir o quartel. %s\n", emvermelho, empadrao);
								printf("\n\n\n");
								system("pause");
							}
						break;

					case 3:
						if (podeConstruirMuralha(recursos[jogador]))
						{
							//////construirTemplo(&recursos[jogador]);
							contruirMuralha(&recursos[jogador]);
						}
						else
						{
							printf("\n\n %sRecursos insuficientes para construir a muralha. %s\n", emvermelho, empadrao);
							printf("\n\n\n");
							system("pause");
						}
						break;

					case 4:
						//verifica se tem recursos disponivel para construir o templo
						if (podeConstruirTemplo(recursos[jogador]))
						{
							construirTemplo(&recursos[jogador]);
						}
						else {
							printf("\n\n %sRecursos insuficientes para construir o templo. %s\n", emvermelho, empadrao);
							printf("\n\n\n");
							system("pause");
						}

						break;
					}


					break;

					// converter para soldado na cidade (alistar)
				case 3:
					system("cls");
					if (recursos[jogador].quartel == 0) {
						printf("\n\n %sSem quartel não pode-se ter soldado(s). %s\n", emvermelho, empadrao);
						printf("\n\n\n");
						system("pause");
						break;
					}
					else {
						do {
							printf("\n\n Quantos habitantes deseja alistar? \n\n Atenção o número máximo possível de soldados são 50 porcento de habitantes. \n\n Você pode alistar até %i soldado(s). \n", (recursos[jogador].habitantes * 50 / 100));
							scanf_s("%i", &alistarSoldados);
							//  para ter soldado precisa ter o quartel construido
							// e 50% total pode ser soldado
							//////nao esta comparando se a quantidade de soldados a alistar é maior que 50% da populaçao;
							//////nao faz comparacao com o numero de habitantes a se alistar e sim se a cidade pode comportar mais soldados;
							//////if ((recursos[jogador].soldadoCidade / recursos[jogador].habitantes * 100) > 50)
							if (alistarSoldados > (recursos[jogador].habitantes * 50 / 100) || alistarSoldados > recursos[jogador].habitantes - recursos[jogador].habitantesOcupados) {

								printf("\n\n %sNão pode alistar mais de 50 porcento da população. \n Digite zero para sair. %s\n", emvermelho, empadrao);
								opcao = -1;
							}
							else {
								recursos[jogador].soldadoCidade = recursos[jogador].soldadoCidade + alistarSoldados;
								recursos[jogador].habitantesOcupados = recursos[jogador].habitantesOcupados + recursos[jogador].soldadoCidade;
							}

						} while (alistarSoldados == -1);
					}
					break;

					// mover para posicao 
				case 4:

					system("cls");

					do
					{
						printf("\n\n Você possui as seguintes posições ocupadas: \n\n");

						for (int forposicoesx = 0; forposicoesx < 20; forposicoesx = forposicoesx + 1) {
							for (int forposicoesy = 0; forposicoesy < 25; forposicoesy = forposicoesy + 1) {
								if (mapa[forposicoesx][forposicoesy].ocupadoJogador == jogador) {
									printf("(%i , %i)\t", forposicoesx, forposicoesy);
								}
							}
						}

						printf("\n\n Para onde você deseja avançar? \n\n");
						printf(" posição x para avançar: \n");
						scanf_s("%i", &recursos[jogador].moverSalvox);

						printf("\n\n posição y para avançar: \n");
						scanf_s("%i", &recursos[jogador].moverSalvoy);

						if (!pontoExiste(recursos[jogador].moverSalvox, recursos[jogador].moverSalvoy) || (posicaoJaConquistada(&recursos[jogador], recursos[jogador].moverSalvox, recursos[jogador].moverSalvoy)) || (!(posicaoAdjacente(recursos[jogador], recursos[jogador].moverSalvox, recursos[jogador].moverSalvoy)))) {
							printf("\n\n %sPosição não permitida! \n\n Ou o ponto não existe \n\n Ou a posição já foi conquistada. \n\n Ou ainda não esta sob alcance. %s\n", emvermelho, empadrao);
						}

						printf("\n\n Deseja salvar esse deslocamento?\n\n\n 1 - Outra posição \n\n 0 - Salvar. \n");
						scanf_s("%i", &opcao2);
					} while (opcao2 != 0);
					//////repetir enquanto o jogador quiser
					// repetir enquanto ponto NAO EXISTE ou
					// posicao ja foi conquistada pelo jogador ou 
					//posicao digitada NAO E adjacente dos que o jogador possue
					//////while (   !pontoExiste(posicaox, posicaoy) || (posicaoJaConquistada(&recursos[jogador], posicaox, posicaoy)) || (!(posicaoAdjacente(recursos[jogador], posicaox, posicaoy)))   );

					//////movido para processamento de fim de turno;
					/*
					// ocupar posicao se nao tiver ocupado 
					if (mapa[posicaox][posicaoy].ocupadoJogador == -1) { // nao ocupado
						  //colocando na fila de arrays, na ultima posicao
						recursos[jogador].posicoes[recursos[jogador].posicoesConquistada].posicaox = posicaox; // adicionando a posicao lista de posicoes conquistadas
						recursos[jogador].posicoes[recursos[jogador].posicoesConquistada].posicaoy = posicaoy; //
						++recursos[jogador].posicoesConquistada;  //posicoes conquistada
						mapa[posicaox][posicaoy].ocupadoJogador = jogador;
					}
					else
					{	//batalha de quem moveu para posição - ataque contra que tem a posse da posição na cidade
						vencedorBatalha = batalhaPosicao(recursos[jogador], recursos[mapa[posicaox][posicaoy].ocupadoJogador]);
						mapa[posicaox][posicaoy].ocupadoJogador = vencedorBatalha; //no vetor começa com zero numero jogador começa com 1
						printf("\n\n Posição (%i, %i) vencida pelo jogador %i na batalha \n", posicaox, posicaoy, vencedorBatalha + 1);
					}
					*/
					break; //fim do mover-posicao
				case 5:
					system("cls");
					do {
						printf("\n\n Existem %.0lf soldados na cidade.\n\n Quantos soldados você deseja convocar para para guerra? \n", recursos[jogador].soldadoCidade);
						scanf_s("%i", &convocarSoldadosParaGuerra);
						// somente pode ir para guerra soldados ja alistados (soldados na cidade)
						//////alistarSoldados substituido por convocarSoldadosParaGuerra para previnir de erros;
						//////alistar soldados ser maior que soldados na cidade;
						//////if (recursos[jogador].soldadoCidade == 0 || recursos[jogador].soldadoCidade >= alistarSoldados)
						if (recursos[jogador].soldadoCidade == 0 || recursos[jogador].soldadoCidade < convocarSoldadosParaGuerra)
						{
							printf("\n\n %sNúmero de soldados alistados insuficientes. \n\n Considere responder 0 para cancelar. %s\n", emvermelho, empadrao);
							scanf_s("%i", &opcao2);
						}
						else
						{
							recursos[jogador].soldadoGuerra = recursos[jogador].soldadoGuerra + convocarSoldadosParaGuerra;
							recursos[jogador].soldadoCidade = recursos[jogador].soldadoCidade - recursos[jogador].soldadoGuerra;

						}
					} while (opcao2 != 0);
					break; //fim convocar para guerra

				case 6:
					system("cls");
					mostrarRecursos(recursos[jogador]);
					break;
				}
			} while (opcao != 0);



		}	//////fim-for rodada que representa um turno, depois daqui considera-se todos os jogadores com seus turnos finalizados;



		//processar no final de cada turno e verifica se terminou de construir algo de algum jogador
		for (jogadorTurno = 0; jogadorTurno < numeroJogadores; ++jogadorTurno)
		{ //se tiver fora do jogo , nem checa 
			if (recursos[jogadorTurno].foraJogo == 0) { continue; }
			construindo(&recursos[jogadorTurno]);//verifica se tem tem algo construindo
		   //verifica se tem alimento no estoque de cada jogador, se não houver diminui um habitante
		   // caso tenha nasce mais um		  
			if (recursos[jogadorTurno].alimento <= 0)
			{
				--recursos[jogadorTurno].habitantes;
			}
			else // há alimentos
			{
				//////fazer o calculo direto;
				//////int habitantesCidade;
				////// habitantesCidade int, porem soldadoGuerra double; 
				//////se for alterar int para double em habitantesCidade quase todas as variaveis devem se tornar double por efeito em cadeia; 
				////habitantesCidade = recursos[jogadorTurno].habitantes - recursos[jogadorTurno].soldadoGuerra - recursos[jogadorTurno].soldadoCidade;
				//perde 1 alimento para cada habitante na cidade
				recursos[jogadorTurno].alimento = recursos[jogadorTurno].alimento - (recursos[jogadorTurno].habitantes - recursos[jogadorTurno].soldadoGuerra);
				//perde 2 alimentos para cada soldado em guerra
				////// alimento int, porem soldadoGuerra double; 
				//////se for alterar int para double em alimento quase todas as variaveis devem se tornar double por efeito em cadeia; 
				recursos[jogadorTurno].alimento = recursos[jogadorTurno].alimento - (2 * recursos[jogadorTurno].soldadoGuerra);
				// só vai aumentar os habitanes se tiver alimento e casa, bolsa familia nao conta
				//////aumentar a populacao caso tiver mais casas				

				if (recursos[jogadorTurno].casas > 0 && (recursos[jogadorTurno].casas * 10 < recursos[jogadorTurno].habitantes)) {
					++recursos[jogadorTurno].habitantes;
				}


			}
			//perdeu habitante e ficou sem, sai do jogo
			if (recursos[jogadorTurno].habitantes == 0) {
				recursos[jogadorTurno].foraJogo = 0; //fora de jogo
				--jogadoresRestantes;  //menos um no jogo
				printf("\n\n Resta %i jogador(es) na partida. \n", jogadoresRestantes);
			}


			//////sistema de coleta adaptado do antigo switch
			extrair = (10 * recursos[jogadorTurno].habitantesMadeira); // quanto vai coletar 1/10 habitantes

					// verificacao se no mapa tem os recursos senao passa para proximas posicoes ate completar ou 
					// varrer todo as posicoes do jogador
			for (posicaox = 0; posicaox < 20 && extrair > 0; ++posicaox)
			{
				for (posicaoy = 0; posicaoy < 25 && extrair > 0; ++posicaoy)
				{
					if (mapa[posicaox][posicaoy].ocupadoJogador == jogadorTurno) //COLETAR SOMENTE recursos/POSICAO EM SUA POSSE
					{
						extrair = baixarRecursosMadeira(&mapa[posicaox][posicaoy], extrair);
					}
				}
			}
			//vai receber tudo que puder extrair de suas terras desconsiderando o que não conseguiu extrair
			// pois varreu todas suas posicoes, mas nao completou tudo que poderia extrair	  
			recursos[jogadorTurno].madeira = recursos[jogadorTurno].madeira + (10 * recursos[jogadorTurno].habitantesMadeira) - extrair;

			//extraindo pedra ou multipla extracao

			extrair = (10 * recursos[jogadorTurno].habitantesPedra); // quanto vai coletar 1/10 habitantes
			for (posicaox = 0; posicaox < 20 && extrair > 0; ++posicaox)
			{
				for (posicaoy = 0; posicaoy < 25 && extrair > 0; ++posicaoy)
				{
					if (mapa[posicaox][posicaoy].ocupadoJogador == jogadorTurno) //COLETAR SOMENTE recursos/POSICAO EM SUA POSSE
					{
						extrair = baixarRecursosPedra(&mapa[posicaox][posicaoy], extrair);
					}
				}
			}
			recursos[jogador].pedra = recursos[jogadorTurno].pedra + (10 * recursos[jogadorTurno].habitantesPedra) - extrair;

			// extraindo recursos alimentos
			 //recursos ilimitados

			recursos[jogadorTurno].alimento = recursos[jogadorTurno].alimento + (10 * recursos[jogadorTurno].habitantesAlimentos);



			extrair = (10 * recursos[jogadorTurno].habitantesMadeira); // quanto vai coletar 1/10 habitantes

				// verificacao se no mapa tem os recursos senao passa para proximas posicoes ate completar ou 
				// varrer todo as posicoes do jogador
			for (posicaox = 0; posicaox < 20 && extrair > 0; ++posicaox)
			{
				for (posicaoy = 0; posicaoy < 25 && extrair > 0; ++posicaoy)
				{
					if (mapa[posicaox][posicaoy].ocupadoJogador == jogadorTurno) //COLETAR SOMENTE recursos/POSICAO EM SUA POSSE
					{
						extrair = baixarRecursosMadeira(&mapa[posicaox][posicaoy], extrair);
					}
				}
			}
			//vai receber tudo que puder extrair de suas terras desconsiderando o que não conseguiu extrair
			// pois varreu todas suas posicoes, mas nao completou tudo que poderia extrair	  
			recursos[jogadorTurno].madeira = recursos[jogadorTurno].madeira + (10 * recursos[jogadorTurno].habitantesMadeira) - extrair;

			//extraindo pedra ou multipla extracao

			extrair = (10 * recursos[jogadorTurno].habitantesPedra); // quanto vai coletar 1/10 habitantes
			for (posicaox = 0; posicaox < 20 && extrair > 0; ++posicaox)
			{
				for (posicaoy = 0; posicaoy < 25 && extrair > 0; ++posicaoy)
				{
					if (mapa[posicaox][posicaoy].ocupadoJogador == jogadorTurno) //COLETAR SOMENTE recursos/POSICAO EM SUA POSSE
					{
						extrair = baixarRecursosPedra(&mapa[posicaox][posicaoy], extrair);
					}
				}
			}
			recursos[jogadorTurno].pedra = recursos[jogadorTurno].pedra + (10 * recursos[jogadorTurno].habitantesPedra) - extrair;

			// extraindo recursos alimentos
			 //recursos ilimitados

			recursos[jogadorTurno].alimento = recursos[jogadorTurno].alimento + (10 * recursos[jogadorTurno].habitantesAlimentos);



			//////movendo unico movimento por turno;
			if (mapa[recursos[jogadorTurno].moverSalvox][recursos[jogadorTurno].moverSalvoy].ocupadoJogador == -1) { // nao ocupado
						  //colocando na fila de arrays, na ultima posicao
				recursos[jogadorTurno].posicoes[recursos[jogadorTurno].posicoesConquistada].posicaox = recursos[jogadorTurno].moverSalvox; // adicionando a posicao lista de posicoes conquistadas
				recursos[jogadorTurno].posicoes[recursos[jogadorTurno].posicoesConquistada].posicaoy = recursos[jogadorTurno].moverSalvoy; //
				++recursos[jogadorTurno].posicoesConquistada;  //posicoes conquistada
				mapa[recursos[jogadorTurno].moverSalvox][recursos[jogadorTurno].moverSalvoy].ocupadoJogador = jogadorTurno;
			}
			else
			{	//batalha de quem moveu para posição - ataque contra que tem a posse da posição na cidade
				vencedorBatalha = batalhaPosicao(recursos[jogadorTurno], recursos[mapa[recursos[jogadorTurno].moverSalvox][recursos[jogadorTurno].moverSalvoy].ocupadoJogador]);
				mapa[recursos[jogadorTurno].moverSalvox][recursos[jogadorTurno].moverSalvoy].ocupadoJogador = vencedorBatalha; //no vetor começa com zero numero jogador começa com 1
				printf("\n\n Posição (%i, %i) vencida pelo jogador %i na batalha \n", recursos[jogador].moverSalvox, recursos[jogador].moverSalvoy, vencedorBatalha + 1);
			}



		}//////fim do for de processar turno;














		//////depreciado, tem que fazer ordem de coleta todo turno se for usar o sistema a seguir;
		//////preenchendo os recursos de direito a cada jogador apos uma rodada;

		//////for (jogador = 0; jogador < numeroJogadores; jogador = jogador + 1) { 

			//////recursos[jogador].alimento = recursos[jogador].alimentoColetando;
			//////recursos[jogador].madeira = recursos[jogador].madeiraColetando;
			//////recursos[jogador].pedra = recursos[jogador].pedraColetando;

			//////caso mudar de ideia e fazer com que o status de coleta zerem ao final do turno
			/*
			recursos[jogador].alimentoColetando = 0;
			recursos[jogador].madeiraColetando = 0;
			recursos[jogador].pedraColetando = 0;
			*/
			//////}

		cronometro[1] = clock();
		tempoGasto = cronometro[1] - cronometro[0];

	}	//////fim-while da partida que funciona enquanto durar o tempo e tiver mais de 1 jogador;


	// saiu do jogo teve um ganhador
	if (jogadoresRestantes == 1)
	{
		for (jogador = 0; jogador < numeroJogadores; ++jogador)
		{
			if (recursos[jogador].foraJogo == 1) // o unico que ficou dentro do jogo
			{
				printf("\n\n O vencedor é o jogador %i. \n Vencendo a partida por resistência. \n", jogador + 1);

				printf("\n\nA partida encerrou com um período de \n");

				tempoDaPartida(tempoGasto);

				break;
			}
		}
	}
	else
		if (jogadoresRestantes == 0)
		{
			printf("\n\n %sTodo mundo morreu de fome! %s\n", emvermelho, empadrao);

			printf("\n\nA partida encerrou com um período de \n");

			tempoDaPartida(tempoGasto);
		}
		else
		{ //ve quem tem maior quantidade de habitantes
			////// variavel ganhador nao usada;
			//////int ganhador;
			long int maiorHabitantes;
			maiorHabitantes = 0;

			////// as condicoes que comparam o jogador vencedor nao parecem de acordo;
			/*
			for (jogador = 0; jogador < numeroJogadores; ++jogador)
			{
				if (recursos[jogador].habitantes > maiorHabitantes)
				{
					maiorHabitantes = recursos[jogador].habitantes;
				}
			}
			printf("Ganhador(es) :");
			for (jogador = 0; jogador < numeroJogadores; ++jogador)
			{
				if (recursos[jogador].habitantes == maiorHabitantes)
				{
					printf("jogador %i .", jogador);
				}
			}
			*/

			maiorHabitantes = maiorNumeroDeHabitantes(numeroJogadores, &recursos[0].habitantes);

			printf("\n\n Quem possui o maior numero de habitantes tem %i habitantes. \n", maiorHabitantes);


			if (houveEmpatef(numeroJogadores, &recursos[0].habitantes, maiorHabitantes) > 1) {
				printf("\n\n Houve empate entre os seguintes jogadores: \n");
				for (int forEmpate = 0; forEmpate < numeroJogadores; forEmpate = forEmpate + 1) {
					if (recursos[forEmpate].habitantes == maiorHabitantes) {
						printf("%i\t", forEmpate + 1);
					}
				}

				printf("\n\nA partida encerrou com um período de \n");
				tempoDaPartida(tempoGasto);
			}

		}

	return 0;
}
