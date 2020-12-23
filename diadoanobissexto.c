//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Escreva um programa para receber do usuário um mês (de 1 a 12) e um ano (de 0 D.C. em diante) e mostrar o número de dias daquele mês daquele ano. Não esqueça de levar em consideração anos bissextos para o cálculo



#include <stdio.h>
// printf
// scan_s
#include <stdlib.h>
// system pause
int main()
{
    int mes;
    unsigned int ano;
// balanceado em uso de memoria e uso do programa

    printf("\ncalendario\n\n");
    printf("\nexibe os dias do mes do ano escolhido\n");
    printf("\no ano deve estar no intervalo entre 0 d.c. e 4294967295 d.c.\n");
    
    printf("\ndigite o ano desejado\n");
    scanf_s("%u",&ano);

    printf("\ndigite o mes desejado\n");
    scanf_s("%i", &mes);

    while ((mes != 1) && (mes != 2) && (mes != 3) && (mes != 4) && (mes != 5) && (mes != 6) && (mes != 7) && (mes != 8) && (mes != 9) && (mes != 10) && (mes != 11) && (mes != 12))
// obriga o usuario a digitar um mes valido    
    {
        printf("\nmes invalido\n");
        printf("\ndigite o mes desejado\n");
        scanf_s("%i", &mes);
    }
    
    printf("\nano: %u \nmes: %i \n\n",ano,mes);


    if ( ((ano % 100) == 0) && ((ano % 400) == 0) )
// ano bissexto regra: anos multiplos de 100 e 400 sao anos bissextos
    {
        
        switch (mes)
        {
            case 1:
                printf("\njaneiro tem 31 dias\n\n");
                    
                break;
            

            case 2:
                printf("\ne ano bissexto, fevereiro tem 29 dias\n\n");

                break;
            

            case 3:
                printf("\nmarco tem 31 dias\n\n");

                break;


            case 4:
                printf("\nabril tem 30 dias\n\n");

                break;
            
            
            case 5:
                printf("\nmaio tem 31 dias\n\n");

                break;


            case 6:
                printf("\njunho tem 30 dias\n\n");

                break;


            case 7:
                printf("\njulho tem 31 dias\n\n");

                break;


            case 8:
                printf("\nagosto tem 31 dias\n\n");

                break;


            case 9:
                printf("\nsetembro tem 30 dias\n\n");

                break;


            case 10:
                printf("\noutubro tem 31 dias\n\n");

                break;


            case 11:
                printf("\nnovembro tem 30 dias\n\n");
                
                break;


            case 12:
                printf("\ndezembro tem 31 dias\n\n");

                break;


            default:
                printf("\nmes invalido\n");
        }


    }

    else
    {
        if (((ano % 100) == 0))
// nao e ano bissexto regra: anos multiplos de 100 nao sao anos bissextos
        {

            switch (mes)
            {
                case 1:
                    printf("\njaneiro tem 31 dias\n\n");

                break;


                case 2:
                    printf("\nnao e ano bissexto, fevereiro tem 28 dias\n\n");

                break;


                case 3:
                    printf("\nmarco tem 31 dias\n\n");

                break;


                case 4:
                    printf("\nabril tem 30 dias\n\n");

                break;


                case 5:
                    printf("\nmaio tem 31 dias\n\n");

                break;


                case 6:
                    printf("\njunho tem 30 dias\n\n");

                break;


                case 7:
                    printf("\njulho tem 31 dias\n\n");

                break;


                case 8:
                    printf("\nagosto tem 31 dias\n\n");

                break;


                case 9:
                    printf("\nsetembro tem 30 dias\n\n");

                break;


                case 10:
                    printf("\noutubro tem 31 dias\n\n");

                break;


                case 11:
                    printf("\nnovembro tem 30 dias\n\n");

                break;


                case 12:
                    printf("\ndezembro tem 31 dias\n\n");

                break;


                default:
                    printf("\nmes invalido\n");
            
            }
        }
        
        else
        {
            if (((ano % 4) == 0))
//ano bissesto regra: anos multiplos de 4 sao anos bissextos
            {

                switch (mes)
                {
                    case 1:
                        printf("\njaneiro tem 31 dias\n\n");

                    break;


                    case 2:
                        printf("\ne ano bissexto, fevereiro tem 29 dias\n\n");

                    break;


                    case 3:
                        printf("\nmarco tem 31 dias\n\n");

                    break;


                    case 4:
                        printf("\nabril tem 30 dias\n\n");

                    break;


                    case 5:
                        printf("\nmaio tem 31 dias\n\n");

                    break;


                    case 6:
                        printf("\njunho tem 30 dias\n\n");

                    break;


                    case 7:
                        printf("\njulho tem 31 dias\n\n");

                    break;


                    case 8:
                        printf("\nagosto tem 31 dias\n\n");

                    break;


                    case 9:
                        printf("\nsetembro tem 30 dias\n\n");

                    break;


                    case 10:
                        printf("\noutubro tem 31 dias\n\n");

                    break;


                    case 11:
                        printf("\nnovembro tem 30 dias\n\n");

                    break;


                    case 12:
                        printf("\ndezembro tem 31 dias\n\n");

                    break;


                    default:
                        printf("\nmes invalido\n");
                }

            }

        }
    }




system("pause");
return 0;
}
