#include "Librarie.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

Librarie::Librarie() : nrCarti(0) {}

void Librarie::adaugaCarte(const Carte& carteNoua) {
    if (nrCarti >= MAX_CARTI) {
        cout << "Nu mai este loc in biblioteca pentru a adauga o carte.\n";
        return;
    }
    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getTitlu() == carteNoua.getTitlu() && carti[i].getAutor() == carteNoua.getAutor()) {
            cout << "Cartea exista deja in biblioteca.\n";
            return;
        }
    }
    carti[nrCarti++] = carteNoua;
    cout << "Cartea a fost adaugata cu succes!\n";
}

void Librarie::cautaDupaTitlu(const string& titlu) const {
    int maxTitlu = strlen("Titlu");
    int maxAutor = strlen("Autor");
    int maxTip = strlen("Tip");
    int maxLocatie = strlen("Locatie");
    int maxDisponibil = strlen("Disponibil");

    bool gasit = false;
    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getTitlu() == titlu) {
            maxTitlu = max(maxTitlu, (int)carti[i].getTitlu().length());
            maxAutor = max(maxAutor, (int)carti[i].getAutor().length());
            maxTip = max(maxTip, (int)carti[i].getTip().length());
            maxLocatie = max(maxLocatie, (int)carti[i].getLocatie().length());
            gasit = true;
        }
    }

    if (!gasit) {
        cout << "Nu s-au gasit carti dupa acest titlu.\n";
        return;
    }

    string lineSeparatorTitlu(maxTitlu, '-');
    string lineSeparatorAutor(maxAutor, '-');
    string lineSeparatorTip(maxTip, '-');
    string lineSeparatorLocatie(maxLocatie, '-');
    string lineSeparatorDisponibil(maxDisponibil, '-');

    cout << "\n\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m Cartile cu titlul " << titlu << " \033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";
    cout << "| " << setw(maxTitlu) << left << "Titlu" << " | " << setw(maxAutor) << left << "Autor" << " | " << setw(maxTip) << left << "Tip" << " | " << setw(maxLocatie) << left << "Locatie" << " | " << setw(maxDisponibil) << left << "Disponibil" << " |\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";

    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getTitlu() == titlu) {
            cout << "| " << setw(maxTitlu) << left << carti[i].getTitlu()
                 << " | " << setw(maxAutor) << left << carti[i].getAutor()
                 << " | " << setw(maxTip) << left << carti[i].getTip()
                 << " | " << setw(maxLocatie) << left << carti[i].getLocatie()
                 << " | " << setw(maxDisponibil) << left << (carti[i].isDisponibila() ? "Da" : "Nu")
                 << " |\n";
            cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";
        }
    }
}


void Librarie::cautaDupaAutor(const string& autor) const {
    int maxTitlu = strlen("Titlu");
    int maxAutor = strlen("Autor");
    int maxTip = strlen("Tip");
    int maxLocatie = strlen("Locatie");
    int maxDisponibil = strlen("Disponibil");

    bool gasit = false;
    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getAutor() == autor) {
            maxTitlu = max(maxTitlu, (int)carti[i].getTitlu().length());
            maxAutor = max(maxAutor, (int)carti[i].getAutor().length());
            maxTip = max(maxTip, (int)carti[i].getTip().length());
            maxLocatie = max(maxLocatie, (int)carti[i].getLocatie().length());
            gasit = true;
        }
    }

    if (!gasit) {
        cout << "Nu s-au gasit carti scrise de acest autor.\n";
        return;
    }

    string lineSeparatorTitlu(maxTitlu, '-');
    string lineSeparatorAutor(maxAutor, '-');
    string lineSeparatorTip(maxTip, '-');
    string lineSeparatorLocatie(maxLocatie, '-');
    string lineSeparatorDisponibil(maxDisponibil, '-');

    cout << "\n\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m Cartile scrise de " << autor << " \033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";
    cout << "| " << setw(maxTitlu) << left << "Titlu" << " | " << setw(maxAutor) << left << "Autor" << " | " << setw(maxTip) << left << "Tip" << " | " << setw(maxLocatie) << left << "Locatie" << " | " << setw(maxDisponibil) << left << "Disponibil" << " |\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";

    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getAutor() == autor) {
            cout << "| " << setw(maxTitlu) << left << carti[i].getTitlu()
                 << " | " << setw(maxAutor) << left << carti[i].getAutor()
                 << " | " << setw(maxTip) << left << carti[i].getTip()
                 << " | " << setw(maxLocatie) << left << carti[i].getLocatie()
                 << " | " << setw(maxDisponibil) << left << (carti[i].isDisponibila() ? "Da" : "Nu")
                 << " |\n";
            cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";
        }
    }
}

