//libreria delle classi

#ifndef CLASSI_H
#define CLASSI_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//classi giocatori e stati
class Personaggio {
    public:
    enum attributi {FORZA, DESTREZZA, COSTITUZIONE, INTELLIGENZA, SAGGEZZA, CARISMA};
    std::string nome;
    int forza;
    int destrezza;
    int costituzione;
    int intelligenza;
    int saggezza;
    int carisma;
    int velocita;
    int CA;
    int modificatori[6];

    void calcolo_modificatori();
    void stampa_statistiche() const;
    Personaggio();
    };


class Party {
private:
    vector<Personaggio> membri;
    const int MAX_MEMBRI = 6;

public:
    string nomeParty; 
    void aggiungiMembro(const Personaggio& p);
    void rimuoviMembro(int indice);
    void stampaMembri() const;
    void stampaStatistiche() const;
    int numeroMembri() const;
    void creaPartyCompleto();
};

#endif