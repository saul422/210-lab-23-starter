#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();



int main() {
    srand(time(0));
    bool again;

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


    return 0;
}

int main_menu (){//create a main_menu function
cout<<//*** GOAT MANAGER 3001 ***
//[1] Add a goat
//[2] Delete a goat
//[3] List goats
//[4] Quit
//choice -->












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