void Librarie::afiseazaToateCartile() const {
    int maxTitlu = strlen("Titlu");
    int maxAutor = strlen("Autor");
    int maxTip = strlen("Tip");
    int maxLocatie = strlen("Locatie");
    int maxDisponibil = strlen("Disponibil");

    bool gasit = false;
    for (int i = 0; i < nrCarti; i++) {
        maxTitlu = max(maxTitlu, (int)carti[i].getTitlu().length());
        maxAutor = max(maxAutor, (int)carti[i].getAutor().length());
        maxTip = max(maxTip, (int)carti[i].getTip().length());
        maxLocatie = max(maxLocatie, (int)carti[i].getLocatie().length());
        gasit = true;
    }

    if (!gasit) {
        cout << "Nu exista carti in baza de date sau fisierul nu exista!\n";
        return;
    }

    string lineSeparatorTitlu(maxTitlu, '-');
    string lineSeparatorAutor(maxAutor, '-');
    string lineSeparatorTip(maxTip, '-');
    string lineSeparatorLocatie(maxLocatie, '-');
    string lineSeparatorDisponibil(maxDisponibil, '-');

    cout << "\n\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m Toate cartile din baza de date \033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";
    cout << "| " << setw(maxTitlu) << left << "Titlu" << " | " << setw(maxAutor) << left << "Autor" << " | " << setw(maxTip) << left << "Tip" << " | " << setw(maxLocatie) << left << "Locatie" << " | " << setw(maxDisponibil) << left << "Disponibil" << " |\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";

    for (int i = 0; i < nrCarti; i++) {
        cout << "| " << setw(maxTitlu) << left << carti[i].getTitlu()
             << " | " << setw(maxAutor) << left << carti[i].getAutor()
             << " | " << setw(maxTip) << left << carti[i].getTip()
             << " | " << setw(maxLocatie) << left << carti[i].getLocatie()
             << " | " << setw(maxDisponibil) << left << (carti[i].isDisponibila() ? "Da" : "Nu")
             << " |\n";
        cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+-" << lineSeparatorDisponibil << "-+\n";
    }
}


void Librarie::cautaCartiDisponibile() const {
    int maxTitlu = strlen("Titlu");
    int maxAutor = strlen("Autor");
    int maxTip = strlen("Tip");
    int maxLocatie = strlen("Locatie");

    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].isDisponibila()) {
            maxTitlu = max(maxTitlu, (int)carti[i].getTitlu().length());
            maxAutor = max(maxAutor, (int)carti[i].getAutor().length());
            maxTip = max(maxTip, (int)carti[i].getTip().length());
            maxLocatie = max(maxLocatie, (int)carti[i].getLocatie().length());
        }
    }

    string lineSeparatorTitlu(maxTitlu, '-');
    string lineSeparatorAutor(maxAutor, '-');
    string lineSeparatorTip(maxTip, '-');
    string lineSeparatorLocatie(maxLocatie, '-');

    cout << "\n\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m Cartile disponibile \033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;37m\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+\n";
    cout << "| " << setw(maxTitlu) << left << "Titlu" << " | " << setw(maxAutor) << left << "Autor" << " | " << setw(maxTip) << left << "Tip" << " | " << setw(maxLocatie) << left << "Locatie" << " |\n";
    cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+\n";

    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].isDisponibila()) {
            cout << "| " << setw(maxTitlu) << left << carti[i].getTitlu()
                 << " | " << setw(maxAutor) << left << carti[i].getAutor()
                 << " | " << setw(maxTip) << left << carti[i].getTip()
                 << " | " << setw(maxLocatie) << left << carti[i].getLocatie()
                 << " |\n";
            cout << "+-" << lineSeparatorTitlu << "-+-" << lineSeparatorAutor << "-+-" << lineSeparatorTip << "-+-" << lineSeparatorLocatie << "-+\n";
        }
    }

    if (nrCarti == 0) {
        cout << "\033[0;33mTabelul este gol. Fisierul nu a fost citit sau fisierul este gol!\033[0;37m\n";
    }
}

void Librarie::imprumutaCartea(const string& titlu) {
    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getTitlu() == titlu && carti[i].isDisponibila()) {
            carti[i].setDisponibila(false);
            cout << "Ati imprumutat cu succes cartea \"" << titlu << "\". Va rugam sa o returnati in maxim 10 zile.\n";
            return;
        }
    }
    cout << "Nu s-a putut realiza imprumutul. Cartea nu exista sau nu este disponibila.\n";
}

void Librarie::returneazaCartea(const string& titlu) {
    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getTitlu() == titlu && !carti[i].isDisponibila()) {
            carti[i].setDisponibila(true);
            cout << "Ati returnat cu succes cartea \"" << titlu << "\".\n";
            return;
        }
    }
    cout << "Nu s-a putut realiza returnarea. Cartea nu a fost imprumutata sau nu exista.\n";
}

void Librarie::salveazaTotul(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Eroare la salvarea bibliotecii in fisier.\n";
        return;
    }
    for (int i = 0; i < nrCarti; i++) {
        file << carti[i];
    }
}

void Librarie::incarcamBiblioteca(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Eroare la incarcarea bibliotecii din fisier.\n";
        return;
    }

    nrCarti = 0;
    while (!file.eof() && nrCarti < MAX_CARTI) {
        Carte carte;
        file >> carte;
        if (!file.eof()) {
            carti[nrCarti++] = carte;
        }
    }
}

void Librarie::stergeCarte(const string& titlu) {
    int pozitie = -1;
    for (int i = 0; i < nrCarti; i++) {
        if (carti[i].getTitlu() == titlu) {
            pozitie = i;
            break;
        }
    }

    if (pozitie != -1) {
        for (int i = pozitie; i < nrCarti - 1; i++) {
            carti[i] = carti[i + 1];
        }
        nrCarti--;
        cout << "Cartea a fost stearsa cu succes.\n";
    } else {
        cout << "Cartea nu a fost gasita.\n";
    }
}
