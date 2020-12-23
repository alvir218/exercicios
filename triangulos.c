#include <stdio.h>
#include <stdlib.h>

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Faça  um  algoritmo  que  receba  três  valores,representando  os  lados  de  um  triângulo fornecidos pelo usuário.Verifique se os valores formam um triânguloe classifique como:a.Equilátero (três lados iguais);b.Isósceles (dois lados iguais);c.Escaleno (três lados diferentes).Lembre-se de que, para formar um triangulo, nenhum dos lados pode ser igual a zero e um lado não pode ser maior do que a soma dos outros dois.

//analise de triangulos

int main()
{
float a, b, c;

printf("analise de triangulos\n\ninforme os lados do triangulo:\n\n");
printf("lado a:\n");
scanf_s("%f", &a);
printf("lado b:\n");
scanf_s("%f", &b);
printf("lado c:\n");
scanf_s("%f", &c);
if (a > 0 && b > 0 && c > 0 && c < a + b && b < a + c && a < b + c) 
{
	if (a == b || a == c)	// todos lados iguais
	{
		printf("\nequilatero\n");	// 2 lados iguais
	}
	else 
	{
		if (a == b || b == c || a == c)	// todos os lados diferentes
		{
			printf("\nisoceles\n");
		}
		else 
		{
			printf("\nescaleno\n");
		}
	}
}
else 
{
	printf("\ntriangulo invalido\n");
}




printf("\n");
system("pause");
return 0;
}