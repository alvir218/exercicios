/*

programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio:
dado um mapa na forma de uma matriz de caracteres, 
faça uma rotina recursiva que encontre e imprima 
um caminho entre a posição [0,0] e a posição [9,9].
um exemplo de mapa está mostrado a seguir. no mapa, 
os asteriscos (*) representam paredes, 
o canto inicio representa o ponto inicial e o canto fim
o ponto final. deverá ser possível entrar com a matriz que 
representa o labirinto. suponha que o labirinto possui uma 
entrada conhecida, porém a saída não é informada e 
escreva uma rotina recursiva para encontrar o caminho.

1 inicio
2 caminho
3 parede
4 fim
		
{1,3,2,2,2,2,2,2,2,2},
{2,2,3,2,3,3,3,3,3,3},
{3,2,2,3,2,2,2,3,2,3},
{3,3,2,2,3,2,2,3,2,2},
{2,3,3,2,2,3,2,3,2,2},
{2,2,2,3,2,3,2,3,2,2},
{2,2,2,2,2,3,2,3,2,2},
{2,3,3,3,3,3,2,3,3,3},
{2,2,2,2,2,2,2,2,2,2},
{3,3,3,3,3,3,3,3,3,4}


*/


#include <stdio.h>
#include <stdlib.h>

#define iMax 10
#define jMax 10

	//1 inicio
	//2 caminho
	//3 parede
	//4 fim
int labirinto[iMax][jMax] = {
	{1,3,2,2,2,2,2,2,2,2},
	{2,2,3,2,3,3,3,3,3,3},
	{3,2,2,3,2,2,2,3,2,3},
	{3,3,2,2,3,2,2,3,2,2},
	{2,3,3,2,2,3,2,3,2,2},
	{2,2,2,3,2,3,2,3,2,2},
	{2,2,2,2,2,3,2,3,2,2},
	{2,3,3,3,3,3,2,3,3,3},
	{2,2,2,2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3,3,3,4}
};

int marcarPassagem[iMax][jMax] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};



struct bifurcacao {
	int bifurcacaoi;
	int bifurcacaoj;
};

struct bifurcacao bifurcacoesh[100];



int caminhoContinuo(int i, int j);

int resolverLabirinto(int i, int j, int bifurcacaon);





int main() {
	
	

	resolverLabirinto(0, 0, 0);

	printf("\n\n\n");
	system("pause");
	return 0;
}



int caminhoContinuo(int i, int j) {
	if (labirinto[i][j] == 3 || i < 0 || i >(iMax - 1) || i < 0 || i >(iMax - 1)) {
		return 0;
	}
	else if (i == 0 && j == 0 && (labirinto[i + 1][j] != 3 || labirinto[i][j + 1] != 3)) {
		return 1;
	}
	else if (i == 0 && j == (jMax - 1) && (labirinto[i + 1][j] != 3 || labirinto[i][j - 1] != 3)) {
		return 2;
	}
	else if (i == (iMax - 1) && j == 0 && (labirinto[i - 1][j] != 3 || labirinto[i][j + 1] != 2)) {
		return 3;
	}
	else if (i == (iMax - 1) && j == (jMax - 1) && (labirinto[i - 1][j] != 3 || labirinto[i][j - 1] != 3)) {
		return 4;
	}
	else if (i == 0 && (j > 0 && j < jMax - 1) && (labirinto[i + 1][j] != 3 || labirinto[i][j + 1] != 3 || labirinto[i][j - 1] != 3)) {
		return 5;
	}
	else if (i == (iMax - 1) && (j > 0 && j < jMax - 1) && (labirinto[i - 1][j] != 3 || labirinto[i][j + 1] != 3 || labirinto[i][j - 1] != 3)) {
		return 6;
	}
	else if ((i > 0 && i < iMax - 1) && (j == jMax - 1) && (labirinto[i - 1][j] != 3 || labirinto[i + 1][j] != 3 || labirinto[i][j - 1] != 3)) {
		return 7;
	}
	else if ((i > 0 && i < iMax - 1) && j == 0 && (labirinto[i - 1][j] != 3 || labirinto[i + 1][j] != 3 || labirinto[i][j + 1] != 3)) {
		return 8;
	}
	else if ((i > 0 && i < (iMax - 1)) && (j > 0 && j < (jMax - 1)) && (labirinto[i - 1][j] != 3 || labirinto[i + 1][j] != 3 || labirinto[i][j + 1] != 3 || labirinto[i][j - 1] != 3)) {
		return 9;
	}
	else {
		return 0;
	}

	//fim de caminhoContinuo;
}



int resolverLabirinto(int i, int j, int bifurcacaon) {
	if (labirinto[i][j] == 4) {
		printf("\n\nencontrado o fim em [%i][%i]", i, j);
		printf("\n\nlabirinto resolvido!\n\n\n");
		return 0;
	}
	else {

		if (caminhoContinuo(i, j + 1) > 0 && marcarPassagem[i][j + 1] == 0) {
			marcarPassagem[i][j + 1] = 1;
			bifurcacoesh[bifurcacaon].bifurcacaoi = i;
			bifurcacoesh[bifurcacaon].bifurcacaoj = j + 1;
			printf("\n\navancando para [%i][%i]", i, j);

			return resolverLabirinto(i, j + 1, bifurcacaon + 1);
		}
		else if (caminhoContinuo(i + 1, j) > 0 && marcarPassagem[i + 1][j] == 0) {
			marcarPassagem[i + 1][j] = 1;
			bifurcacoesh[bifurcacaon].bifurcacaoi = i + 1;
			bifurcacoesh[bifurcacaon].bifurcacaoj = j;
			printf("\n\navancando para [%i][%i]", i, j);

			return resolverLabirinto(i + 1, j, bifurcacaon + 1);
		}
		else if (caminhoContinuo(i, j - 1) > 0 && marcarPassagem[i][j - 1] == 0) {
			marcarPassagem[i][j - 1] = 1;
			bifurcacoesh[bifurcacaon].bifurcacaoi = i;
			bifurcacoesh[bifurcacaon].bifurcacaoj = j - 1;
			printf("\n\navancando para [%i][%i]", i, j);

			return resolverLabirinto(i, j - 1, bifurcacaon + 1);
		}
		else if (caminhoContinuo(i + 1, j) > 0 && marcarPassagem[i + 1][j] == 0) {
			marcarPassagem[i + 1][j] = 1;
			bifurcacoesh[bifurcacaon].bifurcacaoi = i + 1;
			bifurcacoesh[bifurcacaon].bifurcacaoj = j;
			printf("\n\navancando para [%i][%i]", i, j);

			return resolverLabirinto(i + 1, j, bifurcacaon + 1);
		}
		else {
			printf("\n\nretornando para [%i][%i]", bifurcacoesh[bifurcacaon - 1].bifurcacaoi, bifurcacoesh[bifurcacaon - 1].bifurcacaoj);
			return resolverLabirinto(bifurcacoesh[bifurcacaon].bifurcacaoi, bifurcacoesh[bifurcacaon].bifurcacaoj, bifurcacaon - 1);
		}


	}

	//fim resolverLabirinto;
}