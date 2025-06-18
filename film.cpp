#include "film.h"
#include <iostream>


using namespace std;

Film createNewFilm(const char* name, const char* author, const char* genre, const char* description, const char* date, int quality) {
    Film temp{};

    int len = strlen(name) + 1;
    temp.name = new char[len];
    strcpy_s(temp.name, len, name);

    len = strlen(author) + 1;
    temp.author = new char[len];
    strcpy_s(temp.author, len, author);

    len = strlen(genre) + 1;
    temp.genre = new char[len];
    strcpy_s(temp.genre, len, genre);

    len = strlen(description) + 1;
    temp.description = new char[len];
    strcpy_s(temp.description, len, description);

    len = strlen(date) + 1;
    temp.date = new char[len];
    strcpy_s(temp.date, len, date);

    temp.quality = quality;
    temp.series_quantity = 1.0;

    return temp;
}

Film createNewFilmFromUserInput() {
    Film newFilm{};
    char buffer[256];

    cin.ignore();

    cout << "\n--- CREATE NEW FILM ---\n";

    cout << "Enter the name film: ";
    cin.getline(buffer, sizeof(buffer));
    int len = strlen(buffer) + 1;
    newFilm.name = new char[len];
    strcpy_s(newFilm.name, len, buffer);

    cout << "Enter the author of film: ";
    cin.getline(buffer, sizeof(buffer));
    len = strlen(buffer) + 1;
    newFilm.author = new char[len];
    strcpy_s(newFilm.author, len, buffer);

    cout << "Enter the genre: ";
    cin.getline(buffer, sizeof(buffer));
    len = strlen(buffer) + 1;
    newFilm.genre = new char[len];
    strcpy_s(newFilm.genre, len, buffer);

    cout << "Enter the description: ";
    cin.getline(buffer, sizeof(buffer));
    len = strlen(buffer) + 1;
    newFilm.description = new char[len];
    strcpy_s(newFilm.description, len, buffer);

    cout << "Enter the date (YYYY-MM-DD): ";
    cin.getline(buffer, sizeof(buffer));
    len = strlen(buffer) + 1;
    newFilm.date = new char[len];
    strcpy_s(newFilm.date, len, buffer);

    cout << "Enter the quality (1-10): ";
    while (!(cin >> newFilm.quality) || newFilm.quality < 1 || newFilm.quality > 10) {
        cout << "Invalid input. Enter a number between 1 and 10: ";
        cin.clear();
        cin.ignore(256, '\n');
    }

    return newFilm;
}

void printFilm(const Film& film) {
    if (!film.name) {
        cout << "\nThe film is empty or deleted!\n";
        return;
    }

    cout << "\n--- FILM INFO ---\n";
    cout << "Name: " << film.name << "\n";
    cout << "Author: " << film.author << "\n";
    cout << "Genre: " << film.genre << "\n";
    cout << "Description: " << film.description << "\n";
    cout << "Date: " << film.date << "\n";
    cout << "Quality: " << film.quality << "\n";
    cout << "Series Quantity: " << film.series_quantity << "\n";
}

void deleteFilm(Film& film) {
    delete[] film.name;
    delete[] film.author;
    delete[] film.genre;
    delete[] film.description;
    delete[] film.date;

    film.name = film.author = film.genre = film.description = film.date = nullptr;
    film.quality = 0;
    film.series_quantity = 0;
}

void addFilm(Film*& films, int& size, const Film& newFilm) {
    Film* newArray = new Film[size + 1];

    for (int i = 0; i < size; ++i) {
        newArray[i] = films[i];
    }

    newArray[size] = newFilm;

    delete[] films;
    films = newArray;
    ++size;

    cout << "Film added!\n";
}

void printAllFilms(const Film* films, int size) {
    if (size == 0) {
        cout << "\nLibrary is empty.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        cout << "\nFilm #" << i << ":";
        printFilm(films[i]);
    }
}

void printFilmByIndex(const Film* films, int size) {
    if (size == 0) {
        cout << "\nLibrary is empty.\n";
        return;
    }

    int index;
    cout << "Enter index (0 - " << size - 1 << "): ";
    while (!(cin >> index) || index < 0 || index >= size) {
        cout << "Invalid index. Try again: ";
        cin.clear();
        cin.ignore(256, '\n');
    }

    printFilm(films[index]);
}

void deleteFilmByIndex(Film*& films, int& size) {
    if (size == 0) {
        cout << "\nNo films to delete.\n";
        return;
    }

    int index;
    cout << "Enter index to delete (0 - " << size - 1 << "): ";
    while (!(cin >> index) || index < 0 || index >= size) {
        cout << "Invalid index. Try again: ";
        cin.clear();
        cin.ignore(256, '\n');
    }

    deleteFilm(films[index]);

    if (size == 1) {
        delete[] films;
        films = nullptr;
        size = 0;
        cout << "All films deleted.\n";
        return;
    }

    Film* newArray = new Film[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            newArray[j++] = films[i];
        }
    }

    delete[] films;
    films = newArray;
    --size;

    cout << "Film deleted.\n";
}

void deleteAllFilms(Film*& films, int& size) {
    for (int i = 0; i < size; ++i) {
        deleteFilm(films[i]);
    }

    delete[] films;
    films = nullptr;
    size = 0;

    cout << "All films deleted.\n";
}

int myStrnicmp(const char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        char c1 = s1[i];
        char c2 = s2[i];

       
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 - 'A' + 'a';
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 - 'A' + 'a';
        }
    if (c1 != c2) {
        return c1 - c2;
    }
    if (c1 == '\0') {
        return 0;
    }
    return 0;
}
void searchFilms(const Film* films, int size) {
    if (size == 0) {
        cout << "\nLibrary is empty.\n";
        return;
    }

    int choice;
    cout << "Search by: 1-Name 2-Author 3-Genre 4-Date\nYour choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice. Try 1–4: ";
        cin.clear();
        cin.ignore(256, '\n');
    }

    cin.ignore();
    char term[256];
    cout << "Enter search term: ";
    cin.getline(term, sizeof(term));

    int count = 0;  

    for (int i = 0; i < size; ++i) {
        const char* field = nullptr;

        switch (choice) {
        case 1: 
            field = films[i].name; 
            break;
        case 2: 
            field = films[i].author; 
            break;
        case 3:
            field = films[i].genre; 
            break;
        case 4:
            field = films[i].date;
            break;
        }

        if (field != nullptr) {
            if (myStrnicmp(field, term, strlen(term)) == 0) {
                printFilm(films[i]);
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "No matching films found.\n";
    }
}
