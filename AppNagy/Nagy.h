#ifndef NAGY_H
#define NAGY_H

#include "../Functionalitati/Librarie.h"
using namespace std;

void cautaDupaTitlu(const Librarie& librarie, const string& titlu);
void cautaDupaAutor(const Librarie& librarie, const string& autor);
void cautaCartiDisponibile(const Librarie& librarie);
void afiseazaToateCartile(const Librarie& librarie);

#endif // NAGY_H
