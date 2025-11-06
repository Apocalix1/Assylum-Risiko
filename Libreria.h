#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "Classi.h"
#include <limits>
#include <iostream>
using namespace std;

int costoIncremento(int valore);
int aumentaAttributo(int &attributo, int punti_da_spendere);
void spendere_punti(Personaggio& personaggio, int &punti_da_spendere);

#endif