# Library Management System - EN

This project is a **Library Management System** developed in C++, providing functionalities for managing books and handling loans.

## Features

- Adding, deleting, and updating book information
- Searching for books by title or author
- Displaying available books
- Managing loans and returns
- Book information is stored in the `biblioteca.txt` file, which must be in the same location as the executable

## System Requirements

- C++ compiler (e.g., GCC, Clang, MSVC)
- CMake for build management

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/alexutzzro/Library-Management-System-CPPVersion.git
   cd Library-Management-System-CPPVersion
   ```

2. **Compile the project using CMake:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage

After compilation, run the program from the `build` directory:
```bash
./LibraryCPP
```

### Available Commands:
- `./LibraryCPP adauga_carte <Title> <Author> <Type> <Location>` → Adds a book to the database.
- `./LibraryCPP sterge_carte <Title>` → Removes a book from the database.
- `./LibraryCPP cauta_titlu <Title>` → Searches for a book by title.
- `./LibraryCPP cauta_autor <Author>` → Searches for a book by author.
- `./LibraryCPP cauta_disponibile` → Displays available books.
- `./LibraryCPP afiseaza_toate` → Displays all books.
- `./LibraryCPP imprumuta_carte <Title>` → Borrows a book.
- `./LibraryCPP returneaza_carte <Title>` → Returns a book.
- `./LibraryCPP help` → Displays all available commands.

## License

This project was created as part of the Programming Project (part two) course at the West University of Timișoara.

---

# Sistem de Gestiune a Bibliotecii - RO

Acest proiect reprezintă un **Sistem de Gestiune a Bibliotecii** dezvoltat în limbajul C++, oferind funcționalități pentru administrarea cărților și gestionarea împrumuturilor.

## Caracteristici

- Adăugarea, ștergerea și actualizarea informațiilor despre cărți
- Căutarea cărților după titlu sau autor
- Afișarea cărților disponibile
- Gestionarea împrumuturilor și returnărilor
- Informațiile despre cărți sunt stocate în fișierul `biblioteca.txt`, care trebuie să fie în aceeași locație cu executabilul

## Cerințe de sistem

- Compilator C++ (de exemplu, GCC, Clang, MSVC)
- CMake pentru gestionarea build-ului

## Instalare

1. **Clonarea repository-ului:**
   ```bash
   git clone https://github.com/alexutzzro/Library-Management-System-CPPVersion.git
   cd Library-Management-System-CPPVersion
   ```

2. **Compilarea proiectului folosind CMake:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Utilizare

După compilare, execută programul din directorul `build`:
```bash
./LibraryManagementSystemCPP
```

### Comenzi disponibile:
- `./LibraryCPP adauga_carte <Titlu> <Autor> <Tip> <Locatie>` → Adaugă o carte în baza de date.
- `./LibraryCPP sterge_carte <Titlu>` → Șterge o carte din baza de date.
- `./LibraryCPP cauta_titlu <Titlu>` → Caută o carte după titlu.
- `./LibraryCPP cauta_autor <Autor>` → Caută o carte după autor.
- `./LibraryCPP cauta_disponibile` → Afișează cărțile disponibile.
- `./LibraryCPP afiseaza_toate` → Afișează toate cărțile.
- `./LibraryCPP imprumuta_carte <Titlu>` → Împrumută o carte.
- `./LibraryCPP returneaza_carte <Titlu>` → Returnează o carte.
- `./LibraryCPP help` → Afișează lista de comenzi.

## Licență

Acest proiect a fost realizat în cadrul laboratoarelor de la disciplina Proiect de programare (partea a 2-a), din cadrul Universității de Vest din Timișoara.
