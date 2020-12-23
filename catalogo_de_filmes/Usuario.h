#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include "Filme.h";

class Usuario {
public: 

	string login;
	string senha;

	Usuario(string loginf, string senhaf) {
		login = loginf;
		senha = senhaf;
	}

	~Usuario(){}

	Filme criar_filme(string nomef) {
		int ano;
		float nota;
		bool nota_valida = false;
		cout << "\nqual o ano de lancamento?\n";
		cin >> ano;

		do {
			cout << "\nque nota deseja atribuir?\n";
			cin >> nota;
			nota_valida = (nota < 0 || nota > 5);
			if (nota_valida) {
				cout << "\nessa nota nao e valida,\ndigite uma nota de 0 a 5.\n";
			}
		} while (nota_valida);

		return Filme(nomef, ano, this->login, nota);
		
	}

	void editar_filme(Filme* filmef) {
		int opcao = 0;
		string nome_novo;
		int ano_novo;
		float nota_nova;
		bool nota_valida;
		
		cout << "\neditando filme:\n\n";
		filmef->informar();
				
		cout << "\no que deseja fazer?\n\n1. editar filme.\n2. alterar nota.\n3. excluir nota.\n";
		do {
			cin >> opcao;
		} while (opcao != 1 && opcao != 2 && opcao != 3);
		
		switch (opcao) {
		case 1:
			
			if(filmef->usuario_que_criou == this->login){
				cout << "\nqual sera o novo nome do filme?\n";
				cin.ignore();
				getline(cin, nome_novo);

				cout << "\nqual sera o novo ano de lancamento?\n";
				cin >> ano_novo;

				filmef->nome = nome_novo;
				filmef->ano_de_lancamento = ano_novo;

			}
			else {
				cout << "\nsomente o usuario que criou pode editar o filme.\n";
			}
			
			break;

		case 2:
			if (filmef->notas[this->login] == NULL) {
				cout << "\nnota atual: nao atribuida\n";
			}else{ 
				cout << "\nnota atual: " << filmef->notas[this->login] << endl; 
			}
			
			do {
				cout << "\nque nota deseja atribuir?\n";
				cin >> nota_nova;
				nota_valida = (nota_nova < 0 || nota_nova > 5);
				if (nota_valida) {
					cout << "\nessa nota nao e valida,\ndigite uma nota de 0 a 5.\n";
				}
			} while (nota_valida);

			filmef->notas[this->login] = nota_nova;

			filmef->calcular_media();
			
			break;

		case 3:
			filmef->notas.erase(this->login);
			cout << "\nnota removida\n";

			break;

		default:
			cout << "\nopcao invalida.\n";
		}

	}

};