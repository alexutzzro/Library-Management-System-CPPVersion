#include <iostream>
#include <iomanip>
#include "../Functionalitati/Librarie.h"

using namespace std;

void cautaDupaTitlu(const Librarie& librarie, const string& titlu) {
    librarie.cautaDupaTitlu(titlu);
}

void cautaDupaAutor(const Librarie& librarie, const string& autor) {
    librarie.cautaDupaAutor(autor);
}

void cautaCartiDisponibile(const Librarie& librarie) {
    librarie.cautaCartiDisponibile();
}

void afiseazaToateCartile(const Librarie& librarie) {
    librarie.afiseazaToateCartile();
}
