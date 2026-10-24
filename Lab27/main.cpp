// Anthony Huey - 9/24/2026 - COMSC 210 - Lab 27: Villager Map
// Change the villagers favorite color to a tuple -
// Friendship level(0-10), Species(string), Cathphrase(string)
// Add menu-driven program to interact with villagers
#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // for tuple?
using namespace std;

void outputVillagers(map<string, tuple<int, string, string>>);
void searchVillagers(map<string, tuple<int, string, string>>);
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
int main() 
{
/* 
ok, Loop though an outer menu, while loop until exit

1. Add Villager
    - make anew villager from user input
2. Delete Villager
    - use .erase
3. Increase Friendship
    - add a single point, 0 - 10
4. Decrease Friendship
    - remove a single point 0 -10
5. Search for Villager
    - outputs a villagers stats?
6. Exit
    - breaks free from the while ending program

always output the maps contents after each operation.
*/
  // declarations - Friend - Species - Catchprash
    map<string, tuple<int, string, string>> villager;

    villager["Kevin"] = {3, "Human", "woah..."};
    villager["Mark"] = {0, "Human", "hmm..."};
    villager.insert({"Zug", {7, "Orc", "zug zug"}});

    bool loop = 0;
    while (loop != 1)
    {
        int choice = 0;
        cout << "1. Add villager\n"
             << "2. Delete villager\n"
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Search for Villager\n"
             << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1: addVillager(villager);
                    outputVillagers(villager); break;
            case 2: deleteVillager(villager);
                    outputVillagers(villager); break;
            case 3: increaseFriendship(villager); 
                    outputVillagers(villager); break;
            case 4: decreaseFriendship(villager);  
                    outputVillagers(villager); break;    
            case 5: searchVillagers(villager); 
                    outputVillagers(villager); break;
            case 6: loop = 1; cout << "Goodbye!"; 
                                               break;    
        }
    }
  
    return 0;
}
void outputVillagers( map<string, tuple<int, string, string>> output)
{//ok, first is the key
 // the touple is stats which is all tied together, either unpack
 // with another auto&, or point at what you want with get<n>(stats)
    cout << "Villagers details:" << endl;
    for (const auto& [name, stats] : output) 
    {         
        const auto& [level, species, phrase] = stats;
        cout << name << " [" << level << ", " 
                             << species << ", " 
                             << phrase << "]" << endl;
    }
}
void searchVillagers(map<string, tuple<int, string, string>> v)
{
    string searchKey;
    cout << "Enter name: ";
    getline(cin, searchKey);
    auto it = v.find(searchKey);
    if (it != v.end()) // the iterator points to beyond the end of the map
    {                               // if searchKey is not found                                 
        cout << "\nFound " << searchKey << "'s stats: ";
        cout << get<0>(it->second) << " "
             << get<1>(it->second) << " "
             << get<2>(it->second) << endl;
        cout << endl;
    } 
     
    else
        cout << endl << searchKey << " not found." << endl;
}
void increaseFriendship(map<string, tuple<int, string, string>>& v)
{
    string searchKey;
    cout << "Which villagers friendship would you like to increase: ";
    getline(cin, searchKey);
    auto it = v.find(searchKey);
    if (it != v.end()) // the iterator points to beyond the end of the map
    {                               // if searchKey is not found   
        if (get<0>(it->second) < 10)
        {                              
            cout << "\nFound " << searchKey << "'s Friendship: ";
            cout << get<0>(it->second) << " increased to ";
            get<0>(it->second)++;
            cout << get<0>(it->second);
            cout << endl;
        }
        else 
        {
            cout << "Friendship limit reached!\n";
            return;
        }
    } 
     
    else
        cout << endl << searchKey << " not found." << endl;
}
void decreaseFriendship(map<string, tuple<int, string, string>>& v)
{
    string searchKey;
    cout << "Which villagers friendship would you like to decrease: ";
    getline(cin, searchKey);
    auto it = v.find(searchKey);
    if (it != v.end()) // the iterator points to beyond the end of the map
    {                               // if searchKey is not found                                 
        if (get<0>(it->second) > 1)
        {                              
            cout << "\nFound " << searchKey << "'s Friendship: ";
            cout << get<0>(it->second) << " decreased to ";
            get<0>(it->second)--;
            cout << get<0>(it->second);
            cout << endl;
        }
        else 
        {
            cout << "Friendship limit reached!\n";
            return;
        }
    }
    else
        cout << endl << searchKey << " not found." << endl;
}
void addVillager(map<string, tuple<int, string, string>>& v)
{
    string name;
    int level;
    string species;
    string phrase;

    cout << "What is this villager's name: ";
    getline(cin, name);
    cout << "What is this villager's friendship level: ";
    cin >> level;
    cin.ignore();
    cout << "What is this villager's species: ";
    getline(cin, species);
    cout << "What is this villager's catchphrase: ";
    getline(cin, phrase);

    v.insert({name, {level, species, phrase}});
}
void deleteVillager(map<string, tuple<int, string, string>>& v)
{

}

/* saving to reference back to later.
    villager["Kevin"] = {3, "Human", "woah..."};
    villager["Mark"] = {0, "Human", "hmm..."};
    villager.insert({"Zug", {7, "Orc", "zug zug"}});
    outputVillagers(villager);
    
    // access the map using iterators
    cout << "\nVillagers and their stats (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villager.begin(); 
                                               it != villager.end(); ++it) 
    {
        cout << it->first << ": " << get<0>(it->second) << " "
                                  << get<1>(it->second) << " "
                                  << get<2>(it->second) << endl;
        
        cout << endl;
    }

    // delete an element
    villager.erase("Mark");

    // search for an element using .find() to avoid errors
    string searchKey = "Zug";
    auto it = villager.find(searchKey);
    if (it != villager.end()) // the iterator points to beyond the end of the map
    {                               // if searchKey is not found                                 
        cout << "\nFound " << searchKey << "'s stats: ";
        cout << get<0>(it->second) << " "
             << get<1>(it->second) << " "
             << get<2>(it->second) << endl;
        cout << endl;
    } 
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villager.size() << endl;
    villager.clear();
    cout << "Size after clear: " << villager.size() << endl;
*/
   

