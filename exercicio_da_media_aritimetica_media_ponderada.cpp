/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
classe que calcula a media aritmetica e media ponderada
*/



#include<iostream>

using namespace std;

class Avaliacao {
	public:
		float nota1;
		float nota2;
		float nota3;

		float calcularMediaAritmetica() {
			cout << "\na media aritmetica e: \n";
			return ((nota1 + nota2 + nota3) / 3);
		}

		float calcularMediaPonderada() {
			cout << "\na media ponderada e: \n";
			return ((nota1 * 2) + (nota2 * 3) + (nota3 * 4) / 9);
		}

};


int main() {

	Avaliacao avaliacao1 = { 7,8,8.5 };

	cout << "\ncalculando media aritmetica...\n\n" << avaliacao1.calcularMediaAritmetica() << endl;
		

	cout << "\ncalculando media ponderada...\n\n" << avaliacao1.calcularMediaPonderada() << endl;


	cout << "\n\n";
	system("pause");
}