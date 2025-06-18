#include "film.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\n--- FILM LIBRARY MENU ---\n";
    cout << "1. Add a new film\n";
    cout << "2. Display all films\n";
    cout << "3. Display film by index\n";
    cout << "4. Delete all films\n";
    cout << "5. Delete film by index\n";
    cout << "6. Search films\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Film* films = nullptr;
    int size = 0;
    int choice;

    do {
        displayMenu();
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cout << "Invalid input. Enter number between 1–7: ";
            cin.clear();
            cin.ignore(256, '\n');
        }

        switch (choice) {
        case 1:
            addFilm(films, size, createNewFilmFromUserInput());
            break;
        case 2:
            printAllFilms(films, size);
            break;
        case 3:
            printFilmByIndex(films, size);
            break;
        case 4:
            deleteAllFilms(films, size);
            break;
        case 5:
            deleteFilmByIndex(films, size);
            break;
        case 6:
            searchFilms(films, size);
            break;
        case 7:
            deleteAllFilms(films, size);
            cout << "Exiting...\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
