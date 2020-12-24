/*
programador: allan stuart virmond
professor: vinicius pozzobon borin
instituicao de ensino: escola superior politecnica uninter
disciplina: estrutura de dados
ide: visual studio community 2019

exercicio: 
Criar um programa em linguagem C/C++ que realiza o cadastro de um sistema de provas.
Cada prova deverá ter um nome, que se refere a disciplina, e um horário de início e outro de fim,
com hora, minuto e segundo. Crie uma estrutura heterogênea
para cada prova e outra para a hora. Empregue alocação dinâmica.

Crie um menu onde o usuário terá 4 opções:
  1 - Inserir novo registro
  2 - Listar registros em ordem de cadastro
  3 - Listar registros em ordem inversa ao de cadastro
  4 - Sair

Crie uma função separada para cada recurso do programa.
*/



//reparando com alocaçao dinamica

#include<iostream>
#include<vector>

using namespace std;

struct CadastroDeHorario {
	unsigned int HoraInicio;
	unsigned int MinutoInicio;
	unsigned int SegundoInicio;
	unsigned int HoraFim;
	unsigned int MinutoFim;
	unsigned int SegundoFim;

};

struct CadastroDeDisciplina {
	char Disciplina[56];

	struct CadastroDeHorario Horarios;
};

void InserirNovoRegistro(vector<CadastroDeDisciplina> &CadastrosF);

void ExibirPorOrdemDeCadastro(vector<CadastroDeDisciplina> &CadastrosF);

void ExibirPorOrdemReversaDeCadastro(vector<CadastroDeDisciplina> &CadastrosF);


int main() {

	unsigned int Menu = 0;

	vector<CadastroDeDisciplina> Cadastros;


	do {
		cout << "\n\n";
		system("pause");
		system("cls");
		cout << "Escolha uma opcao: \n\n1- Inserir novo registro\n\n2- Listar registros em ordem de cadastro\n\n3- Listar registros em ordem reversa de cadastro\n\n4- Sair\n\n";
		cin >> Menu;

		switch (Menu) {

		case 1:
			InserirNovoRegistro(Cadastros);

			break;

		case 2:
			ExibirPorOrdemDeCadastro(Cadastros);

			break;

		case 3:
			ExibirPorOrdemReversaDeCadastro(Cadastros);

			break;
		}


	} while (Menu != 4);

	system("pause");

	return 0;
}



void InserirNovoRegistro(vector<CadastroDeDisciplina> &CadastrosF) {
	CadastroDeDisciplina CadastroTemp;
	
	system("cls");

	cout << "Digite o nome da disciplina: \n";
	cin >> CadastroTemp.Disciplina;

	cout << "\n\nDigite a hora de inicio:\n";
	cin >> CadastroTemp.Horarios.HoraInicio;

	cout << "\n\nDigite o minuto de inicio:\n";
	cin >> CadastroTemp.Horarios.MinutoInicio;

	cout << "\n\nDigite o segundo de inicio:\n";
	cin >> CadastroTemp.Horarios.SegundoInicio;

	cout << "\n\nDigite a hora do encerramento:\n";
	cin >> CadastroTemp.Horarios.HoraFim;

	cout << "\n\nDigite o minuto de encerramento:\n";
	cin >> CadastroTemp.Horarios.MinutoFim;

	cout << "\n\nDigite o segundo de encerramento:\n";
	cin >> CadastroTemp.Horarios.SegundoFim;

	CadastrosF.push_back(CadastroTemp);
}



void ExibirPorOrdemDeCadastro(vector<CadastroDeDisciplina> &CadastrosF) {
	system("cls");
	cout << "Exibindo por ordem de cadastro...\n\n";
	for (unsigned int Iteracao = 0; Iteracao < CadastrosF.size(); Iteracao = Iteracao + 1) {
		cout << "\nDisciplina: \n" << CadastrosF[Iteracao].Disciplina << endl;
		cout << "\nHora de inicio: \n";
		cout << CadastrosF[Iteracao].Horarios.HoraInicio << ":"
			<< CadastrosF[Iteracao].Horarios.MinutoInicio << ":"
			<< CadastrosF[Iteracao].Horarios.SegundoInicio<< "\n";

		cout << "\nHora de encerramento: \n";
		cout << CadastrosF[Iteracao].Horarios.HoraFim << ":"
			<< CadastrosF[Iteracao].Horarios.MinutoFim << ":"
			<< CadastrosF[Iteracao].Horarios.SegundoFim << "\n";
	}
}



void ExibirPorOrdemReversaDeCadastro(vector<CadastroDeDisciplina> &CadastrosF) {
	system("cls");
	cout << "Exibindo por ordem inversa de cadastro...\n\n";
	for (int Iteracao = (CadastrosF.size() - 1); Iteracao >= 0; Iteracao = Iteracao - 1) {
		cout << "\nDisciplina: \n" << CadastrosF[Iteracao].Disciplina << endl;
		cout << "\nHora de inicio: \n";
		cout << CadastrosF[Iteracao].Horarios.HoraInicio << ":"
			<< CadastrosF[Iteracao].Horarios.MinutoInicio << ":"
			<< CadastrosF[Iteracao].Horarios.SegundoInicio << "\n";

		cout << "\nHora de encerramento: \n";
		cout << CadastrosF[Iteracao].Horarios.HoraFim << ":"
			<< CadastrosF[Iteracao].Horarios.MinutoFim << ":"
			<< CadastrosF[Iteracao].Horarios.SegundoFim << "\n";
	}

}