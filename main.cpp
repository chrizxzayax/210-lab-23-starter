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
        nameCount++;
    }
    fin.close();
    ifstream fin1("colors.txt");
    if (!fin1) {
        cerr << "Error opening colors.txt file!" << endl;
        return 1;
    }
    while (colorCount < SZ_COLORS && fin1 >> colors[colorCount]) {
        colorCount++;
    }
    fin1.close();

    int colorCount = 0;
    ifstream finc1("colors.txt");
    if (!finc1) {
        cerr << "Error opening colors.txt file!" << endl;
        return 1;
    }
    while (colorCount < SZ_COLORS && finc1 >> colors[colorCount]) {
        colorCount++;
    }
    finc1.close();

    return 0;
}

