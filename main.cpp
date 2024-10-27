#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(const list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(const list<Goat> trip);
int main_menu();



int main() {
    srand(time(0));
    bool again;

    list<Goat> trip; //list that holds goat objects



    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

//call main_menu function
bool quit = false;
while (!quit) {
    int choice = main_menu();
    switch(choice){
        case 1:
            add_goat(trip,names,colors);
            break;
        case 2:
            delete_goat(trip);
            break;
        case 3:
            display_trip(trip);
            break;
        case 4:
            quit = true;
            cout << " Exiting Goat Manager 3001";
            break;
        default:
            cout<<"Invalid choice, please try agian. \n";
    }

}

    return 0;
}

int main_menu (){//create a main_menu function
int choice;  //define choice
do
{
cout<<"*** GOAT MANAGER 3001 ***"<< endl;  //*** GOAT MANAGER 3001 ***
//create a do while loop to get choices 1-4
cout<<"[1] Add a goat\n [2] Delete a goat\n [3] List goats\n[4] Quit\n";
cout<< "choice --> ";
} while (choice < 1 || choice > 4); //set the range between 1-4


cin>> choice;
return choice;
};


void add_goat(list<Goat> &trip, const string names[], const string colors [])
{
    string name = names [rand() % SZ_NAMES];
    int age = rand() % ( MAX_AGE + 1 );
    string color = colors [rand() % SZ_COLORS];

    Goat new_goat(name, age, color);
    trip.push_back(new_goat);

    cout<<"Added goat: ";
    new_goat.display();
    cout << endl;


}

//delete selecte goat
void delete_goat(list<Goat> &trip) {
        if (trip.empty()) {
            cout << "No goats to delete. \n";
            return;
        }

        int index = select_goat(trip);
        if (index == -1) return;

        auto it = trip.begin();
        advance(it, index);
        cout<< "Deleting goat: ";
        it -> display();
        trip.erase(it);
}
//display all goats in list
void display_trip(const list<Goat> &trip ) {
    if (trip.empty()) {
         cout << "No goats to delete. \n";
            return;
    }
    int i = 1;
    for (const Goat &g : trip) {
        cout<< "[ "<< i++ << "]";
        g.display();
        cout<< endl;
    }
}
//select goat by index
int select_goat(const list<Goat>& trip) {
    display_trip(trip);
    int choice;
    cout<< "Select a goat by a number (or 0 to cancel): ";
    cin >> choice;

    if (choice < 1 || choice > trip.size()) {
        cout<< " Canceled or invalid choice. \n";
        return -1;
    }
    return choice - 1;

}




/*
Common <list> member functions:
.back()              // returns a reference to the last element in the container
.begin()             // returns an iterator to the first element
.clear()             // removes all elements from the list
.emplace(it, args)   // emplaces, but requires an iterator pointing to an existing element
.emplace_back(args)  // emplaces to the back
.emplace_front(args) // emplaces to the front
.empty()             // returns true if empty; false otherwise
.erase(it)           // erases the element pointed to by the iterator
.front()             // returns a reference to the first element in the container
.insert(it, value)   // inserts value before the element at the specified position
.pop_back()          // removes the last element
.pop_front()         // removes the first element
.push_back(value)    // adds an element to the end
.push_front(value)   // adds an element to the front
.remove(value)       // removes all elements equal to value
.reverse()           // reverses the order of the elements
.sort()              // sorts the elements
.size()              // returns the number of elements
.unique()            // deduplicates the list
*/