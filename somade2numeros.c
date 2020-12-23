//programador: allan stuart virmond
//ide: visual studio community 2019
//exercicio: soma de dois numeros, exemplo de operacao aritmetica

#include<stdio.h> 
 
// Função principal - main()
int main()
{
    // Declaração de variáveis
    int A, B, soma;
 
    // Entrada dos dados
    printf("Informe o valor de A:");
    scanf("%d", &A);
 
    printf("Informe o valor de B:");
    scanf("%d", &B);
 
    // Cálculo da soma de A + B
    soma = A + B;
 
    // Exibe o resultado
    printf("\nSoma = %d\n", soma);
 
    // Retorno da função main()
    return 0;
}