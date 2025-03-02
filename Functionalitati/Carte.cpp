#include "Carte.h"
using namespace std;

ostream& operator<<(ostream& os, const Carte& carte) {
    os << carte.titlu << "\n"
       << carte.autor << "\n"
       << carte.tip << "\n"
       << carte.locatie << "\n"
       << (carte.disponibila ? "1" : "0") << "\n";
    return os;
}

istream& operator>>(istream& is, Carte& carte) {
    string disp;
    getline(is, carte.titlu);
    getline(is, carte.autor);
    getline(is, carte.tip);
    getline(is, carte.locatie);
    getline(is, disp);
    carte.disponibila = (disp == "1");
    return is;
}

void Carte::inlocuiesteBarileJos() {
    replace(titlu.begin(), titlu.end(), '_', ' ');
    replace(autor.begin(), autor.end(), '_', ' ');
    replace(tip.begin(), tip.end(), '_', ' ');
    replace(locatie.begin(), locatie.end(), '_', ' ');
}

void Carte::inlocuiesteSpatiile() {
    replace(titlu.begin(), titlu.end(), ' ', '_');
    replace(autor.begin(), autor.end(), ' ', '_');
    replace(tip.begin(), tip.end(), ' ', '_');
    replace(locatie.begin(), locatie.end(), ' ', '_');
}
