//programador: allan stuart virmond
//programador: julho cesar radicheski da costa
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio:
/*

RPG TEXTED BASED:

Voc�s ir�o desenvolver um jogo de RPG no estilo text based. Como exemplo de jogo de RPG deste estilo cito o Zork. Observe algumas imagens abaixo deste jogo. Perceba que tudo acontece em modo texto, tomadas de decis�o, ataques, invent�rio, etc.:

O jogo que ser� desenvolvido dever� atender os seguintes requisitos abaixo:1.Interface(30% da nota):�Observe  que  para  este trabalho a interface  � fundamental, pois  � um dos aspectos  mais importantes de um jogo;�Utilizetextos bem escritos, com gram�tica correta. Utilize a fun��o localize para escrever com acentua��o. �Use  cores  para  modificar  seus  textosou  aspectos  da  tela.Existem  diversas bibliotecas  de  cores  em linguagem C;�O  nome  do  jogador,  sua  vida,  invent�rio, itens e  outros  recursos  que  julgar  necess�rio  deixe sempre  na interface para o usu�rio;�Divida  a  interface  da maneira  abaixo.  Narre  a  hist�rica  na  parte  de  cima  da  tela  e  deixe  sempre  as informa��es �teis ao usu�rio embaixo:

NARRATIVA E DECIS�ES

User Interface

Sempre que precisar trocar o texto da hist�ria ou alterar algum dado do jogador, como sua vida, apague ou  sobrescreva  a  tela. Usem  a  fun��o gotoxypara  fazer  isso.  Esta  fun��o  n�o  �  padr�o  da  linguagem  C, portanto deixei ela dispon�vel no meu GITHUB (pasta extras);2.Narrativa(30% da nota):?Ao iniciar o jogo, o usu�rio dever� receber uma tela em que poder� selecionar para iniciar o jogo ou sair imediatamente. Ao iniciar o jogo, o programa deve perguntar qual o nome do jogador/personagem. Este nome deve ser utilizado ao longo de todo o jogo.?Em anexo a este documento voc�s receberam um script do roteiro do jogo. O script deve ser inserido por completo no jogo. Neste roteiro, o jogador dever� chegar ao final dele para tornar-se vitorioso.?Caso o jogador morra em algum momento do jogo, encerre imediatamente ou retorne ao menu inicial;?Como    implementar    a    narrativa    da    hist�ria?    Talvez    a    solu��o    mais    f�cil    seja    criar    uma fun��o/procedimento  para  cada  etapa  da  aventura.  Sempre  que  o  usu�rio  chegar  nesta  etapa,  invoque aquela fun��o, com seu texto e suas poss�veis decis�es;
?Jogabilidade e recursos(40% da nota):?Em alguns momentosdo jogo,voc� poder� efetuar compra/venda de itens com um mercador. Crie uma fun��o para o mercado que � invocada sempre que necess�rio. O mercador dever� permitir a compra de itens. A lista de itens do mercador est�em anexo a este documento.?No jogo, seu personagem ter� uma bruaca. A bruaca ter� um tamanho fixo de 9 espa�os. Trate a bruaca como  uma estrutura  de matriz. Cada  item  ter�  uma  quantidade  de  espa�os  que  ocupa,  bem  como  uma estrutura de espa�os fixo para armazenar, conforme anexo de itens.?O jogador dever� ter um item equipado, o qual poder� usar em poss�veis batalhas;?Crie  uma  maneira  do  jogador  curar  sua  vida  com  um  item  sempre que  ele  quiser  (e  tiver  este  item dispon�vel).?Em  alguns  momentos  poder�o  existir  lutas/batalhas  entre  seu  personagem  e  um  inimigo.  Paraestas batalhas, seu personagem dever� utilizar o item que est� equipado. O processo para c�lculo de dano, vida e morte do personagem ficam a crit�rio dosprogramadores.

*/



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <Windows.h>


int cavernasecreta(char nomedojogador[32]);

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;




