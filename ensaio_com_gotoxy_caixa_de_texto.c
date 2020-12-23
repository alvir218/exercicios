//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: ensaio com go to desenhando uma caixa que contorna o texto



#include <stdio.h>
#include <Windows.h>



void box(int x1, int y1, int x2, int y2);

void box2(int x1, int y1, int x2, int y2);

void gotoxy(int x, int y);



int main() {

	int coluna = 10;
	int linha = 15;


	// funcao gotoxy; 
	// 24 linhas por 80 colunas;

	printf("ensaio com a funcao gotoxy \nimprime texto em posicao arbitraria \nimprime uma caixa de texto\n\n\n");
	
	

	system("cls");

	gotoxy(coluna, linha);

	printf("hello...");

	gotoxy(coluna + 3, linha + 2);

	printf("world!\n\n\n\n\n\n");

	system("pause");




	// caixa de texto em torno do hello world;
	
	box(coluna - 2, linha - 2, coluna + 10, linha + 5);
	

	system("pause");

	system("cls");
	
	// coluna inicial, linha inicial, atecoluna; atelinha;

	box2(0, 0, 10, 4);
	system("pause");
	box2(0, 0, 12, 8);
	system("pause");
	box2(0, 0, 14, 10);
	system("pause");
	box2(0,0,16,12);
	system("pause");
	box2(0,0,18,14);
	system("pause");
	box2(0,0,20,16);
	system("pause");
	box2(0,0,22,18);
	system("pause");
	box2(0,0,24,20);
	system("pause");
	box2(0,0,26,22);



	printf("\n\n");
	system("pause");
	return 0;
}


void box(int x1, int y1, int x2, int y2) {
	// contador para for;
	int cont;

	gotoxy(x1, y1);
	putchar(201);
	gotoxy(x2, y1);
	putchar(187);
	gotoxy(x1, y2);
	putchar(200);
	gotoxy(x2, y2);
	putchar(188);

	for (cont = x1 + 1; cont < x2; cont++) {
		gotoxy(cont, y1);
		putchar(205);

	}

	for (cont = x1 + 1; cont < x2; cont++) {
		gotoxy(cont, y2);
		putchar(205);

	}

	for (cont = y1 + 1; cont < y2; cont++) {
		gotoxy(x1, cont);
		putchar(186);

	}

	for (cont = y1 + 1; cont < y2; cont++) {
		gotoxy(x2, cont);
		putchar(186);
	}

// box
}



void box2(int x1, int y1, int x2, int y2) {
	// contador para for;
	int cont;

	gotoxy(x1, y1);
	putchar(201);
	gotoxy(x2, y1);
	putchar(187);
	gotoxy(x1, y2);
	putchar(200);
	gotoxy(x2, y2);
	putchar(188);

	for (cont = x1 + 1; cont < x2; cont++) {
		gotoxy(cont, y1);
		putchar(205);

	}

	for (cont = x1 + 1; cont < x2; cont++) {
		gotoxy(cont, y2);
		putchar(205);

	}

	for (cont = y1 + 1; cont < y2; cont++) {
		gotoxy(x1, cont);
		putchar(186);

	}

	for (cont = y1 + 1; cont < y2; cont++) {
		gotoxy(x2, cont);
		putchar(186);
	}

	// box2
}



void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



