//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: algoritmo para resolver a torre de hanoi de 3 a 9 discos



#include <stdio.h>
#include <stdlib.h>

int torrea[9];
int torreb[9];
int torrec[9];
int tamanhodatorre = 0;
int forimprimirtorres;
int forinvertido;
int topotorrea;
int topotorreb;
int topotorrec;
int vezdatorre = 1;



// declarar funcao e procedimento

void imprimirtorres();
void topodapilha();


int main() {

	printf("resolucao da torre de hanoi de 3 ate 9 discos\n\n\n");



	while (tamanhodatorre != 3 && tamanhodatorre != 4 && tamanhodatorre != 5 && tamanhodatorre != 6 && tamanhodatorre != 7 && tamanhodatorre != 8 && tamanhodatorre != 9) {
		printf("qual o tamanho da torre (minimo: 3 discos e maximo: 9 discos)?\n");
		scanf_s("%d", &tamanhodatorre);
		printf("\n\n");

	}



	// iniciar torre a;
	forinvertido = tamanhodatorre - 1;
	for (forimprimirtorres = 0; forimprimirtorres < tamanhodatorre; forimprimirtorres = forimprimirtorres + 1) {
		torrea[forimprimirtorres] = forinvertido + 1;
		torreb[forimprimirtorres] = 0;
		torrec[forimprimirtorres] = 0;
		forinvertido = forinvertido - 1;
	}



	imprimirtorres();



	while (torrec[tamanhodatorre - 1] != 1) {
		topodapilha();


		// da a para b)
		if (vezdatorre == 1 && torrea[topotorrea] > 0 && ((torrea[topotorrea] < torreb[topotorreb]) || torreb[topotorreb] == 0) ) { 
			if (torreb[topotorreb] == 0) {
				torreb[topotorreb] = torrea[topotorrea];
				torrea[topotorrea] = 0;
				vezdatorre = 2;
			}
			else {
				torreb[topotorreb + 1] = torrea[topotorrea];
				torrea[topotorrea] = 0;
				vezdatorre = 2;
			}
		}
		else { // da a para c
			if (vezdatorre == 1 && torrea[topotorrea] > 0 && (torrea[topotorrea] > torreb[topotorreb]) && ((torrea[topotorrea] < torrec[topotorrec]) || torrec[topotorrec] == 0) ) { 
				if (torrec[topotorrec] == 0) {
					torrec[topotorrec] = torrea[topotorrea];
					torrea[topotorrea] = 0;
					vezdatorre = 1;
				}
				else {
					torrec[topotorrec + 1] = torrea[topotorrea];
					torrea[topotorrea] = 0;
					vezdatorre = 1;
				}
			}
			else { // da b para c
				if (vezdatorre == 2 && torreb[topotorreb] > 0 && ((torreb[topotorreb] < torrec[topotorrec]) || torrec[topotorrec] == 0) ) { 
					if (torrec[topotorrec] == 0) {
						torrec[topotorrec] = torreb[topotorreb];
						torreb[topotorreb] = 0;
						vezdatorre = 3;
					}
					else {
						torrec[topotorrec + 1] = torreb[topotorreb];
						torreb[topotorreb] = 0;
						vezdatorre = 3;
					}
				}
				else { // da b para a
					if (vezdatorre == 2 && torreb[topotorreb] > 0 && (torreb[topotorreb] > torrec[topotorrec]) && ((torreb[topotorreb] < torrea[topotorrea]) || torrea[topotorrea] == 0) ) { 
						if (torrea[topotorrea] == 0) {
							torrea[topotorrea] = torreb[topotorreb];
							torreb[topotorreb] = 0;
							vezdatorre = 2;
						}
						else {
							torrea[topotorrea + 1] = torreb[topotorreb];
							torreb[topotorreb] = 0;
							vezdatorre = 2;
						}
					}
					else { // da c para a
						if (vezdatorre == 3 && torrec[topotorrec] > 0 && ((torrec[topotorrec] < torrea[topotorrea]) || torrea[topotorrea] == 0) ) { 
							if (torrea[topotorrea] == 0) {
								torrea[topotorrea] = torrec[topotorrec];
								torrec[topotorrec] = 0;
								vezdatorre = 1;
							}
							else {
								torrea[topotorrea + 1] = torrec[topotorrec];
								torrec[topotorrec] = 0;
								vezdatorre = 1;
							}
						}
						else { // da c para b
							if (vezdatorre == 3 && torrec[topotorrec] > 0 && (torrec[topotorrec] > torrea[topotorrea]) && ((torrec[topotorrec] < torreb[topotorreb]) || torreb[topotorreb] == 0) ) { 
								if (torreb[topotorreb] == 0) {
									torreb[topotorreb] = torrec[topotorrec];
									torrec[topotorrec] = 0;
									vezdatorre = 3;
								}
								else {
									torreb[topotorreb + 1] = torrec[topotorrec];
									torrec[topotorrec] = 0;
									vezdatorre = 3;
								}
							}
						}
					}
				}
			}

		}				


		if (vezdatorre == 1) {
			vezdatorre = 2;
		}
		else {
			if (vezdatorre == 2) {
				vezdatorre = 3;
			}
			else {
				if (vezdatorre == 3) {
					vezdatorre = 1;
				}
			}
		}

		

		imprimirtorres();
	// while principal;
	}




	printf("\n\nfim de jogo!\n\n");
	imprimirtorres();

	return 0;
}




// funcao e procedimento

void imprimirtorres() {

	printf("\n\n");
	for (forimprimirtorres = tamanhodatorre - 1; forimprimirtorres > -1; forimprimirtorres = forimprimirtorres - 1) {
		printf("%d\t\t%d\t\t%d", torrea[forimprimirtorres], torreb[forimprimirtorres], torrec[forimprimirtorres]);
		printf("\n");
	}
	printf("\n");
	system("pause");
}


void topodapilha() {
	for (forimprimirtorres = 0; forimprimirtorres < tamanhodatorre; forimprimirtorres = forimprimirtorres + 1) {

		if (torrea[forimprimirtorres] > 0) {
			topotorrea = forimprimirtorres;
		}
		else {
			if (torrea[0] == 0) {
				topotorrea = 0;
			}
		}

		if (torreb[forimprimirtorres] > 0) {
			topotorreb = forimprimirtorres;
		}
		else {
			if (torreb[0] == 0) {
				topotorreb = 0;
			}
		}

		if (torrec[forimprimirtorres] > 0) {
			topotorrec = forimprimirtorres;
		}
		else {
			if (torrec[0] == 0) {
				topotorrec = 0;
			}
		}
	}
}