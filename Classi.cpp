#include "Classi.h"
#include "Libreria.h"
#include <iostream>
#include <limits>

// ----------------------
// Personaggio
// ----------------------
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
    CA = 8 + modificatori[DESTREZZA];
    livello = 1;
}

void Personaggio::calcolo_modificatori()
{
    modificatori[FORZA] = (forza - 10) / 2;
    modificatori[DESTREZZA] = (destrezza - 10) / 2;
    modificatori[COSTITUZIONE] = (costituzione - 10) / 2;
    modificatori[INTELLIGENZA] = (intelligenza - 10) / 2;
    modificatori[SAGGEZZA] = (saggezza - 10) / 2;
    modificatori[CARISMA] = (carisma - 10) / 2;
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
    cout << "CA: " << CA << endl<<endl;
    stampaAbilitaRazziali();
}

void Personaggio::assegnaRazza(Razza* r)
{
    if (!r) return;
    r->applicaBonus(*this);
}

void Personaggio::stampaAbilitaRazziali() const
{
    if (abilita_razziali.empty()) {
        cout << "Nessuna abilità razziale.\n";
        return;
    }

    cout << "Abilità razziali di " << nome << ":\n";
    for (const auto& abilita : abilita_razziali) {
        cout << "- " << abilita << "\n";
    }
}

// ----------------------
// Party
// ----------------------

void Party::creaPartyCompleto()
{
    cout << "Inserisci il nome del party: ";
    getline(cin, nomeParty);

    int nMembri = 0;
    while (true) {
            cout << "Quanti membri vuoi nel party? (max " << MAX_MEMBRI << "): ";
            if (!(cin >> nMembri) || nMembri < 1 || nMembri > MAX_MEMBRI) {
                cout << "Input non valido! Riprova.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pulisce newline residuo
            break;
        }

        // Definizione delle razze disponibili
        vector<string> nomiRazze = {"Umano", "Elfo"};
        for (int i = 0; i < nMembri; i++) {
        Personaggio p;

        cout << "Inserisci il nome del personaggio " << i + 1 << ": ";
        getline(cin, p.nome);

        // Selezione razza
        cout << "Seleziona la razza:\n";
        for (size_t j = 0; j < nomiRazze.size(); j++) {
            cout << j + 1 << ". " << nomiRazze[j] << endl;
        }

        int sceltaRazza = 0;
        while (true) {
            cout << "Inserisci il numero della razza: ";
            if (!(cin >> sceltaRazza) || sceltaRazza < 1 || static_cast<size_t>(sceltaRazza) > nomiRazze.size()) {
                cout << "Input non valido! Riprova.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Razza* razzaSelezionata = nullptr;
        switch (sceltaRazza) {
            case 1: razzaSelezionata = new Umano(); break;
            case 2: razzaSelezionata = new Elfo(); break;
        }

        p.assegnaRazza(razzaSelezionata);
        delete razzaSelezionata;

        // Punti da spendere
        int puntiDaSpendere = 30;
        spendere_punti(p, puntiDaSpendere);

        aggiungiMembro(p);
    }
}

void Party::aggiungiMembro(const Personaggio& p)
    {
        if (membri.size() < static_cast<size_t>(MAX_MEMBRI)) {
            membri.push_back(p);
            cout << p.nome << " aggiunto al party." << endl;
        } else {
            cout << "Party pieno! Impossibile aggiungere " << p.nome << "." << endl;
        }
    }

void Party::rimuoviMembro(int indice)
{
    if (indice >= 0 && static_cast<size_t>(indice) < membri.size()) {
        size_t idx = static_cast<size_t>(indice);
        cout << membri[idx].nome << " rimosso dal party." << endl;
        membri.erase(membri.begin() + static_cast<std::vector<Personaggio>::difference_type>(idx));
    } else {
        cout << "Indice non valido." << endl;
    }
}

void Party::stampaMembri() const
{
    cout << "Membri del party:" << endl;
    for (size_t i = 0; i < membri.size(); i++)
        cout << i + 1 << ". " << membri[i].nome << endl;
}

void Party::stampaStatistiche() const
{
    cout << "Statistiche dei membri:" << endl;
    for (const auto& p : membri) {
        p.stampa_statistiche();
        cout << "------------------------" << endl;
    }
}

int Party::numeroMembri() const
{
    return static_cast<int>(membri.size());
}

// ----------------------
// Razze
// ----------------------

void Razza::applicaBonus(Personaggio& p) const
{
    p.forza += bonusForza;
    p.destrezza += bonusDestrezza;
    p.costituzione += bonusCostituzione;
    p.intelligenza += bonusIntelligenza;
    p.saggezza += bonusSaggezza;
    p.carisma += bonusCarisma;

    // Aggiunge le abilità razziali al personaggio
    for (const auto& a : abilitaRazza)
        p.abilita_razziali.push_back(a);

    // Aggiorna i modificatori
    p.calcolo_modificatori();
}

// ----------------------
// Razze concrete
// ----------------------

Umano::Umano() : Razza("Umano")
{
    bonusForza = 1;
    bonusDestrezza = 1;
    bonusCostituzione = 1;
    bonusIntelligenza = 1;
    bonusSaggezza = 1;
    bonusCarisma = 1;
    velocita = 9;

    abilitaRazza.push_back("Adattabilità");
}

Elfo::Elfo() : Razza("Elfo")
{
    bonusDestrezza = 2;
    velocita = 10;

    abilitaRazza.push_back("Sensi acuti");
    abilitaRazza.push_back("Trance");
    abilitaRazza.push_back("Retaggio fatato");
}
