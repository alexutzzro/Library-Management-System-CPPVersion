#ifndef LIBRARIE_H
#define LIBRARIE_H

#include "Carte.h"

using namespace std;

class Librarie {
private:
    static const int MAX_CARTI = 200;
    Carte carti[MAX_CARTI];
    int nrCarti;

public:
    Librarie();

    void adaugaCarte(const Carte& carteNoua);
    void cautaDupaTitlu(const string& titlu) const;
    void cautaDupaAutor(const string& autor) const;
    void cautaCartiDisponibile() const;
    void imprumutaCartea(const string& titlu);
    void returneazaCartea(const string& titlu);
    void afiseazaToateCartile() const;
    void salveazaTotul(const string& filename) const;
    void incarcamBiblioteca(const string& filename);
    void stergeCarte(const string& titlu);

    // Getters
    int getNrCarti() const { return nrCarti; }
    Carte getCarte(int index) const { return carti[index]; }
};

#endif // LIBRARIE_H
