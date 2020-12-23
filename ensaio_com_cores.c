//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: ensaio com formatacao de texto com core e ou fundo diferentes



#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

/*****************************EFECTS***************************************/
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define UNDERSCORE  "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"

/*****************************COLORS***************************************/
#define C_BLACK     "\033[30m"
#define C_RED       "\033[31m"
#define C_GREEN     "\033[32m"
#define C_YELLOW    "\033[33m"
#define C_BLUE      "\033[34m"
#define C_MAGENTA   "\033[35m"
#define C_CYAN      "\033[36m"
#define C_GRAY      "\033[37m"

/***************************BACKGROUNDS************************************/
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_GRAY     "\033[47m"

int main()
{

	system("cls");

	const char* string = "texto escrito em verde!";
	printf("%s%s%s%s%s", NONE, C_GREEN, BG_RED, string, NONE);
	printf("\n%s%s%s%s%s", BOLD, C_GREEN, BG_RED, string, NONE);
	printf("\n%s%s%s%s%s", UNDERSCORE, C_GREEN, BG_RED, string, NONE);
	printf("\n%s%s%s%s%s", HALFBRIGHT, C_GREEN, BG_RED, string, NONE);
	printf("\n%s%s%s%s%s", REVERSE, C_GREEN, BG_RED, string, NONE);
	printf("\n%s%s%s%s%s", BLINK, C_GREEN, BG_RED, string, NONE);
	
	printf("\n\n");
	   
	printf("%s teste com NONE", NONE);
	printf("\n\n");

	printf("%s teste com BOLD", BOLD);
	printf("\n\n");
	printf("%s teste com HALFBRIGHT", HALFBRIGHT);
	printf("\n\n");
	printf("%s teste com UNDERSCORE", UNDERSCORE);
	printf("\n\n");
	printf("%s teste com BLINK", BLINK);
	printf("\n\n");
	printf("%s teste com REVERSE", REVERSE);
	printf("\n\n");
	printf("%s teste com C_BLACK", C_BLACK);
	printf("\n\n");
	printf("%s teste com C_RED", C_RED);
	printf("\n\n");
	printf("%s teste com C_GREEN", C_GREEN);
	printf("\n\n");
	printf("%s teste com C_YELLOW", C_YELLOW);
	printf("\n\n");
	printf("%s teste com C_BLUE", C_BLUE);
	printf("\n\n");
	printf("%s teste com C_MAGENTA", C_MAGENTA);
	printf("\n\n");
	printf("%s teste com C_CYAN", C_CYAN);
	printf("\n\n");
	printf("%s teste com C_GRAY", C_GRAY);
	printf("\n\n");
	printf("%s teste com BG_BLACK", BG_BLACK);
	printf("\n\n");

	printf("%s teste com BG_RED", BG_RED);
	printf("\n\n");

	printf("%s teste com BG_GREEN", BG_GREEN);
	printf("\n\n");

	printf("%s teste com BG_YELLOW", BG_YELLOW);
	printf("\n\n");

	printf("%s teste com BG_BLUE", BG_BLUE);
	printf("\n\n");

	printf("%s teste com BG_MAGENTA", BG_MAGENTA);
	printf("\n\n");

	printf("%s teste com BG_CYAN", BG_CYAN);
	printf("\n\n");

	printf("%s teste com BG_GRAY", BG_GRAY);
	printf("\n\n");


	printf("%s teste com C_GREEN e %sBOLD", C_GREEN, BOLD);
	printf("\n\n");
	
	printf("%s teste com C_GREEN e %sHALFBRIGHT", C_GREEN, HALFBRIGHT);
	printf("\n\n");

	printf("%s teste com C_GREEN e %sUNDERSCORE", C_GREEN, UNDERSCORE);
	printf("\n\n");

	printf("%s teste com C_GREEN e %sBLINK%s", C_GREEN, BLINK, NONE);
	printf("\n\n");
	
	

	printf("%s%s teste com C_GREEN e %sREVERSE%s", C_GREEN, BG_BLUE, REVERSE, NONE);
	printf("\n\n");

	printf("\n\n");
	system("pause");
	return 0;
}



// ele salva o padrao e continua imprimindo conforme a ultima configuracao valida;
// para limpar os efeitos em diante deve ser aplicado o NONE;