#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string names[], int nameCount, string colors[], int colorCount);// fixed prototype
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // read & populate arrays for names and colors

    string names[SZ_NAMES];
    string colors[SZ_COLORS];


    ifstream fin("names.txt");
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}

