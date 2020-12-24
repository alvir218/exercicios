/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
revisao do uso de struct
vetor de struct sem alocacao dinamica
*/




#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int main() {

	struct Pessoa {
		char Nome[31];
		unsigned int Idade;
		float Peso;

	}; struct Pessoa Pessoas[99];

	unsigned int TamanhoDoCadastro = 0;

	cout << "Quantas pessoas deseja cadastrar? \n";
	cin >> TamanhoDoCadastro;

	for (unsigned int Iteracao = 0; Iteracao < TamanhoDoCadastro; Iteracao = Iteracao + 1) {
		cout << "\nQual o nome?\n";
		cin >> Pessoas[Iteracao].Nome;
		cout << "\nQual a idade?\n";
		cin >> Pessoas[Iteracao].Idade;
		cout << "\nQual o peso?\n";
		cin >> Pessoas[Iteracao].Peso;
	}

	for (unsigned int Iteracao = 0; Iteracao < TamanhoDoCadastro; Iteracao = Iteracao + 1) {
		cout << "\n\nNome: \n";
		cout << Pessoas[Iteracao].Nome;
		cout << "\n\nIdade: \n";
		cout << Pessoas[Iteracao].Idade;
		cout << "\n\nPeso: \n";
		cout << Pessoas[Iteracao].Peso;
	}

	cout << "\n\n";
	system("pause");
	return 0;
}