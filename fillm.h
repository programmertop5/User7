#pragma once

#include <cstring>

struct Film {
    char* name = nullptr;
    char* author = nullptr;
    char* genre = nullptr;
    char* description = nullptr;
    char* date = nullptr;

    double series_quantity = 1.0;
    int quality = 0;
};


Film createNewFilm(const char*, const char*, const char*, const char*, const char*, int);
Film createNewFilmFromUserInput();
void printFilm(const Film&);
void deleteFilm(Film&);
void addFilm(Film*&, int&, const Film&);
void printAllFilms(const Film*, int);
void printFilmByIndex(const Film*, int);
void deleteFilmByIndex(Film*&, int&);
void deleteAllFilms(Film*&, int&);
void searchFilms(const Film*, int);
