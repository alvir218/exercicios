#include <stdio.h>
#include <stdlib.h>

// calculo de salario com bonificacao por tempo de servico

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Escreva um algoritmo em pseudocódigo e em fluxograma em que se necessita conhecer o valor do salário e o tempo de serviço de um funcionário. Casoo funcionário esteja a mais de 5 anos na empresa, ele receberá uma bonificação de 20% em seu salário. Caso contrário, somente de 10%. Mostre na tela o bônus do funcionário calculado a partir do seu salário.

int main()

{
	float salario, tempo;

	printf("digite o salario\n");
	scanf_s("%f", &salario);

	printf("digite o tempo de servico\n");
	scanf_s("%f", &tempo);

	if (tempo >= 5) {
		salario = salario * 1.2;
	}
	else {
		salario = salario * 1.1;
	}

	printf("o salario final foi %.2f \n", salario);


	printf("\n");
	system("pause");
	return 0;

}