// Anthony Huey - 10/25/2026 - COMSC 210 - Lab 28: STL algorithms
// Using lab 24 lab soloution, add 8 different stl algo's to the menu.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <algorithm>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();
// New STL algorithms ------------------
void clear_goat(list<Goat> &trip);
void reverse_goat(list<Goat> &trip);
void sort_goat(list<Goat> &trip);
void _goat(list<Goat> &trip);


int main() 
{
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

    // create & populate a trip of Goats using std::list of random size 8-15
    int tripSize = rand() % 8 + 8;
    list<Goat> trip;
    int age;
    string name, color;
    for (int i = 0; i < tripSize; i++)
    {
        age = rand() % MAX_AGE;  // defined in Goat.h
        name = names[rand() % SZ_NAMES];
        color = colors[rand() % SZ_COLORS];
        Goat tmp(name, age, color);
        trip.push_back(tmp);
    }
    
    // Goat Manager 3001 Engine
    int sel = main_menu();
    while (sel != 12) 
    {
        switch (sel) 
        {
            case 1:
                cout << "Adding a goat.\n";
                add_goat(trip, names, colors);
                break;
            case 2:    
                cout << "Removing a goat.\n";
                delete_goat(trip);
                break;
            case 3:    
                cout << "Displaying goat data.\n";
                display_trip(trip);
                break;
// New STL Algorithms -----------------------
            case 4:    // clears all the data from the list
                cout << "Clearing goat data\n";
               clear_goat(trip);
                break;   
            case 5: // Reverses the data from the list
                cout << "Reverse goat data\n";
                reverse_goat(trip);
                break;   
            case 6:    
                cout << "find a goat\n";
                find_goat(trip);
                break;   
            case 7:    
                cout << "\n";
               
                break;   
            case 8:    
                cout << "\n";
               
                break;   
            case 9:
                cout << "\n";
               
                break;   
            case 10:    
                cout << "\n";
               
                break;   
            case 11:    
                cout << "\n";
               
                break;
// ---------------------------------------------                             
            default:
                cout << "Invalid selection.\n";
                break;
        }
        sel = main_menu();
    }
    

    return 0;
}

int main_menu() 
{
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    // New STL Algorithms ----------
    cout << "[4] Clear all goats\n";
    cout << "[5] Reverse all goats\n";
    cout << "[6]  all goats\n";
    cout << "[7] \n";
    cout << "[8] \n";
    cout << "[9] \n";
    cout << "[10] \n";
    cout << "[11] \n";
    //------------------------------
    cout << "[12] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 13) 
    {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

void delete_goat(list<Goat> &trip) 
{
    cout << "DELETE A GOAT\n";
    int index = select_goat(trip);
    auto it = trip.begin();
    advance(it, index-1);
    trip.erase(it);
    cout << "Goat deleted. New trip size: " << trip.size() << endl;
}

void add_goat(list<Goat> &trip, string nms[], string cls[]) 
{
    cout << "ADD A GOAT\n";
    int age = rand() % MAX_AGE;
    string nm = nms[rand() % SZ_NAMES];
    string cl = cls[rand() % SZ_COLORS];
    Goat tmp(nm, age, cl);
    trip.push_back(tmp);
    cout << "Goat added. New trip size: " << trip.size() << endl;
}

void display_trip(list<Goat> trp) 
{
    int i = 1;
    for (auto gt: trp)
        cout << "\t" 
             << "[" << i++ << "] "
             << gt.get_name() 
             << " (" << gt.get_age() 
             << ", " << gt.get_color() << ")\n";
}

int select_goat(list<Goat> trp) 
{
    int input;
    cout << "Make a selection:\n";
    display_trip(trp);
    cout << "Choice --> ";
    cin >> input;
    while (input < 1 or input > trp.size()) {
        cout << "Invalid choice, again --> ";
        cin >> input;
    }
    return input;
}

void clear_goat(list<Goat> &trip) // clears the list of all data.
{
    trip.clear();
    cout << "Goat data cleared.\n";
}

void reverse_goat(list<Goat> &trip)
{
    reverse(trip.begin(),trip.end());
    cout << "Goats have been reversed!\n";
}

void find_goat(list<Goat> &trip)
{
    
}

void _goat(list<Goat> &trip)
{
    
}