/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
Desenvolva um programa que leia todas 
as palavras de um arquivo de texto e 
diga quais e quantas ocorrências 
existem de cada palavra.
*/



#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<map>


int main() {
	string temporaria;
	map<string, int> histograma;

	ifstream arquivol("nomes.txt");
	
	if (!arquivol.good()) {
		cout << "erro ao ler arquivo.\n\n";
	}

	while (!arquivol.eof()) {
		arquivol >> temporaria;
		histograma[temporaria] = histograma[temporaria] + 1;
	}

	for (auto iteracao = histograma.cbegin(); iteracao != histograma.cend(); iteracao++) {
		cout << iteracao->first << " : " << iteracao->second << endl;
	}




	cout << "\n\n";
	system("pause");
	return 0;
}