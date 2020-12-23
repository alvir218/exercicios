//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: jogo da forca com string em forma de ponteiros



//continuar usando ponteiros

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() {

	printf("\njogo de forca com ponteiros.\n\n advinhe a palavra...\n\n");

	char texto[] = "bicicleta";
	char *ptexto;
	char textoadvinhando[] = "000000000";
	char *ptextoadvinhando;

	ptexto = &texto[0];
	ptextoadvinhando = &textoadvinhando[0];

	// para informar o conteudo usa-se *, sem * informa o endereco;
	//while (   (*ptexto) != (*ptextoadvinhando)   ) {
	//while (   (ptexto) != (ptextoadvinhando)   ) {
	//while (strcmp(ptexto, ptextoadvinhando) != 0) {
	while (   (*ptexto) != (*ptextoadvinhando)   ) {

		char letra;
		char c;

		printf("\n\ndigite uma letra:\n\n");
		letra = _getche();



		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("\n\n");

		int contador;
		for (contador = 0; contador < 9; contador = contador + 1) {
			if ((letra == texto[contador])) {
				textoadvinhando[contador] = letra;
				printf(" %c ", textoadvinhando[contador]);
			}
			else {
				if (texto[contador] == textoadvinhando[contador]) {
					printf(" %c ", textoadvinhando[contador]);
				}
				else {
					printf(" _ ");
				}

			}

		}

		////printf("%c", *ptexto);

		//// soma um endereco de memoria;
		////ptexto++;
		////ptexto = ptexto + 1;

	}


	printf("\n\nvoce advinhou a palavra!");
	printf("\n\n\n");
	system("pause");
	return 0;
}