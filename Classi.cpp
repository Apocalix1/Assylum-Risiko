#include "Classi.h"
#include "Libreria.h"
#include <limits>

    void Personaggio::calcolo_modificatori()
    {
        modificatori[FORZA] = ((forza - 10) / 2);
        modificatori[DESTREZZA] = ((destrezza - 10) / 2);
        modificatori[COSTITUZIONE] = ((costituzione - 10) / 2);
        modificatori[INTELLIGENZA] = ((intelligenza - 10) / 2);
        modificatori[SAGGEZZA] = ((saggezza - 10) / 2);
        modificatori[CARISMA] = ((carisma - 10) / 2);
    }

    void Personaggio::stampa_statistiche() const
    {
        cout << "Nome: " << nome << endl;
        cout << "FORZA: " << forza << " (mod: " << modificatori[FORZA] << ")" << endl;
        cout << "DESTREZZA: " << destrezza << " (mod: " << modificatori[DESTREZZA] << ")" << endl;
        cout << "COSTITUZIONE: " << costituzione << " (mod: " << modificatori[COSTITUZIONE] << ")" << endl;
        cout << "INTELLIGENZA: " << intelligenza << " (mod: " << modificatori[INTELLIGENZA] << ")" << endl;
        cout << "SAGGEZZA: " << saggezza << " (mod: " << modificatori[SAGGEZZA] << ")" << endl;
        cout << "CARISMA: " << carisma << " (mod: " << modificatori[CARISMA] << ")" << endl;
        cout << "Velocità: " << velocita << endl;
        cout << "CA: " << CA << endl;
    }

    Personaggio::Personaggio()
    {
        nome = " ";
        forza = 6;
        destrezza = 6;
        costituzione = 6;
        intelligenza = 6;
        saggezza = 6;
        carisma = 6;
        calcolo_modificatori();
        velocita = 9;
        CA = 9 + modificatori[DESTREZZA];
    }

// ----------------------
// Party
// ----------------------
void Party::aggiungiMembro(const Personaggio& p) {
    if (membri.size() < MAX_MEMBRI) {
        membri.push_back(p);
        cout << p.nome << " aggiunto al party." << endl;
    } else {
        cout << "Party pieno! Impossibile aggiungere " << p.nome << "." << endl;
    }
}

void Party::rimuoviMembro(int indice) {
    if (indice >= 0 && indice < membri.size()) {
        cout << membri[indice].nome << " rimosso dal party." << endl;
        membri.erase(membri.begin() + indice);
    } else {
        cout << "Indice non valido." << endl;
    }
}

void Party::stampaMembri() const {
    cout << "Membri del party:" << endl;
    for (int i = 0; i < membri.size(); i++)
        cout << i + 1 << ". " << membri[i].nome << endl;
}

void Party::stampaStatistiche() const {
    cout << "Statistiche dei membri:" << endl;
    for (int i = 0; i < membri.size(); i++) {
        const Personaggio& p = membri[i]; // riferimento costante
        p.stampa_statistiche();
        cout << "------------------------" << endl;
    }
}

int Party::numeroMembri() const {
    return membri.size();
}

void Party::creaPartyCompleto() {
    cout << "Inserisci il nome del party: ";
    getline(cin, nomeParty);

   int nMembri = 0;
    while (true) {
        cout << "Quanti membri vuoi nel party? (1-6): ";
        if (!(cin >> nMembri) || nMembri < 1 || nMembri > MAX_MEMBRI) {
            cout << "Numero non valido. Riprova!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    // Pulisci il buffer prima dei nomi dei personaggi
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < nMembri; i++) {
        Personaggio p;

        cout << "Inserisci il nome del personaggio " << i + 1 << ": ";
        getline(cin, p.nome);

        int puntiDaSpendere = 30;
        spendere_punti(p, puntiDaSpendere);

        aggiungiMembro(p);
    }
}
