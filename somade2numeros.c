//programador: allan stuart virmond
//ide: visual studio community 2019
//exercicio: soma de dois numeros, exemplo de operacao aritmetica

#include<stdio.h> 
 
// Fun��o principal - main()
int main()
{
    // Declara��o de vari�veis
    int A, B, soma;
 
    // Entrada dos dados
    printf("Informe o valor de A:");
    scanf("%d", &A);
 
    printf("Informe o valor de B:");
    scanf("%d", &B);
 
    // C�lculo da soma de A + B
    soma = A + B;
 
    // Exibe o resultado
    printf("\nSoma = %d\n", soma);
 
    // Retorno da fun��o main()
    return 0;
}