/*
programador: allan stuart virmond
professor: leonardo gomes
instituicao de ensino: escola superior politecnica uninter
disciplina: programacao orientada a objetos
ide: visual studio community 2019

exercicio: 
algoritmo de um sistema de conta bancaria
classe com saque, deposito e transferencia pra outra conta
*/



#include<iostream>
using namespace std;

class Conta {
	public:
		int numero;
		string dono;
		float saldo;
		float limite;

		bool sacar(int quantoSacar) {
			if (saldo + limite >= quantoSacar) {
				saldo = (saldo - quantoSacar);
				
				if (saldo < 0) {
					limite = limite + saldo;
				}

				return true;
			}

			else {
				cout << "\nsaldo insuficiente.\n";
				return false;
			}
		}

		bool depositar(int quantoDepositar) {
			saldo = saldo + quantoDepositar;
			return true;
		}

		void info() {
			cout << "\nconta numero: \n" << numero << endl;
			cout << "\ntitular: \n" << dono << endl;
			cout << "\nsaldo: \n" << saldo << endl;
			cout << "\nlimite: \n" << limite << endl;
			cout << "\ntotal disponivel: \n" << saldo + limite << endl;
		}
		
		bool transferir(Conta &origem, Conta &destino, int quantoTransferir) {
			if ((origem.saldo + origem.limite) >= quantoTransferir) {
				origem.saldo = (origem.saldo - quantoTransferir);
				
				if (origem.saldo < 0) {
					origem.limite = origem.limite + saldo;
				}

				destino.saldo = destino.saldo + quantoTransferir;

				return true;
			}
			else {
				cout << "\nsaldo insuficiente\n";
			}
		}
};


int main() {

	Conta mario { 123, "super mario", 1500, 500 };
	Conta luigi{ 124, "super luigi", 1600, 500 };

	
	mario.info();
	cout << "\n\n";
	luigi.info();
	cout << "\n\n";
	

	mario.depositar(300);
	luigi.depositar(250);
	
	mario.info();
	cout << "\n\n";
	luigi.info();
	cout << "\n\n";
	
	mario.transferir(mario, luigi, 700);
	
	mario.info();
	cout << "\n\n";
	luigi.info();
	cout << "\n\n";
	
	luigi.transferir(luigi, mario, 600);
	
	mario.info();
	cout << "\n\n";
	luigi.info();
	cout << "\n\n";
	

	mario.sacar(2100);
	//saldo -400
	//limite 100

	cout << "\n\n";
	system("pause");
}