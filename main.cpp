#include <iostream>
#include "Classi.h"
#include "Libreria.h"

int main()
{
    int punti_da_spendere = 30;
    Personaggio Personaggio;
    Personaggio.forza = 6;
    Personaggio.destrezza = 6;
    Personaggio.costituzione = 6;
    Personaggio.intelligenza = 6;
    Personaggio.saggezza = 6;
    Personaggio.carisma = 6;
    Personaggio.calcolo_modificatori();
    Personaggio.velocita = 9;
    Personaggio.CA = 10 + Personaggio.modificatori[Personaggio.DESTREZZA];

    spendere_punti(Personaggio, punti_da_spendere);

    return 0;
}