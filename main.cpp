#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "Functionalitati/Carte.h"
#include "Functionalitati/Librarie.h"
#include "AppNagy/Nagy.h"
#include "AppUntaru/Untaru.h"

using namespace std;

void AfiseazaListaComenzi(const string& programName);

int main(int argc, char* argv[]) {
    Librarie librarie;
    librarie.incarcamBiblioteca("biblioteca.txt");

    if (argc < 2) {
        cout << "Utilizare: ./main.exe <comanda> <arg1> <arg2> ..." << endl << "Pentru a vedea comenzile disponibile ruleaza: \033[0;33m`program.exe help`\033[0;37m\n";
        return 1;
    }

    string comanda = argv[1];
    string programName = argv[0];

    if (comanda == "adauga_carte" && argc == 6) {
        Carte carteNoua;
        carteNoua.setTitlu(argv[2]);
        carteNoua.setAutor(argv[3]);
        carteNoua.setTip(argv[4]);
        carteNoua.setLocatie(argv[5]);
        carteNoua.inlocuiesteBarileJos();
        adaugaCarte(librarie, carteNoua);
    } else if (comanda == "cauta_titlu" && argc == 3) {
        string titlu = argv[2];
        replace(titlu.begin(), titlu.end(), '_', ' ');
        cautaDupaTitlu(librarie, titlu);
    } else if (comanda == "cauta_autor" && argc == 3) {
        string autor = argv[2];
        replace(autor.begin(), autor.end(), '_', ' ');
        cautaDupaAutor(librarie, autor);
    } else if (comanda == "cauta_disponibile") {
        cautaCartiDisponibile(librarie);
    } else if (comanda == "afiseaza_toate") {
        afiseazaToateCartile(librarie);
    } else if (comanda == "imprumuta_carte" && argc == 3) {
        string titlu = argv[2];
        replace(titlu.begin(), titlu.end(), '_', ' ');
        imprumutaCartea(librarie, titlu);
    } else if (comanda == "returneaza_carte" && argc == 3) {
        string titlu = argv[2];
        replace(titlu.begin(), titlu.end(), '_', ' ');
        returneazaCartea(librarie, titlu);
    } else if (comanda == "sterge_carte" && argc == 3) {
        string titlu = argv[2];
        replace(titlu.begin(), titlu.end(), '_', ' ');
        stergeCarte(librarie, titlu);
    } else if (comanda == "help") {
        AfiseazaListaComenzi(programName);
    } else {
        cout << "Comanda invalida sau argumente insuficiente. Pentru a vedea comenzile disponibile ruleaza: \033[0;33m`program.exe help`\033[0;37m\n";
    }

    librarie.salveazaTotul("biblioteca.txt");
    return 0;
}

void AfiseazaListaComenzi(const string& programName) {
    string execName = programName.substr(programName.find_last_of("/\\") + 1);
    cout << "\n";
    cout << "\033[0;33m888888b.    .d8888b.  888     888 88888888888 \n";
    cout << "\033[0;32m888  \"88b  d88P  Y88b 888     888     888     \n";
    cout << "\033[0;36m888  .88P  888    888 888     888     888     \n";
    cout << "\033[0;31m8888888K.  888        888     888     888     \n";
    cout << "\033[0;33m888  \"Y88b 888        888     888     888     \n";
    cout << "\033[0;32m888    888 888    888 888     888     888     \n";
    cout << "\033[0;36m888   d88P Y88b  d88P Y88b. .d88P     888     \n";
    cout << "\033[0;31m8888888P\"   \"Y8888P\"   \"Y88888P\"      888     \n";
    cout << "\033[0;33m                                              \n";
    cout << "\n\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;35m=\033[0;36m=\033[0;37m=\033[0;31m=\033[0;32m=\033[0;37m COMENZI DISPONIBILE \033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;35m=\033[0;36m=\033[0;37m=\033[0;31m=\033[0;32m=\033[0;37m\n";
    cout << "- " << execName << " adauga_carte <Titlu_Carte> <Autor> <Tip> <Locatie>\033[0;33m - Adaugi o carte\033[0;37m\n";
    cout << "- " << execName << " sterge_carte <Titlu_Carte>\033[0;33m - Stergi o carte\033[0;37m\n";
    cout << "- " << execName << " cauta_titlu <Titlu_Carte>\033[0;33m - Cauti o carte dupa titlu\033[0;37m\n";
    cout << "- " << execName << " cauta_autor <Autor>\033[0;33m - Cauti o carte dupa autor\033[0;37m\n";
    cout << "- " << execName << " cauta_disponibile\033[0;33m - Afisezi toate cartile disponibile\033[0;37m\n";
    cout << "- " << execName << " afiseaza_toate\033[0;33m - Afiseaza toate cartile disponibile din baza de date\033[0;37m\n";
    cout << "- " << execName << " imprumuta_carte <Titlu_Carte>\033[0;33m - Imprumuti o carte\033[0;37m\n";
    cout << "- " << execName << " returneaza_carte <Titlu_Carte>\033[0;33m - Returnezi o carte\033[0;37m\n";
    cout << "- " << execName << " help\033[0;33m - Afisezi lista de comenzi\033[0;37m\n";
    cout << "\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;35m=\033[0;36m=\033[0;37m=\033[0;31m=\033[0;32m=\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;35m=\033[0;36m=\033[0;37m=\033[0;31m=\033[0;32m=\033[0;37m\033[0;31m=\033[0;32m=\033[0;33m=\033[0;34m=\033[0;35m=\033[0;35m=\033[0;36m=\033[0;37m=\033[0;31m=\033[0;32m=\033[0;31m=\033[0;37m\n";
}
