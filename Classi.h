//libreria delle classi

#ifndef CLASSI_H
#define CLASSI_H

#include <iostream>
#include <string>
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
    };

#endif