#pragma once
#include <iostream>
#include <vector>
#include "Funcionario.h"

using namespace std;

class Departamento
{
private:
    vector<Funcionario *> funcionarios;

public:
    string nome;
    void cadastrarFuncionario(Funcionario *f)
    {
        funcionarios.push_back(f);
    }

    void listarFuncionarios()
    {
        cout << "Nome Departamento: " << nome << endl;
        for (Funcionario *f : funcionarios)
        {
            f->info();
        }
        cout << "-----------------" << endl;
    }

    Departamento(string _nome) : nome(_nome) {}

    void alterarSalarioManual() {
        int escolha = -999;
        float salariof = 0;

        cout << "\n\nDigite o novo salario: \n";
        cin >> salariof;
                
        cout << "Escolha o funcionario do qual deseja alterar o salario:\n\n";
        for (int iteracao = 0; iteracao < funcionarios.size(); iteracao = iteracao + 1) {
            //listar funcionarios
            cout << iteracao << ". \n";
            funcionarios[iteracao]->info();
            cout << "\n\n";
        }
        
        cout << "Digite o numero que corresponde ao funcionario escolhido: \n";
        cin >> escolha;

        cout << "\n\nO salario do(a) " << funcionarios[escolha]->nome << " foi alterado de " << funcionarios[escolha]->salario;

        funcionarios[escolha]->salario = salariof;

        cout << " para " << funcionarios[escolha]->salario << ".\n\n";

        system("pause");
    }

    void alterarSalarioAutomatico(float salariof, string nomef) {
        bool foiAlterado = false;
        for (int iteracao = 0; iteracao < funcionarios.size(); iteracao = iteracao + 1) {
            if (funcionarios[iteracao]->nome == nomef) {
                cout << "\n\nO salario do(a) " << funcionarios[iteracao]->nome << " foi alterado de " << funcionarios[iteracao]->salario << " para ";
                funcionarios[iteracao]->salario = salariof;
                cout << funcionarios[iteracao]->salario << "\n\n";
                foiAlterado = true;
            }
        }
        if (!foiAlterado) {
            cout << "\n\nNao foi possivel alterar o salario do(a) " << nomef << ", funcionario nao encontrado.\n\n";
        }
    }

    void aumentoParaTodosFuncionarios(float porcentagem) {
        for (int iteracao = 0; iteracao < funcionarios.size(); iteracao = iteracao + 1) {
            funcionarios[iteracao]->salario = funcionarios[iteracao]->salario * ((porcentagem + 100) / 100);
        }
    }

    Funcionario* getFuncionario(string nomef) {
        int iteracao = 0;
        while(iteracao < funcionarios.size()) {
            if (funcionarios[iteracao]->nome == nomef) {
                return funcionarios[iteracao];
            }
            iteracao = iteracao + 1;
        }
        return NULL;
    }

    void removerFuncionario(string nomef) {
        int funcionarioIndice = -9;
        
        for (int iteracao = 0; iteracao < funcionarios.size(); iteracao = iteracao + 1) {
            if (funcionarios[iteracao]->nome == nomef) {
                funcionarioIndice = iteracao;
            }
        }

        if (funcionarioIndice == -9) {
            cout << "\n\nErro. Funcionario nao encontrado.\n\n";
        }
        else {
            funcionarios.erase(funcionarios.begin() + funcionarioIndice);
        }
    }
};