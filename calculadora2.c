//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Faça um algoritmo que apresenta na tela um menu parauma calculadora simples que recebe como entrada dois valores reais,e que realiza uma das 4 operaçõesabaixo. Se o usuáriodigitar  qualquer  opção  fora  das  4  operações  permitidas,  seu  algoritmo  deve tratar isso.a.adição(operação 1);b.subtração(operação 2);c.divisão (operação 3);d.multiplicação(operação 4).



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int operacao;
	float numero1, numero2;

	printf("calculadora\n\n\n");



	printf("escolha uma operacao\n\n");
	
	
	printf("1 adicao\n");
	printf("2 subtracao\n");
	printf("3 divisao\n");
	printf("4 multiplicacao\n");

	printf("\n\n");


	scanf_s("%i", &operacao);

	printf("digite o numero 1\n");
	scanf_s("%f", &numero1);
	printf("digite o numero 2\n");
	scanf_s("%f", &numero2);

	if (operacao = 1 || operacao = 2 || operacao = 3 || operacao = 4)
	{

		switch (operacao)
		{
		case 1:
			printf("a soma de %f mais %f e igual a: %f\n", numero1, numero2, numero1 + numero2);
			break;

		case 2:
			printf("a subtracao de %f menos %f e igual a: %f\n", numero1, numero2, numero1 - numero2);
			break;

		case 3:
			printf("a divisao de %f por %f e igual a: %f\n", numero1, numero2, numero1 / numero2);
			break;

		case 4:
			printf("a multiplicao de %f por %f e igual a: %f\n", numero1, numero2, numero1 * numero2);
			break;

		default:
			printf("\n\noperacao invalida\n\n");
			break;

		}
	}
	else
	{
		printf("operacao invalida");
	}
	
	}
printf("\n");
system("pause");
return 0;
}