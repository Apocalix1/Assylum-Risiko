// Classi.h - libreria delle classi di oggetti generali

#ifndef CLASSI_H
#define CLASSI_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ----------------------
// Personaggio
// ----------------------
class Razza; 

class Personaggio {
public:
    enum attributi {FORZA, DESTREZZA, COSTITUZIONE, INTELLIGENZA, SAGGEZZA, CARISMA};

    string nome;
    int forza;
    int destrezza;
    int costituzione;
    int intelligenza;
    int saggezza;
    int carisma;
    int CA;
    int modificatori[6];
    int livello;

    vector<string> abilita_razziali;

    Personaggio();

    void calcolo_modificatori();
    void stampa_statistiche() const;
    void assegnaRazza(Razza* r);
    void stampaAbilitaRazziali() const;
};

// ----------------------
// Party
// ----------------------
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

// ----------------------
// Razze
// ----------------------
class Razza {
public:
    string nomeRazza;
    int bonusForza = 0;
    int bonusDestrezza = 0;
    int bonusCostituzione = 0;
    int bonusIntelligenza = 0;
    int bonusSaggezza = 0;
    int bonusCarisma = 0;
    int velocita = 0;

    vector<string> abilitaRazza;

    Razza(const string& n) : nomeRazza(n) {}
    virtual void applicaBonus(Personaggio& p) const;
    virtual ~Razza() = default;
};

class Umano : public Razza {
public:
    Umano();
};

class Elfo : public Razza {
public:
    Elfo();
};

#endif 
