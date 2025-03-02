#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    string tip;
    string locatie;
    bool disponibila;

public:
    Carte() : disponibila(true) {}

    // Gettere
    string getTitlu() const { return titlu; }
    string getAutor() const { return autor; }
    string getTip() const { return tip; }
    string getLocatie() const { return locatie; }
    bool isDisponibila() const { return disponibila; }

    // Settere
    void setTitlu(const string& t) { titlu = t; }
    void setAutor(const string& a) { autor = a; }
    void setTip(const string& t) { tip = t; }
    void setLocatie(const string& l) { locatie = l; }
    void setDisponibila(bool d) { disponibila = d; }

    friend ostream& operator<<(ostream& os, const Carte& carte);
    friend istream& operator>>(istream& is, Carte& carte);

    void inlocuiesteBarileJos();
    void inlocuiesteSpatiile();
};

#endif // CARTE_H