int main()
{
	int jogarnovamente = 1;

	setlocale(LC_ALL, "Portuguese");


	while (jogarnovamente == 1)

	{
		char nomedojogador[32], nomedojogadorconfirmacao[32];
		int escolha;
		int	batalha;
		//int retornodacaverna;

		printf("Bem vindo ao...\n\nJORNADA L�MURE\n\n");

		do
		{
			printf("\nEntre com o seu nome de jogador : \n");
			gets_s(nomedojogador);
			printf("\nConfirme o nome:\n");
			gets_s(nomedojogadorconfirmacao);

			if (strcmp(nomedojogador, nomedojogadorconfirmacao) != 0)
			{
				printf("\nOs nomes n�o conferem, digite o nome novamente.\n");
			}
		} while (strcmp(nomedojogador, nomedojogadorconfirmacao) != 0);

		printf("\n\nBem vindo � JORNADA L�MURE ");
		puts(nomedojogador);

		printf("\nAgora voc� � um L�mure de uma grande fam�lia e est� em sua aconchegante toca junto com sua fam�lia.\n\n");

		system("pause");

		system("cls");

		cout << "TOCA DOS L�MURES: \n\nEm uma pequena e simples toca vivia um grupo de 10 l�mures. \nA matriarca da fam�lia est� preocupada, pois o inverno est� chegando e o estoque de comidas est� bastante baixo. \nOs l�mures precisam estocar provis�es para o inverno que ir� chegar. \nOs l�mures ouviram falar de uma lenda onde, \nem algum lugar da floresta existe um local com o segredo para encontrar a comida em abund�ncia. \nObservando a preocupa��o da matriarca, um jovem e bravo l�mure, chamado(a) " << nomedojogador << ", \nvoluntaria-se para ir em busca deste segredo escondido e salvar sua fam�lia. \nO l�mure ent�o coloca sua vestimenta de couro, suas botas, \ncoloca no bolso suas 100 moedas de ouro e pega sua arma, um pequeno, mas bem afiado, \ngraveto feito de carvalho, coloca - o nas costas.\nNeste momento, sua melhor amiga, Lemissa, surge ao seu lado tamb�m pronta para acompanha - lo. \nSua amiga � pequena, mas bastante forte, e carrega sempre consigo uma clava com espinhos. \n\n\nAgora, o l�mure se v� diante de duas op��es : \n\n1 - Conversar com o mercador. \n2 - Ir para floresta. \n";

		do
		{
			printf("\nEscolha 1 ou 2...\n");
			scanf_s("%d", &escolha);
		} while ((escolha != 1) && (escolha != 2));

		if (escolha == 1)
		{
			escolha = 0;
			printf("#mercador1");

		}

		system("cls");
		cout << "ENTRADA DA FLORESTA:\n\n" << nomedojogador << " ruma em dire��o a floresta a busca pela sobreviv�ncia de sua fam�lia junta de sua companheira insepar�vel. \nNa entrada da densa, �mida e escura floresta de arauc�rias e baob�s o l�mure se depara com tr�s caminhos a serem seguidos:\n\n1 - � esquerda, uma pequena trilha, bastante estreita.\n2 - � direita, um largo e amplo caminho. Um odor f�tido � exalado deste lado.\n3 - No meio, uma grande �rvore.\n";
		scanf_s("%d", &escolha);

		do
		{
			printf("\nEscolha 1, 2 ou 3...\n");
			scanf_s("%d", &escolha);
		} while ((escolha != 1) && (escolha != 2) && (escolha != 3));

		if (escolha == 1)
		{
			escolha = 0;
			system("cls");
			printf("FLORESTA (CAMINHO DA ESQUERDA): \n\n");
			cout << nomedojogador << " e sua amiga seguem a estreita trilha para a esquerda. \nAparentemente este caminho parece n�o ser muito usado e � de dif�cil acesso. \nOs l�mures, por serem pequenos, conseguem se esgueirar por dentro os galhos e plantas no caminho at�, ap�s alguns quil�metros de caminhada avistarem uma pequena clareira com duas �rvores de folhas brancas.\n" << nomedojogador << "lembra das hist�rias da matriarca onde, em uma clareira com duas �rvores brancas, uma representa vida e outra morte. \nAmbas �rvores apresentam uma abertura. \nVoc� precisa optar qual delas entrar: \n\n2 - �rvore branca da esquerda. \n1 - �rvore branca da direita. \n";
			do
			{
				printf("\nEscolha 1 ou 2...\n");
				scanf_s("%d", &escolha);
			} while ((escolha != 1) && (escolha != 2));

			if (escolha == 1)
			{
				escolha = 0;
				system("cls");
				printf("�rvore branca da esquerda: \n\n");
				cout << "Os l�mures decidem entrar pela �rvore do lado esquerdo. \nNesta �rvore um feixe de luz bate direto na entrada da porta iluminando o interior. \nAo entrar, nada � visto nem encontrado. Os l�mures est�o decepcionados. \nQuase antes de desistir, a fiel companheira de" << nomedojogador << "\nenxerga uma fina linha amarrada alguns metros acima da cabe�a deles, dentro da �rvore. \nEla resolve saltar o m�ximo que consegue para se agarrar nesta linha. \nEla consegue mas se desprende e cai de costas no ch�o, quebrando seu pesco�o e morrendo. \nVoc� perdeu sua companheira e consequentemente seu poder de luta. \nGra�as ao esfor�o dela, uma passagem se abriu e voc� pode passar por ela. \n\n1 - Atravessar a passagem.\n2 - Voltar.\n\n";
				do
				{
					printf("\nEscolha 1 ou 2...\n");
					scanf_s("%d", &escolha);
				} while ((escolha != 1) && (escolha != 2));

				//caverna secreta abrir um if aqui
			}

			if (escolha == 2)
			{
				escolha = 0;
				system("cls");
				printf("�rvore branca da direita: \n\n");
				cout << "Os l�mures decidem entrar pela �rvore do lado direito. \nNesta �rvore uma n�voa densa e escura espreita dentro da oca �rvore. \nAo entrar, nada � visto nem encontrado. " << nomedojogador << " tateia as paredes internas da �rvore at� que encontra uma sali�ncia. Ele aperta. \nUma passagem na �rvore � aberta e voc� entrar por ela. \n\n1 � Atravessar a passagem.\n2 � Voltar.\n";
				do
				{
					printf("\nEscolha 1 ou 2...\n");
					scanf_s("%d", &escolha);
				} while ((escolha != 1) && (escolha != 2));

				cavernasecreta(nomedojogador);
			}

		}

		if (escolha == 2)
		{
			escolha = 0;
			system("cls");
			printf("FLORESTA (CAMINHO DA DIREITA): \n\n");
			cout << nomedojogador << " e sua amiga seguem o odor que vem do lado direito da floresta. \nA trilha � bastante ampla.Os l�mures avan�am, devagar, quando percebem pegadas bastante grandes no ch�o. \nEstas pegadas seguem na floresta e terminam repentinamente no meio do mato.\nO odor � muito forte.Os l�mures percebem um animal enorme saindo do mato alto e pulando para cima deles. \nUm urso.Em uma s� mordida, sem qualquer rea��o, os l�mures s�o abocanhados, n�o restando nada. \n\nVoc� perdeu!";

		}

		if (escolha == 3);
		{
			escolha = 0;
			system("cls");
			printf("FLORESTA (CAMINHO DO MEIO): \n\n");
			cout << "Os l�mures optam por fazerem uma escala na grande �rvore em sua frente. \nEsta �rvore poder� dar pistas de onde se localiza o local que precisam chegar. \nAp�s a escala. Os l�mures atingem o topo e resolvem espiar. \nUma �guia, predadora voraz de l�mures enxerga-os e parte para o ataque com suas afiadas garras e bico pontiagudo. \nVoc� s� tem uma op��o, lutar!";

			//#batalhaaguia
			//retornar vitoria 1 se vencer
			//vitoria 0 se perder
			batalha = 1;

			if (batalha == 0)
			{
				escolha = 0;
				printf("\n\nVoc� perdeu!\n\n");

			}

		}


		printf("\n\nJogar Novamente?\n\n0 - N�o\n1 - Sim\n");
		scanf_s("%d", &jogarnovamente);

	}


	return 0;
}



