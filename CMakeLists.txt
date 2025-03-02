cmake_minimum_required(VERSION 3.30)
project(LibraryCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibraryCPP
        main.cpp
        Functionalitati/Carte.cpp
        Functionalitati/Librarie.cpp
        AppNagy/Nagy.cpp
        AppUntaru/Untaru.cpp
)

include_directories(
        Functionalitati
        AppNagy
        AppUntaru
)