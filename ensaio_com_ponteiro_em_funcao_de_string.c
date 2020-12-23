//programador: allan stuart virmond
//professor: winston sen lun fung
//instituicao de ensino: escola superior politecnica uninter
//disciplina: linguagem de programacao
//ide: visual studio community 2019
//exercicio: ensaio com string em forma de ponteiro

#include <stdio.h>
#include <stdlib.h>



int main() {

	// vetor de tamanho automatico;
	char teste[] = "ponteiros em c"; 
	
	// * significa ponteiro;
	char *ponteiroteste;
	
	// nao tem *;
	// atribuicao de endereco no inicio do vetor;
	// caractere \0 deve ser escrito em aspas simples '' indicando um unico caractere que significa o fim da string;
	ponteiroteste = &teste[0];


	// 
	while (*ponteiroteste != '\0') {
		printf("%c", *ponteiroteste);

		// proximo endereco
		ponteiroteste++;
	}



	printf("\n\n");
	system ("pause");
	return 0;
}
