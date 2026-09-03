// Anthony Huey - 9/3/2026 - Lab3 Resaurant Structs
//create a struct, fill it with user data, output to console

#include <iostream>
#include <string>

using namespace std;

// Struct Template
struct Restaurant
{
    string name;
    int chairs;
    int tables;
    bool open;
};
// Function for filling struct with user data
Restaurant uInput();
// Function for outputting struct to console
void output(const Restaurant &);

const int MAX = 4;

int main()
{
   // Make the struct, 
   Restaurant list[MAX];
   for (int i = 0; i < MAX; i++)
     list[i] = uInput(); 

   // Output the struct.
   for (int i = 0; i < MAX; i++)
     output(list[i]);
}
// Make a temp restaurant to store data then pass that over to main.
Restaurant uInput()
{
    Restaurant temp;

    cout << "What the name of the restaurant? ";
    getline(cin, temp.name);

    cout << "How many Chairs? ";
    cin >> temp.chairs;
    cin.ignore();

    cout << "How many Tables? ";
    cin >> temp.tables;
    cin.ignore();

    // ok more complicated,check their string input (y/n) and set the bool? 
    char open;
    cout << "Is the restaurant open. (y/n) ";
    cin >> open;
    cin.ignore();
    while (open != 'y' && open != 'n')
    {
        cout <<" Please enter (y)es or (n)o. ";
        cin >> open;
        cin.ignore();
    }
    if (open == 'y')
        temp.open = 1;
    else
        temp.open = 0;
    
    return temp;
}
// simple cout
void output(const Restaurant &temp)
{
    cout << "Name: " << temp.name;
    cout << "\tTables/Chairs: " << temp.tables << "/" << temp.chairs;
    if (temp.open == 1) 
        cout << "\tThe store is open!\n";
    else
        cout << "\tThe store is closed...\n";
}