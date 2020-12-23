/*
programador: allan stuart virmond
professor: winston sen lun fung
instituicao de ensino: escola superior politecnica uninter
disciplina: linguagem de programacao
ide: visual studio community 2019

exercicio: 
Replique o exercício 3. Porém, agora, declare um ponteiro para a estrutura de dados heterogênea. No momento da leitura dos dados e da impressão na tela, use o ponteiro para buscar o conteúdo dos campos. Imprima na tela também o seu RU na tela.
*/



int main() {

	printf("linguagem de programacao\nlista de exercicios 1\nexercicio 4\n\n");


	struct cadastrodealuno {
		char nome[42];
		unsigned int ru;

	}; struct cadastrodealuno caluno, * pcaluno;

	pcaluno = &caluno;

	printf("\n\ndigite o nome do aluno: \n\n");
	fflush(stdin);
	fgets((*pcaluno).nome, 42, stdin);

	printf("\n\ndigite o ru: \n\n");
	scanf_s("%i", &(*pcaluno).ru);

	printf("\n\no nome do aluno e: \n%s\n\n\n\no ru do aluno e: \n%i", (*pcaluno).nome, (*pcaluno).ru);




	printf("\n\n\n");
	system("pause");
	return 0;
}
