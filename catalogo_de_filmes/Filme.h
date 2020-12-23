#pragma once
#include<iostream>
using namespace std;
#include<map>
#include "Usuario.h"

class Filme {
public:
	string nome;
	int ano_de_lancamento;
	string usuario_que_criou;
	float nota_media;

	map<string, float> notas;


	Filme(string nomef, int ano_de_lancamentof, string usuario_que_criouf, float notaf) {
		nome = nomef;
		ano_de_lancamento = ano_de_lancamentof;
		usuario_que_criou = usuario_que_criouf;
		notas[usuario_que_criou] = notaf;
		nota_media = notaf;
	}

	~Filme(){}

	void calcular_media() {
		float soma = 0;
		for (auto &iteracao : notas) {
			soma = soma + iteracao.second;
		}
		nota_media = (soma / notas.size());
	}

	void informar() {
		cout << "\nnome do filme: " << nome << endl;
		cout << "\nano de lancamento: " << ano_de_lancamento << endl;
		cout << "\nnota media: " << nota_media << endl;
	}
};
