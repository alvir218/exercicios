#pragma once
#include <iostream>
#include <vector>
#include "Departamento.h"

using namespace std;

class Empresa
{
private:
    vector<Departamento *> departamentos;

public:
    string nome, cnpj;

    void cadastrarDepartamento(Departamento *d)
    {
        departamentos.push_back(d);
    }

    void listarDepartamentos()
    {
        cout << "Nome da Empresa: " << nome << endl;
        for (Departamento *d : departamentos)
        {
            d->listarFuncionarios();
        }
    }

    Empresa(string _nome, string _cnpj) : nome(_nome), cnpj(_cnpj) {}

    void transferirFuncionario(string departamentoDestino, string departamentoOrigem, string nomef) {
        int departamentoOrigemIndice = -9;
        int departamentoDestinoIndice = -9;
        //int funcionarioIndice = -9;
        //Funcionario funcionarioAux("aux", 1234, "01/02/03");
        Funcionario* funcionarioAux;
                
        for (int iteracao = 0; iteracao < departamentos.size(); iteracao = iteracao + 1) {
            if (departamentos[iteracao]->nome == departamentoOrigem) {
                departamentoOrigemIndice = iteracao;
            }
        }

        for (int iteracao = 0; iteracao < departamentos.size(); iteracao = iteracao + 1) {
            if (departamentos[iteracao]->nome == departamentoDestino) {
                departamentoDestinoIndice = iteracao;
            }
        }

        if (departamentoOrigemIndice == -9 || departamentoDestinoIndice == -9) {
            cout << "\n\nErro ao transferir funcionario de departamento. Departamento nao encontrado.\n\n";
            return;
        }

        funcionarioAux = departamentos[departamentoOrigemIndice]->getFuncionario(nomef);

        if (funcionarioAux == NULL) {
            cout << "\n\nErro ao transferir funcionario de departamento. Funcionario nao encontrado.\n\n";
            return;
        }
        else {
            departamentos[departamentoDestinoIndice]->cadastrarFuncionario(funcionarioAux);
            departamentos[departamentoOrigemIndice]->removerFuncionario(nomef);
        }

        cout << "\n\nFuncionario " << nomef << " transferido do departamento " << departamentoOrigem << " para " << departamentoDestino << " \n\n";
    }
};