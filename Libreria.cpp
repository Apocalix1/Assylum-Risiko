#include "Libreria.h"
#include <iostream>
#include <limits>
using namespace std;

// Funzione che calcola il costo per incrementare un attributo
int costoIncremento(int valore) {
    if (valore < 12) return 1;
    else if (valore < 16) return 2;
    else if (valore < 18) return 3;
    else if (valore < 20) return 4;
    return 0; // già massimo
}

// Funzione che incrementa un attributo usando i punti disponibili
int aumentaAttributo(int &attributo, int punti_da_spendere) {
    int spesi = 0;
    while (punti_da_spendere > 0 && attributo < 20) {
        int costo = costoIncremento(attributo);
        if (punti_da_spendere >= costo) {
            attributo += 1;
            punti_da_spendere -= costo;
            spesi += costo;
        } else {
            cout << "Non abbastanza punti per aumentare" << endl;
            break;
        }
    }
    if (attributo >= 20) {
        cout << "Valore massimo raggiunto!" << endl;
    }
    return spesi;
}
// Funzione principale per spendere punti negli attributi
void spendere_punti(Personaggio& personaggio, int &punti_da_spendere) {
    while (punti_da_spendere > 0) {
        // Stampa lo stato corrente
        cout << "\nPunti rimasti: " << punti_da_spendere << endl;
        cout << "1. Forza: " << personaggio.forza << " (mod: " << personaggio.modificatori[Personaggio::FORZA] << ")\n";
        cout << "2. Destrezza: " << personaggio.destrezza << " (mod: " << personaggio.modificatori[Personaggio::DESTREZZA] << ")\n";
        cout << "3. Costituzione: " << personaggio.costituzione << " (mod: " << personaggio.modificatori[Personaggio::COSTITUZIONE] << ")\n";
        cout << "4. Intelligenza: " << personaggio.intelligenza << " (mod: " << personaggio.modificatori[Personaggio::INTELLIGENZA] << ")\n";
        cout << "5. Saggezza: " << personaggio.saggezza << " (mod: " << personaggio.modificatori[Personaggio::SAGGEZZA] << ")\n";
        cout << "6. Carisma: " << personaggio.carisma << " (mod: " << personaggio.modificatori[Personaggio::CARISMA] << ")\n";

        int scelta;
        while (true) {
            cout << "Scegli l'attributo da incrementare (1-6): ";
            if (!(cin >> scelta) || scelta < 1 || scelta > 6) {
                cout << "Input non valido! Inserisci un numero da 1 a 6.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pulisce il buffer
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // rimuove newline residuo
            break;
        }

        int punti_spesi;
        while (true) {
            cout << "Quanti punti vuoi spendere? ";
            if (!(cin >> punti_spesi) || punti_spesi < 1) {
                cout << "Input non valido! Inserisci un numero positivo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pulisce buffer
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pulisce newline residuo
            break;
        }

        // Aumenta l'attributo scelto
        int spesi_effettivi = 0;
        switch (scelta) {
            case 1: spesi_effettivi = aumentaAttributo(personaggio.forza, punti_spesi); break;
            case 2: spesi_effettivi = aumentaAttributo(personaggio.destrezza, punti_spesi); break;
            case 3: spesi_effettivi = aumentaAttributo(personaggio.costituzione, punti_spesi); break;
            case 4: spesi_effettivi = aumentaAttributo(personaggio.intelligenza, punti_spesi); break;
            case 5: spesi_effettivi = aumentaAttributo(personaggio.saggezza, punti_spesi); break;
            case 6: spesi_effettivi = aumentaAttributo(personaggio.carisma, punti_spesi); break;
        }

        // Aggiorna modificatori
        personaggio.calcolo_modificatori();

        // Aggiorna i punti rimanenti
        punti_da_spendere -= spesi_effettivi;

        // Restituisce eventuali punti non spesi
        if (spesi_effettivi < punti_spesi) {
            int resto = punti_spesi - spesi_effettivi;
            cout << "Hai raggiunto il massimo per questo attributo. Restano " << resto << " punti da spendere.\n";
            punti_da_spendere += resto;
        }

        cout << "----------------------------------------\n";
    }

    cout << "Hai speso tutti i punti disponibili!\n";
}