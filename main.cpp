#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(const list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string names[], int nameCount, string colors[], int colorCount);
void display_trip(const list<Goat> trip);
int main_menu();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // read & populate arrays for names and colors

    string names[SZ_NAMES];
    string colors[SZ_COLORS];

    int nameCount = 0;
    ifstream fin("names.txt");
    if (!fin) {
        cerr << "Error opening names.txt file!" << endl;
        return 1;
    }
    while (nameCount < SZ_NAMES && fin >> names[nameCount]) {
        ++nameCount;
    }
    fin.close();
    if (nameCount == 0) {
        cerr << "No names found in names.txt file!" << endl;
        return 1;
    }


    int colorCount = 0;
    ifstream finc1("colors.txt");
    if (!finc1) {
        cerr << "Error opening colors.txt file!" << endl;
        return 1;
    }
    while (colorCount < SZ_COLORS && finc1 >> colors[colorCount]) {// finished reading the colors
        ++colorCount;
    }
    finc1.close();
    if (colorCount == 0) {
        cerr << "No colors found in colors.txt file!" << endl;
        return 1;
    }

    list<Goat> trip;

    bool running = true;
    while (running) {//
        int choice = main_menu();
        switch (choice) {
            case 1:
                add_goat(trip, names, nameCount, colors, colorCount);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                running = false;
                cout << "Exiting program." << endl;
                break;
        }
    }

    return 0;
}

int main_menu() {
    // start making th display menu and get user choice
    int choice;
    cout << "\nGoat Trip Menu\n";
    cout << "1. Add a goat to the trip\n";
    cout << "2. Delete a goat from the trip\n";
    cout << "3. Display the trip goats\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

