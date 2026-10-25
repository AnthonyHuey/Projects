// Anthony Huey - 10/25/2026 - COMSC 210 - Lab 28: STL algorithms
// Using lab 24 lab soloution, add 8 different stl algo's to the menu.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <numeric>
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
void find_goat(list<Goat> &trip);
void each_goat(list<Goat> &trip);
void accumulate_goat(list<Goat> &trip);


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
                cout << "Find a goat\n";
                find_goat(trip);
                break;   
            case 7:    
                cout << "Birthday!\n";
                each_goat(trip);
                break;   
            case 8:    
                cout << "Finding sum of all the goats age\n";
                accumulate_goat(trip);
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
    cout << "[6] Find a goat\n"; // find a goat you know everything about
    cout << "[7] Birthday for all goats\n";
    cout << "[8] Sum of all goat age\n";
    cout << "[9] \n";
    cout << "[10] \n";
    cout << "[11] \n";
    //------------------------------
    cout << "[12] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 12) 
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

void reverse_goat(list<Goat> &trip) // Reverses the list of data
{
    reverse(trip.begin(),trip.end());
    cout << "Goats have been reversed!\n";
}

void find_goat(list<Goat> &trip) // Finds a goat by name, depend on operator==
{
    string name;
    cout << "Enter the name of goat you would like to find: ";
    cin >> name; 
    auto it = find(trip.begin(), trip.end(), name);
    if (it != trip.end())
        cout << "Found the goat: " << it->get_name() << endl;
    else
        cout << "Goat not found...\n";
}

void each_goat(list<Goat> &trip) // add 1 to all the goats age.
{   
    for_each(trip.begin(), trip.end(),
                [](Goat &n) {n.set_age(n.get_age() + 1); });
     cout << "Happy birthday to all goats!\n";
}

void accumulate_goat(list<Goat> &trip) // add all the goats ages together
{
    // needed numeric. need to return a sum.
    int total = accumulate(trip.begin(), trip.end(), 0,
                [](int sum, Goat &n) {return sum + n.get_age(); });
    cout << "All of the goats age added together is: " << total << endl;
    //reading the wacky error from stl_numeric helped a lot with this one.
    // put sum in enough places and it evetually works.
}