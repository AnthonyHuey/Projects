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

int main()
{
   // Make the struct,
    for (int i = 0; i < 4; i++)
    {
        string temp;
        cout << "What the name of restaurant " << i+1 << ": ";
        getline(cin, temp);
        Restaurant temp = uInput(); 
    }

   // Output the struct.
  // output(test);
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
    while (open != 'y' && open != 'n')
    {
        cout <<" Please enter (y)es or (n)o. ";
        cin >> open;
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
    cout << "\nTables/Chairs: " << temp.tables << "/" << temp.chairs;
    if (temp.open == 1) 
        cout << "\nThe store is open!";
    else
        cout << "\nThe store is closed...";
}