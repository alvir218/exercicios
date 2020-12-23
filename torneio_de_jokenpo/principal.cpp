//allan stuart virmond ru:2379525

#include <iostream>
#include <vector>
#include <ctime>
#include "Jogador.h"

using namespace std;

void enfrentar(Jogador& jogadorA, Jogador& jogadorB);

bool jaSeEnfrentaram(const Jogador& jogador, const Jogador& jogadorB);


int main()
{
    srand(time(NULL));

    int maisVitorias = -1;
    int menosDerrotas = 32766;
    int menosEmpates = 32766;
    int menosDerrotas2 = 32766;
    int menosEmpates2 = 32766;
    vector<Jogador> jogadores;
    vector<int> empatouVitorias;
    vector<int> empatouDerrotas;
    vector<int> empatouEmpates;
    vector<int> empatouVitoriasEDerrotas;
    vector<int> empatouVitoriasEDerrotasEEmpates;


        //registrando jogadores do torneio
    jogadores.push_back(Jogador("Mario"));
    jogadores.push_back(Jogador("Luigi"));
    jogadores.push_back(Jogador("Bowser"));
    jogadores.push_back(Jogador("Yoshi"));
    jogadores.push_back(Jogador("Peach"));
    jogadores.push_back(Jogador("Koopa"));
    jogadores.push_back(Jogador("Donkey"));
    jogadores.push_back(Jogador("Toad"));
    jogadores.push_back(Jogador("Wario"));
    jogadores.push_back(Jogador("Geno"));
    jogadores.push_back(Jogador("Mallow"));

        //faz todos se enfrentarem
    for (int iteracao1 = 0; iteracao1 < jogadores.size(); iteracao1 = iteracao1 + 1) {
        for (int iteracao2 = 0; iteracao2 < jogadores.size(); iteracao2 = iteracao2 + 1) {
            if (iteracao1 == iteracao2) {
                continue;
            }
            else if (jaSeEnfrentaram(jogadores[iteracao1], jogadores[iteracao2]) == false) {
                enfrentar(jogadores[iteracao1], jogadores[iteracao2]);
            }

        }
    }
    
        //obtem os melhores resultados
    for (int iteracao = 0; iteracao < jogadores.size(); iteracao = iteracao + 1) {
        if (jogadores[iteracao].vitoria > maisVitorias) {
            maisVitorias = jogadores[iteracao].vitoria;
        }
        if (jogadores[iteracao].empate < menosEmpates) {
            menosEmpates = jogadores[iteracao].empate;
        }
        if (jogadores[iteracao].derrota < menosDerrotas) {
            menosDerrotas = jogadores[iteracao].derrota;
        }
    }
        //obtem os criterios de avaliacao
    for (int iteracao = 0; iteracao < jogadores.size(); iteracao = iteracao + 1) {
        if (jogadores[iteracao].vitoria == maisVitorias) {
            empatouVitorias.push_back(iteracao);
        }
        if (jogadores[iteracao].empate == menosEmpates) {
            empatouEmpates.push_back(iteracao);
        }
        if (jogadores[iteracao].derrota == menosDerrotas) {
            empatouDerrotas.push_back(iteracao);
        }

    }
        //se so houver um vencedor venceu o torneio
        //se nao os obtem os criterios de desempate
        //mais vitorias
        //menos derrotas
        //menos empates
    if (empatouVitorias.size() == 1) {
        cout << "o jogador " << jogadores[empatouVitorias[0]].nome << " venceu\n\n";
    }
    else {
            //mais vitorias e menos derrotas
        for (int iteracao = 0; iteracao < empatouVitorias.size(); iteracao = iteracao + 1) {
            if (jogadores[empatouVitorias[iteracao]].derrota < menosDerrotas2) {
                menosDerrotas2 = jogadores[empatouVitorias[iteracao]].derrota;
            }
        }
        for (int iteracao = 0; iteracao < empatouVitorias.size(); iteracao = iteracao + 1) {
            if (jogadores[empatouVitorias[iteracao]].derrota == menosDerrotas2) {
                empatouVitoriasEDerrotas.push_back(empatouVitorias[iteracao]);
            }
        }
        if (empatouVitoriasEDerrotas.size() == 1) {
            cout << "\n\no jogador " << jogadores[empatouVitoriasEDerrotas[0]].nome << " venceu \n\n";
        }
        else {
                //mais vitorias, menos derrotas
            for (int iteracao = 0; iteracao < empatouVitoriasEDerrotas.size(); iteracao = iteracao + 1) {
                if (jogadores[empatouVitoriasEDerrotas[iteracao]].empate < menosEmpates2) {
                    menosEmpates2 = jogadores[empatouVitoriasEDerrotas[iteracao]].empate;
                }
            }
            for (int iteracao = 0; iteracao < empatouVitoriasEDerrotas.size(); iteracao = iteracao + 1) {
                if(jogadores[empatouVitoriasEDerrotas[iteracao]].empate == menosEmpates2){
                    empatouVitoriasEDerrotasEEmpates.push_back(empatouVitoriasEDerrotas[iteracao]);
                }
            }
            if (empatouVitoriasEDerrotasEEmpates.size() == 1) {
                cout << "\n\no jogador " << jogadores[empatouVitoriasEDerrotasEEmpates[0]].nome << " venceu\n\n";
            }
            else {
                    //empate tecnico
                cout << "\n\nhouve empate tecnico entre os seguintes jogadores: \n";
                for (int iteracao = 0; iteracao < empatouVitoriasEDerrotasEEmpates.size(); iteracao = iteracao + 1) {
                    cout << "\n" << jogadores[empatouVitoriasEDerrotasEEmpates[iteracao]].nome;
                }
            }
        }
    }

    cout << "\n\n";
    system("pause");
    return 0;
}



void enfrentar(Jogador& jogadorA, Jogador& jogadorB) {
    jogadorA.jaJogouCom.push_back(jogadorB.nome);
    jogadorB.jaJogouCom.push_back(jogadorA.nome);

    string jogadaA = jogadorA.jogar();
    string jogadaB = jogadorB.jogar();

    if ((jogadaA == "pedra" && jogadaB == "tesoura") || (jogadaA == "papel" && jogadaB == "pedra") || (jogadaA == "tesoura" && jogadaB == "papel")) {
        jogadorA.vitoria = jogadorA.vitoria + 1;
        jogadorB.derrota = jogadorB.derrota + 1;

    }
    else if ((jogadaA == "pedra" && jogadaB == "papel") || (jogadaA == "tesoura" && jogadaB == "pedra") || (jogadaA == "papel" && jogadaB == "tesoura")) {
        jogadorA.derrota = jogadorA.derrota + 1;
        jogadorB.vitoria = jogadorB.vitoria + 1;
    }
    else {
        jogadorA.empate = jogadorA.empate + 1;
        jogadorB.empate = jogadorB.empate + 1;
    }

}

bool jaSeEnfrentaram(const Jogador& jogadorA, const Jogador& jogadorB) {
    bool jaJogaram = false;
    for (int iteracao = 0; iteracao < jogadorA.jaJogouCom.size(); iteracao = iteracao + 1) {
        if (jogadorA.jaJogouCom[iteracao] == jogadorB.nome) {
            jaJogaram = true;
        }
    }
    return jaJogaram;
}