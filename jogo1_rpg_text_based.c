//programador: allan stuart virmond
//programador: julho cesar radicheski da costa
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio:
/*

RPG TEXTED BASED:

Vocês irão desenvolver um jogo de RPG no estilo text based. Como exemplo de jogo de RPG deste estilo cito o Zork. Observe algumas imagens abaixo deste jogo. Perceba que tudo acontece em modo texto, tomadas de decisão, ataques, inventário, etc.:

O jogo que será desenvolvido deverá atender os seguintes requisitos abaixo:1.Interface(30% da nota):•Observe  que  para  este trabalho a interface  é fundamental, pois  é um dos aspectos  mais importantes de um jogo;•Utilizetextos bem escritos, com gramática correta. Utilize a função localize para escrever com acentuação. •Use  cores  para  modificar  seus  textosou  aspectos  da  tela.Existem  diversas bibliotecas  de  cores  em linguagem C;•O  nome  do  jogador,  sua  vida,  inventário, itens e  outros  recursos  que  julgar  necessário  deixe sempre  na interface para o usuário;•Divida  a  interface  da maneira  abaixo.  Narre  a  histórica  na  parte  de  cima  da  tela  e  deixe  sempre  as informações úteis ao usuário embaixo:

NARRATIVA E DECISÕES

User Interface

Sempre que precisar trocar o texto da história ou alterar algum dado do jogador, como sua vida, apague ou  sobrescreva  a  tela. Usem  a  função gotoxypara  fazer  isso.  Esta  função  não  é  padrão  da  linguagem  C, portanto deixei ela disponível no meu GITHUB (pasta extras);2.Narrativa(30% da nota):?Ao iniciar o jogo, o usuário deverá receber uma tela em que poderá selecionar para iniciar o jogo ou sair imediatamente. Ao iniciar o jogo, o programa deve perguntar qual o nome do jogador/personagem. Este nome deve ser utilizado ao longo de todo o jogo.?Em anexo a este documento vocês receberam um script do roteiro do jogo. O script deve ser inserido por completo no jogo. Neste roteiro, o jogador deverá chegar ao final dele para tornar-se vitorioso.?Caso o jogador morra em algum momento do jogo, encerre imediatamente ou retorne ao menu inicial;?Como    implementar    a    narrativa    da    história?    Talvez    a    solução    mais    fácil    seja    criar    uma função/procedimento  para  cada  etapa  da  aventura.  Sempre  que  o  usuário  chegar  nesta  etapa,  invoque aquela função, com seu texto e suas possíveis decisões;
?Jogabilidade e recursos(40% da nota):?Em alguns momentosdo jogo,você poderá efetuar compra/venda de itens com um mercador. Crie uma função para o mercado que é invocada sempre que necessário. O mercador deverá permitir a compra de itens. A lista de itens do mercador estáem anexo a este documento.?No jogo, seu personagem terá uma bruaca. A bruaca terá um tamanho fixo de 9 espaços. Trate a bruaca como  uma estrutura  de matriz. Cada  item  terá  uma  quantidade  de  espaços  que  ocupa,  bem  como  uma estrutura de espaços fixo para armazenar, conforme anexo de itens.?O jogador deverá ter um item equipado, o qual poderá usar em possíveis batalhas;?Crie  uma  maneira  do  jogador  curar  sua  vida  com  um  item  sempre que  ele  quiser  (e  tiver  este  item disponível).?Em  alguns  momentos  poderão  existir  lutas/batalhas  entre  seu  personagem  e  um  inimigo.  Paraestas batalhas, seu personagem deverá utilizar o item que está equipado. O processo para cálculo de dano, vida e morte do personagem ficam a critério dosprogramadores.

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

		printf("Bem vindo ao...\n\nJORNADA LÊMURE\n\n");

		do
		{
			printf("\nEntre com o seu nome de jogador : \n");
			gets_s(nomedojogador);
			printf("\nConfirme o nome:\n");
			gets_s(nomedojogadorconfirmacao);

			if (strcmp(nomedojogador, nomedojogadorconfirmacao) != 0)
			{
				printf("\nOs nomes não conferem, digite o nome novamente.\n");
			}
		} while (strcmp(nomedojogador, nomedojogadorconfirmacao) != 0);

		printf("\n\nBem vindo à JORNADA LÊMURE ");
		puts(nomedojogador);

		printf("\nAgora você é um Lêmure de uma grande família e está em sua aconchegante toca junto com sua família.\n\n");

		system("pause");

		system("cls");

		cout << "TOCA DOS LÊMURES: \n\nEm uma pequena e simples toca vivia um grupo de 10 lêmures. \nA matriarca da família está preocupada, pois o inverno está chegando e o estoque de comidas está bastante baixo. \nOs lêmures precisam estocar provisões para o inverno que irá chegar. \nOs lêmures ouviram falar de uma lenda onde, \nem algum lugar da floresta existe um local com o segredo para encontrar a comida em abundância. \nObservando a preocupação da matriarca, um jovem e bravo lémure, chamado(a) " << nomedojogador << ", \nvoluntaria-se para ir em busca deste segredo escondido e salvar sua família. \nO lémure então coloca sua vestimenta de couro, suas botas, \ncoloca no bolso suas 100 moedas de ouro e pega sua arma, um pequeno, mas bem afiado, \ngraveto feito de carvalho, coloca - o nas costas.\nNeste momento, sua melhor amiga, Lemissa, surge ao seu lado também pronta para acompanha - lo. \nSua amiga é pequena, mas bastante forte, e carrega sempre consigo uma clava com espinhos. \n\n\nAgora, o lémure se vê diante de duas opções : \n\n1 - Conversar com o mercador. \n2 - Ir para floresta. \n";

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
		cout << "ENTRADA DA FLORESTA:\n\n" << nomedojogador << " ruma em direção a floresta a busca pela sobrevivência de sua família junta de sua companheira inseparável. \nNa entrada da densa, úmida e escura floresta de araucárias e baobás o lêmure se depara com três caminhos a serem seguidos:\n\n1 - À esquerda, uma pequena trilha, bastante estreita.\n2 - À direita, um largo e amplo caminho. Um odor fétido é exalado deste lado.\n3 - No meio, uma grande árvore.\n";
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
			cout << nomedojogador << " e sua amiga seguem a estreita trilha para a esquerda. \nAparentemente este caminho parece não ser muito usado e é de difícil acesso. \nOs lêmures, por serem pequenos, conseguem se esgueirar por dentro os galhos e plantas no caminho até, após alguns quilômetros de caminhada avistarem uma pequena clareira com duas árvores de folhas brancas.\n" << nomedojogador << "lembra das histórias da matriarca onde, em uma clareira com duas árvores brancas, uma representa vida e outra morte. \nAmbas árvores apresentam uma abertura. \nVocê precisa optar qual delas entrar: \n\n2 - Árvore branca da esquerda. \n1 - Árvore branca da direita. \n";
			do
			{
				printf("\nEscolha 1 ou 2...\n");
				scanf_s("%d", &escolha);
			} while ((escolha != 1) && (escolha != 2));

			if (escolha == 1)
			{
				escolha = 0;
				system("cls");
				printf("Árvore branca da esquerda: \n\n");
				cout << "Os lêmures decidem entrar pela árvore do lado esquerdo. \nNesta árvore um feixe de luz bate direto na entrada da porta iluminando o interior. \nAo entrar, nada é visto nem encontrado. Os lêmures estão decepcionados. \nQuase antes de desistir, a fiel companheira de" << nomedojogador << "\nenxerga uma fina linha amarrada alguns metros acima da cabeça deles, dentro da árvore. \nEla resolve saltar o máximo que consegue para se agarrar nesta linha. \nEla consegue mas se desprende e cai de costas no chão, quebrando seu pescoço e morrendo. \nVocê perdeu sua companheira e consequentemente seu poder de luta. \nGraças ao esforço dela, uma passagem se abriu e você pode passar por ela. \n\n1 - Atravessar a passagem.\n2 - Voltar.\n\n";
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
				printf("Árvore branca da direita: \n\n");
				cout << "Os lêmures decidem entrar pela árvore do lado direito. \nNesta árvore uma névoa densa e escura espreita dentro da oca árvore. \nAo entrar, nada é visto nem encontrado. " << nomedojogador << " tateia as paredes internas da árvore até que encontra uma saliência. Ele aperta. \nUma passagem na árvore é aberta e você entrar por ela. \n\n1 – Atravessar a passagem.\n2 – Voltar.\n";
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
			cout << nomedojogador << " e sua amiga seguem o odor que vem do lado direito da floresta. \nA trilha é bastante ampla.Os lêmures avançam, devagar, quando percebem pegadas bastante grandes no chão. \nEstas pegadas seguem na floresta e terminam repentinamente no meio do mato.\nO odor é muito forte.Os lêmures percebem um animal enorme saindo do mato alto e pulando para cima deles. \nUm urso.Em uma só mordida, sem qualquer reação, os lêmures são abocanhados, não restando nada. \n\nVocê perdeu!";

		}

		if (escolha == 3);
		{
			escolha = 0;
			system("cls");
			printf("FLORESTA (CAMINHO DO MEIO): \n\n");
			cout << "Os lêmures optam por fazerem uma escala na grande árvore em sua frente. \nEsta árvore poderá dar pistas de onde se localiza o local que precisam chegar. \nApós a escala. Os lêmures atingem o topo e resolvem espiar. \nUma águia, predadora voraz de lêmures enxerga-os e parte para o ataque com suas afiadas garras e bico pontiagudo. \nVocê só tem uma opção, lutar!";

			//#batalhaaguia
			//retornar vitoria 1 se vencer
			//vitoria 0 se perder
			batalha = 1;

			if (batalha == 0)
			{
				escolha = 0;
				printf("\n\nVocê perdeu!\n\n");

			}

		}


		printf("\n\nJogar Novamente?\n\n0 - Não\n1 - Sim\n");
		scanf_s("%d", &jogarnovamente);

	}


	return 0;
}



int cavernasecreta(char nomedojogador[32])
{
	int escolha, batalha;

	system("cls");
	printf("CAVERNA SECRETA (HALL DE ENTRADA): \n\n");
	cout << "O lêmure entra na caverna. A porta atrás dele se fecha. \n" << nomedojogador << " avança lentamente pelo escuro. \n Aos poucos uma luz começa a emergir e vozes ecoam. \nDobrando uma esquina na caverna, avista-se um grupo de lêmures. \nA cor da pele dele é azul. \nTodos utilizam aparatos indígenas. \nQuando eles veem você, sorriem para recebe-lo. \nNeste momento, NomeDoJogador, percebe que na verdade este são os lêmures da tribo Chimichunga. \nA tribo citada pela matriarca que detêm o conhecimento 	que eles procuram.\nVocê se aproxima do chefe da tribo dos Chimichungas. \nEle diz que se você seguir a escadaria que está atrás deles, e descer os 10 mil degraus, \nencontrará a resposta e a salvação para o seu povo. \n\nVocê tem duas opções:\n\n1 - Conversar com o mercador da tribo. \n2 - Ir em frente pela escadaria. \n";
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
		cout << "O lêmure avança escadaria abaixo. \nDegrau por degrau. Passo por passo. \nA luz é muito fraca, mas aos poucos os olhos dos lêmures vão se adaptando \ne é possível ver pelo vão da escadaria um abismo profundo. \nEles vão descendo, e descendo e descendo. \nEm um determinando momento, grunhidos são ouvidos. \nDuas aranhas, quase invisíveis aparecem na frente. \n\nEnfrente as aranhas...\n";
		//batalhaaranha
		//se vencer retorna batalha 1
		//se perder retorna zero, talvez nao precisa
		
		system("pause");

		batalha = 1;

		

		if (batalha == 1)
		{
			system("cls");
			printf("FINAL DA ESCADARIA: \n\n");
			cout << "Finalmente, após horas, ou talvez dias descendo, os lêmures chegam a final da imensa escadaria. \nNo final dela, escritas antigas estão colocadas na parede. \n\nO segredo!\n\nPensou " << nomedojogador << ". Você, como um bom jovem aprendiz, entende a leitura desta antiga língua. \nPorém, antes de começar a ler, você percebe que existe uma espécie de túnel/buraco na parede. \nVozes ecoam por ele e, poucos segundos depois, \na tribo Chimichunga aparece por este escorregador. \nO chefe da tribo diz: \n\n \nEnganamos vocês! \nNão existe segredo nenhum! \nAgora vocês estão aqui, presos com a gente e morrerão. \nEm seguida iremos comer a carne de vocês. \nSim, somos lêmures canibais!\n\n";


			system("pause");
			//batalha final
			batalha = 1;


			if (batalha == 0)
			{
				system("cls");
				printf("Você foi derrotado pela tribo Chimichunga!");
				return 0;
			}

			if (batalha == 1)
			{
				system("cls");
				cout << "A tribo Chimichunga foi derrotada. \nApós vencê-los você começa a ler tudo que está nas paredes. \nPorém, não existe nenhuma solução para o problema deles. \nTriste, " << nomedojogador << " opta por voltar de mãos vazias. \nApós dias subindo a escadaria de volta e chegando ao antigo alojamento dos Chimichunga, \nagora vazio, eles percebem muitas caixas cheias de mantimentos, roupas, provisões. \n\nEstamos salvos, com estes mantimentos teremos provisões por muitos anos!\n\n\nFIM DA HISTÓRIA!";
				system("pause");
				return 1;
			}
		}

	}

}



