//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visual studio community 2019
//exercicio: Fazer um programa para medir os reflexos do usuário. O programa deve:a)Mostrar a palavra “Agora!” após um tempo aleatório e um número, também aleatório;b)Mediro tempo até que o usuário digite o número pedido e mostrar esse tempo.Dica:  usar  a  função clockda  biblioteca  time.h.  Verifique  também  as funções rand, srandpara geração de números aleatórios.



#include <stdio.h>
//printf
//scanf_s
#include <stdlib.h>
//system pause
#include <time.h>
//rand
#include <Windows.h>
//sleep




// medidor de reflexo
// gera um numero aleatorio 
// aguarda um tempo aleatorio
// mede o tempo de resposta do usuario ao digita-lo

int main()
{
	int teste = 1, numeroaleatorio, tempoaleatorio, numeroresposta;
	float tempoderesposta;

	printf("\nteste de reflexo\n\n\n");
	printf("\nteste seu reflexo respondendo que numero aparece na tela apos a palavra: agora!\n\n");

	system("pause");
// pausa para aguardar o usuario a entender do que se trata o software

	while (teste == 1)
// executara o teste enquanto o usuario quiser
	{

		srand(time(NULL));
// inicializa o gerador de numeros aleatorios 

		numeroaleatorio = (rand() % 9);
// atribui o numero aleatorio de 0 a 9 na variavel escolhida
		
		
		tempoaleatorio = 3000 + (rand() % 12000);
		Sleep(tempoaleatorio);
		//gera um tempo aleatorio e pausa o programa durante este intervalo
				
		printf("\nagora!\n");
		printf("%i\n", numeroaleatorio);

		clock_t Ticks[2];
		Ticks[0] = clock();
// inicia o cronometro
		
		scanf_s("%i", &numeroresposta);

		while (numeroaleatorio != numeroresposta)
// repetira toda vez que o usuario errar a resposta
		{
			if (numeroaleatorio != numeroresposta)
			{
				printf("\nerrou!\ntente novamente\n");

				printf("\ndigite %i \n", numeroaleatorio);

				scanf_s("%i", &numeroresposta);
			}
		}

		Ticks[1] = clock();
		tempoderesposta = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
// encerra o cronometro apos o usuario acertar o numero
// calcula o intervalo de tempo
// atribui o intervalo de tempo em milisegundos a variavel
		
		if (tempoderesposta <= 15)
// avalia se o numero for acertado adivinhando antes de aparecer na tela
		{
			printf("voce trapaceou, digite o numero apos a palavra:\nagora!");
		}

		else
		{
		printf("\nacertou!\n");
		printf("seu reflexo foi de %g milisegundos", tempoderesposta);
		}
		



		printf("\n\ndeseja reiniciar o teste de reflexo?\n\n");
		printf("digite 1 para reiniciar\n");
		printf("digite qualquer outro numero para encerrar\n");
		scanf_s("%i", &teste);
// reinicia o teste se o usuario desejar

	}




	return 0;
}