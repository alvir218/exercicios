//allan stuart virmond ru:2379525

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Jogador
{
public:
    string nome;
    int vitoria, derrota, empate;
    vector<string> jaJogouCom;

    Jogador(string _nome)
        : nome(_nome), vitoria(0), derrota(0), empate(0)
    {}

    string jogar() {

        int v = rand() % 3;
        if (v == 0)
        {
            return "pedra";
        }
        else if (v == 1)
        {
            return "papel";
        }
        else
        {
            return "tesoura";
        }
    }

};
