/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
Faça um função/método que receba 2 arrays de strings. E devolva um único array contendo todos os elementos dos dois arrays ordenados.
Utilizando a função anterior combine 4 arrays. (utilize a função mas não faça modificações no código da mesma para receber mais parâmetros) 
*/



#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

void Concatenar(vector<string>* pListaCombinada, vector<string> Lista2);

int main() {

	vector<string> Mario = { "Mario", "Toad", "Koopa", "Peach", "Bowser" };
	vector<string> Mortal = { "SubZero", "Kano", "Sonia", "Kitana", "Strike", "Scorpion" };
	vector<string> Rrr = { "Grinder", "Snake", "Buthcer", "Flash", "Roadkill" };
	vector<string> Kong = { "Didy", "Dixie", "Crancky", "Donkey" };
	vector<string> ListaCombinada;

	//one.insert(one.end(), two.begin(), two.end());

	Concatenar(&ListaCombinada, Mario);
	Concatenar(&ListaCombinada, Mortal);
	Concatenar(&ListaCombinada, Rrr);
	Concatenar(&ListaCombinada, Kong);

	cout << "Imprimindo a lista toda...\n\n";

	for (string Temporario : ListaCombinada) {
		cout << Temporario << "\n";
	}


	cout << "\n\n";
	system("pause");
	return 0;
}


void Concatenar(vector<string>* pListaCombinada, vector<string> Lista2){
	pListaCombinada->insert(pListaCombinada->end(), Lista2.begin(), Lista2.end());
	sort(pListaCombinada->begin(), pListaCombinada->end());

}
