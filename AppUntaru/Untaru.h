#ifndef UNTARU_H
#define UNTARU_H

#include "../Functionalitati/Librarie.h"

using namespace std;

void adaugaCarte(Librarie& librarie, const Carte& carteNoua);
void stergeCarte(Librarie& librarie, const string& titlu);
void imprumutaCartea(Librarie& librarie, const string& titlu);
void returneazaCartea(Librarie& librarie, const string& titlu);

#endif // UNTARU_H
