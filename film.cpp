#include "film.h"
#include <iostream>

using namespace std;

Film createNewFilm(const char* name, const char* author, const char* genre, const char* description, const char* date, int quality) {
    Film temp{};

    int len = (int)strlen(name) + 1;
    temp.name = new char[len];
    strcpy_s(temp.name, len, name);

    len = (int)strlen(author) + 1;
    temp.author = new char[len];
    strcpy_s(temp.author, len, author);

    len = (int)strlen(genre) + 1;
    temp.genre = new char[len];
    strcpy_s(temp.genre, len, genre);

    len = (int)strlen(description) + 1;
    temp.description = new char[len];
    strcpy_s(temp.description, len, description);

    len = (int)strlen(date) + 1;
    temp.date = new char[len];
    strcpy_s(temp.date, len, date);

    temp.series_quantity = 1.0;
    temp.quality = quality;

    return temp;
}

Film createNewFilmFromUserInput() {
    Film newFilm{};
    char buffer[256];

    cout << "\n-------------------- CREATE NEW FILM --------------------\n";

    cin.ignore(); // очистка буфера перед первым getline

    cout << "Enter the name film: ";
    cin.getline(buffer, 256);
    int len = (int)strlen(buffer) + 1;
    newFilm.name = new char[len];
    strcpy_s(newFilm.name, len, buffer);

    cout << "Enter the author of film: ";
    cin.getline(buffer, 256);
    len = (int)strlen(buffer) + 1;
    newFilm.author = new char[len];
    strcpy_s(newFilm.author, len, buffer);

    cout << "Enter the genre: ";
    cin.getline(buffer, 256);
    len = (int)strlen(buffer) + 1;
    newFilm.genre = new char[len];
    strcpy_s(newFilm.genre, len, buffer);

    cout << "Enter the description: ";
    cin.getline(buffer, 256);
    len = (int)strlen(buffer) + 1;
    newFilm.description = new char[len];
    strcpy_s(newFilm.description, len, buffer);

    cout << "Enter the date (for example, 2025-06-12): ";
    cin.getline(buffer, 256);
    len = (int)strlen(buffer) + 1;
    newFilm.date = new char[len];
    strcpy_s(newFilm.date, len, buffer);

    cout << "Enter the quality (1-10): ";
    cin >> newFilm.quality;
    cin.ignore(); // очистка буфера после числового ввода

    newFilm.series_quantity = 1.0;

    return newFilm;
}

void printFilm(const Film& film) {
    cout << "\n-------------------- INFORMATION ABOUT FILM --------------------\n";

    if (!film.name) {
        cout << "The movie is empty or already deleted!" << endl;
        return;
    }

    cout << "Name: " << film.name << endl;
    cout << "Author: " << film.author << endl;
    cout << "Genre: " << film.genre << endl;
    cout << "Description: " << film.description << endl;
    cout << "Date: " << film.date << endl;
    cout << "Quality: " << film.quality << endl;
    cout << "Quantity: " << film.series_quantity << endl;

    cout << "--------------------------------------------------------------\n";
}

void deleteFilm(Film& film) {
    if (film.name) delete[] film.name;
    if (film.author) delete[] film.author;
    if (film.genre) delete[] film.genre;
    if (film.description) delete[] film.description;
    if (film.date) delete[] film.date;

    film.name = film.author = film.genre = film.description = film.date = nullptr;
    film.quality = 0;
    film.series_quantity = 0.0;
}

int main() {
    Film myFilm = createNewFilmFromUserInput();
    printFilm(myFilm);
    deleteFilm(myFilm);
    return 0;
}
