/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
Leônidas é constante questionado 
sobre quantos soldados seus trezentos 
espartanos irão enfrentar.
Ajude Leônidas fazendo um pequeno jogo de adivinhação 
em que o jogador deve dar um palpite,
caso seja abaixo ou acima do valor correto 
imprima mensagens adequadas informando o fato.
(Valor correto deve ser: 10000)
*/



#include<iostream>
using namespace std;

int main() {
	int Numero = 10000;
	int Tentativa = 0;

	cout << "Advinhe o numero: \n";
	cin >> Tentativa;

	while (Numero != Tentativa) {
		if (Tentativa < Numero) {
			cout << "\nMais\n";
		}
		else if (Tentativa > Numero) {
			cout << "\nMenos\n";
		}
		
		cout << "\nTente outra vez: \n";
		cin >> Tentativa;
	}

	cout << "\nAcertou! \n";


		return 0;
}
