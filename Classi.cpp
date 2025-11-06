#include "Classi.h"

    void Personaggio::calcolo_modificatori()
    {
        modificatori[FORZA] = ((forza - 10) / 2);
        modificatori[DESTREZZA] = ((destrezza - 10) / 2);
        modificatori[COSTITUZIONE] = ((costituzione - 10) / 2);
        modificatori[INTELLIGENZA] = ((intelligenza - 10) / 2);
        modificatori[SAGGEZZA] = ((saggezza - 10) / 2);
        modificatori[CARISMA] = ((carisma - 10) / 2);
    }
