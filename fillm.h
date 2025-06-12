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

// Создает новый фильм с заданными параметрами
Film createNewFilm(const char* name, const char* author, const char* genre, const char* description, const char* date, int quality);

// Создает новый фильм, запрашивая данные у пользователя
Film createNewFilmFromUserInput();

// Выводит информацию о фильме
void printFilm(const Film& film);

// Выводит информацию о всех фильмах из массива
void printFilms(Film* films, int size);

// Освобождает память, занятую полями фильма
void deleteFilm(Film& film);

// Освобождает память всех фильмов в массиве
void deleteFilms(Film* films, int size);
