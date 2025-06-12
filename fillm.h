#pragma once

struct Film {
    char* name = nullptr;
    char* author = nullptr;
    char* genre = nullptr;
    char* description = nullptr;
    char* date = nullptr;

    double series_quantity = 1.0;
    int quality = 0;
};


Film createNewFilm(const char* name, const char* author, const char* genre, const char* description, const char* date, int quality);


Film createNewFilmFromUserInput();


void printFilm(const Film& film);


void printFilms(Film* films, int size);

void deleteFilm(Film& film);

// Освобождает память всех фильмов в массиве
void deleteFilms(Film* films, int size);
