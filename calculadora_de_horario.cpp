/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio:
Crie uma classe Horario com 3 atributos do tipo int para representar 
hora/minuto/segundo e crie 3 métodos que adicionam hora/minuto/segundo 
respeitando os limites de 0-23 horas e 0-59 minutos e segundos. 
*/



#include<iostream>
using namespace std;

class Horario {
	public:
		int hora;
		int minuto;
		int segundo;

		void adicionarHora(int quantasHoras) {
			if ((hora + quantasHoras) < 24) {
				hora = hora + quantasHoras;

			}else if ((quantasHoras % 24) != 0 && quantasHoras != 0) {
				//hora = hora + ((quantasHoras % 24) - 1);
				//parametro;teoria;pratica;
				//24 0 0
				//25 1 0
				//48 0 0
				//46 22 21

				hora = hora + (quantasHoras % 24);
				//parametro;teoria;pratica;
				//24 0 0
				//25 1 1
				//48 0 0
				//46 22 22
			}
			else { hora = 0; }

		}

		void adicionarMinuto(int quantosMinutos) {
			if ((minuto + quantosMinutos) < 60) {
				minuto = minuto + quantosMinutos;

			}
			else if ((quantosMinutos % 60) != 0 && quantosMinutos != 0) {
				minuto = minuto + quantosMinutos % 60;
				adicionarHora(quantosMinutos / 60);
			}else{
				minuto = 0;
				adicionarHora(quantosMinutos / 60);
			}

		}

		void adicionarSegundo(int quantosSegundos) {
			if ((segundo + quantosSegundos) < 60) {
				segundo = segundo + quantosSegundos;

			}
			else if (quantosSegundos % 60 != 0 && quantosSegundos != 0) {
				segundo = segundo + quantosSegundos % 60;
				adicionarMinuto(quantosSegundos / 60);
			}
			else {
				minuto = 0;
				adicionarMinuto(quantosSegundos / 60);
			}
		}
};


int main() {

	Horario relogio = {0,2,3};
	
	//relogio.adicionarHora(1);
	//1:2:3
	

	relogio.adicionarHora(46);
	//22:2:3;
	relogio.adicionarMinuto(62);
	//1:4:3;
	//23:4:3;
	relogio.adicionarSegundo(67);
	//0:3:10;
	//23:5:10;
	
	cout << relogio.hora << ":" << relogio.minuto << ":" << relogio.segundo << endl;

	cout << "\n\n";
	system("pause");
	return 0;
}