/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
Faça um programa que carregue duas imagens diferentes no formato pgm. 
e tire a média de cada pixel e salve na posição equivalente em um terceiro arquivo pgm de resposta.

Detalhes de como funciona o formato pgm no link:
https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html

*/



#include<iostream>
using namespace std;
#include<string>
#include<fstream>



int main(int argc, char* argv[]) {
	int linha1 = 0, linha2 = 0, linha3 = 0;
	int coluna1 = 0, coluna2 = 0, coluna3 = 0;
	int maximo1 = 0, maximo2 = 0, maximo3 = 0;
	string temporaria;
	int pixel1 = 0, pixel2 = 0;
	int media = 0;
		
	if (argc < 4) {
		cout << "argumentos incorretos \ndigite o nome de 3 arquivos pgm \ndois para entrada e 1 para saida.\n\n";
		cout << "\n\n";
		system("pause");
		return 1;
	}

	ifstream arquivoe1(argv[1]);
	ifstream arquivoe2(argv[2]);
	ofstream arquivos(argv[3]);

	if ((!arquivoe1.good()) || (!arquivoe2.good())) {
		cout << "problema ao ler os arquivos de entrada.\nverifique se os nomes e/ou os caminhos estao corretos.\n\n";
		cout << "\n\n";
		system("pause");
		return 2;
	}
	
	arquivos << "P2\n# created by '" << argv[1] << "' and '" << argv[2] << "'" << endl;

	getline(arquivoe1, temporaria);
	getline(arquivoe2, temporaria);
	getline(arquivoe1, temporaria);
	getline(arquivoe2, temporaria);

	arquivoe1 >> linha1 >> coluna1 >> maximo1;
	arquivoe2 >> linha2 >> coluna2 >> maximo2;
	
	if (linha1 <= linha2) {
		linha3 = linha1;
	}
	else {
		linha3 = linha2;
	}

	if (coluna1 <= coluna2) {
		coluna3 = coluna1;
	}
	else {
		coluna3 = coluna2;
	}

	maximo3 = (maximo1 + maximo2) / 2;
	
  arquivos << linha3 << " " << coluna3 << endl;
  arquivos << maximo3 << endl;

	for (int iteracao = 0; iteracao < (linha3 * coluna3); iteracao = iteracao + 1) {
		arquivoe1 >> pixel1;
		arquivoe2 >> pixel2;
		media = (pixel1 + pixel2) / 2;
		arquivos << media;
		arquivos << " ";
	}

	cout << "\n\nas imagens foram mescladas com sucesso.\n";



	cout << "\n\n";
	system("pause");
	return 0;
}