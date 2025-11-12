#include <iostream>
#include "Classi.h"
#include "Libreria.h"


int main() {
    Party party1;

    // Crea il party completo con nomi e punti da spendere
    party1.creaPartyCompleto();

    cout << "\nMembri e statistiche del party " << party1.nomeParty << ":\n";
    party1.stampaStatistiche();

    Party party2;

    // Crea il party completo con nomi e punti da spendere
    party2.creaPartyCompleto();

    cout << "\nMembri e statistiche del party " << party2.nomeParty << ":\n";
    party2.stampaStatistiche();

    return 0;
}