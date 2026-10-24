// Anthony Huey - 9/24/2026 - COMSC 210 - Lab 27: Villager Map
// Change the villagers favorite color to a tuple -
// Friendship level(0-10), Species(string), Cathphrase(string)
// Add menu-driven program to interact with villagers
#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // for tuple?
using namespace std;

void outputVillagers( map<string, tuple<int, string, string>> );

int main() 
{
    // declarations - Friend - Species - Cathprash
    map<string, tuple<int, string, string>> villager;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    //villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});
    villager["Kevin"] = {3, "Human", "woah..."};
    villager["Mark"] = {0, "Human", "hmm..."};
    villager.insert({"Zug", {7, "Orc", "zug zug"}});

    // compile-time indices
    //int friendshipLevel = get<0>(villager);
    //string species = get<1>(villager);
    //string phrase = get<2>(villager)
    
    // access the map using a range-based for loop
    cout << "Villagers details:" << endl;
    for (const auto& [name, stats] : villager) //ok, first is the key
    {          // the touple is stats which is all tied together, either unpack
            //  with another auto&, or point at what you want with get<n>(stats)
        const auto& [level, species, phrase] = stats;
        cout << name << ": " << level << " " << species << " " << phrase << endl;
        cout << endl << name << ": " << get<0>(stats) <<  " " << get<1>(stats)
                                     << " " << get<2>(stats) << endl;
    }
/*
    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villager.begin(); 
                                               it != villager.end(); ++it) 
    {
        cout << it->first << ": ";
        for (auto color : it->second) 
            cout << color << " ";
        cout << endl;
    }

    // delete an element
    villager.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villager.find(searchKey);
    if (it != villager.end()) // the iterator points to beyond the end of the map
    {                               // if searchKey is not found
                                     
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } 
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villager.size() << endl;
    villager.clear();
    cout << "Size after clear: " << villager.size() << endl;
*/
    return 0;
}

void outputVillagers( map<string, tuple<int, string, string>> out)
{

}