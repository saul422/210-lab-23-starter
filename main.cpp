#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Goat.h"
using namespace std;

// Constants
const int SZ_NAMES = 200;
const int SZ_COLORS = 25;
const int MAX_AGE = 20;

// Function prototypes
int select_goat(const list<Goat>& trip);
void delete_goat(list<Goat>& trip);
void add_goat(list<Goat>& trip, const string[], const string[]);
void display_trip(const list<Goat>& trip);
int main_menu();

int main() {
    srand(static_cast<unsigned>(time(0)));

    list<Goat> trip;
    string names[SZ_NAMES];
    string colors[SZ_COLORS];

    // Read names and colors from files
    ifstream fin("names.txt");
    int i = 0;
    while (fin >> names[i++] && i < SZ_NAMES);
    fin.close();

    ifstream fin1("colors.txt");
    i = 0;
    while (fin1 >> colors[i++] && i < SZ_COLORS);
    fin1.close();

    // Main loop
    bool quit = false;
    while (!quit) {
        int choice = main_menu();
        switch (choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                quit = true;
                cout << "Exiting Goat Manager 3001." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}

// Main menu function
int main_menu() {
    int choice;
    do {
        cout << "\n*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    return choice;
}

// Add a goat to the list
void add_goat(list<Goat>& trip, const string names[], const string colors[]) {
    string name = names[rand() % SZ_NAMES];
    int age = rand() % (MAX_AGE + 1);
    string color = colors[rand() % SZ_COLORS];

    Goat new_goat(name, age, color);
    trip.push_back(new_goat);

    cout << "Added goat: ";
    new_goat.display();
    cout << endl;
}

// Delete a goat from the list
void delete_goat(list<Goat>& trip) {
    if (trip.empty()) {
        cout << "No goats to delete." << endl;
        return;
    }

    int index = select_goat(trip);
    if (index == -1) return;

    auto it = trip.begin();
    advance(it, index);
    cout << "Deleting goat: ";
    it->display();
    cout << endl;
    trip.erase(it);
}

// Display all goats in the list
void display_trip(const list<Goat>& trip) {
    if (trip.empty()) {
        cout << "No goats to display." << endl;
        return;
    }

    int i = 1;
    for (const Goat& g : trip) {
        cout << "[" << i++ << "] ";
        g.display();
        cout << endl;
    }
}

// Select a goat by index
int select_goat(const list<Goat>& trip) {
    display_trip(trip);
    int choice;
    cout << "Select a goat by number (or 0 to cancel): ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(trip.size())) {
        cout << "Canceled or invalid choice." << endl;
        return -1;
    }
    return choice - 1;
}
