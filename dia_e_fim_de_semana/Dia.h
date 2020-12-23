#pragma once
#include<iostream>
using namespace std;

enum Dia_da_semana {
	domingo = 1,
	segunda,
	terca,
	quarta,
	quinta,
	sexta,
	sabado
};

class Dia {
public:
	int dia;
	int mes;
	int ano;
	enum Dia_da_semana feira;

	Dia(int diaf, int mesf, int anof, enum Dia_da_semana feiraf) {
		dia = diaf;
		mes = mesf;
		ano = anof;
		feira = feiraf;
		
	}

	void info() {
		cout << "\nhoje e dia: " << dia << "/" << mes << "/" << ano << endl;

		if (feira == sabado || feira == domingo) {
			cout << "tenha um otimo fim de semana.\n";
		}
	}
};