int cavernasecreta(char nomedojogador[32])
{
	int escolha, batalha;

	system("cls");
	printf("CAVERNA SECRETA (HALL DE ENTRADA): \n\n");
	cout << "O l�mure entra na caverna. A porta atr�s dele se fecha. \n" << nomedojogador << " avan�a lentamente pelo escuro. \n Aos poucos uma luz come�a a emergir e vozes ecoam. \nDobrando uma esquina na caverna, avista-se um grupo de l�mures. \nA cor da pele dele � azul. \nTodos utilizam aparatos ind�genas. \nQuando eles veem voc�, sorriem para recebe-lo. \nNeste momento, NomeDoJogador, percebe que na verdade este s�o os l�mures da tribo Chimichunga. \nA tribo citada pela matriarca que det�m o conhecimento 	que eles procuram.\nVoc� se aproxima do chefe da tribo dos Chimichungas. \nEle diz que se voc� seguir a escadaria que est� atr�s deles, e descer os 10 mil degraus, \nencontrar� a resposta e a salva��o para o seu povo. \n\nVoc� tem duas op��es:\n\n1 - Conversar com o mercador da tribo. \n2 - Ir em frente pela escadaria. \n";
	do
	{
		printf("\nEscolha 1 ou 2...\n");
		scanf_s("%d", &escolha);
	} while ((escolha != 1) && (escolha != 2));

	if (escolha == 1)
	{
		escolha = 0;
		printf("mercador2");

	}

	if (escolha == 2)
	{
		escolha = 0;
		system("cls");
		printf("ESCADARIA: \n\n");
		cout << "O l�mure avan�a escadaria abaixo. \nDegrau por degrau. Passo por passo. \nA luz � muito fraca, mas aos poucos os olhos dos l�mures v�o se adaptando \ne � poss�vel ver pelo v�o da escadaria um abismo profundo. \nEles v�o descendo, e descendo e descendo. \nEm um determinando momento, grunhidos s�o ouvidos. \nDuas aranhas, quase invis�veis aparecem na frente. \n\nEnfrente as aranhas...\n";
		//batalhaaranha
		//se vencer retorna batalha 1
		//se perder retorna zero, talvez nao precisa
		
		system("pause");

		batalha = 1;

		

		if (batalha == 1)
		{
			system("cls");
			printf("FINAL DA ESCADARIA: \n\n");
			cout << "Finalmente, ap�s horas, ou talvez dias descendo, os l�mures chegam a final da imensa escadaria. \nNo final dela, escritas antigas est�o colocadas na parede. \n\nO segredo!\n\nPensou " << nomedojogador << ". Voc�, como um bom jovem aprendiz, entende a leitura desta antiga l�ngua. \nPor�m, antes de come�ar a ler, voc� percebe que existe uma esp�cie de t�nel/buraco na parede. \nVozes ecoam por ele e, poucos segundos depois, \na tribo Chimichunga aparece por este escorregador. \nO chefe da tribo diz: \n\n \nEnganamos voc�s! \nN�o existe segredo nenhum! \nAgora voc�s est�o aqui, presos com a gente e morrer�o. \nEm seguida iremos comer a carne de voc�s. \nSim, somos l�mures canibais!\n\n";


			system("pause");
			//batalha final
			batalha = 1;


			if (batalha == 0)
			{
				system("cls");
				printf("Voc� foi derrotado pela tribo Chimichunga!");
				return 0;
			}

			if (batalha == 1)
			{
				system("cls");
				cout << "A tribo Chimichunga foi derrotada. \nAp�s venc�-los voc� come�a a ler tudo que est� nas paredes. \nPor�m, n�o existe nenhuma solu��o para o problema deles. \nTriste, " << nomedojogador << " opta por voltar de m�os vazias. \nAp�s dias subindo a escadaria de volta e chegando ao antigo alojamento dos Chimichunga, \nagora vazio, eles percebem muitas caixas cheias de mantimentos, roupas, provis�es. \n\nEstamos salvos, com estes mantimentos teremos provis�es por muitos anos!\n\n\nFIM DA HIST�RIA!";
				system("pause");
				return 1;
			}
		}

	}

}



