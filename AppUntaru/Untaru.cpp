#include <iostream>
#include "../Functionalitati/Librarie.h"

using namespace std;

void adaugaCarte(Librarie& librarie, const Carte& carteNoua) {
    librarie.adaugaCarte(carteNoua);
}

void stergeCarte(Librarie& librarie, const string& titlu) {
    librarie.stergeCarte(titlu);
}

void imprumutaCartea(Librarie& librarie, const string& titlu) {
    librarie.imprumutaCartea(titlu);
}

void returneazaCartea(Librarie& librarie, const string& titlu) {
    librarie.returneazaCartea(titlu);
}