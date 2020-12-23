#pragma once
#include <iostream>

using namespace std;

class Funcionario
{
public:
    string nome;
    float salario;
    string dataAdmissao;

    Funcionario(string _nome, float _salario, string _dataAdmissao)
        : nome(_nome), salario(_salario), dataAdmissao(_dataAdmissao) {}

    void info()
    {
        cout << "Nome: " << nome << " salario: " << salario << " Data admissao: " << dataAdmissao << endl;
    }
};