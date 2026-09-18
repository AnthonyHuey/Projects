// Anthony Huey - 9/18/2026 - COMSC 210 - STD::array & STD Vector
// Show understanding of STD::array/vector

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAX = 30;

int main()
{
// Create the STD::array
    array<int, MAX> list; 
        
// Fill it with fin
    ifstream fin;
    fin.open("list.txt");
    if (fin.good())
    {
       for (int i = 0; i < list.size(); i++)
            fin >> list.at(i);
        fin.close();  
    }    
    else
        cout << "File not found.\n";

    for (int val : list) cout << val << " ";

// have some fun with <array> functions
    cout << "\nEmpty? " << (list.empty() == 0? "False" : "True"); // neat
    cout << "\nFirst: " << list.front();
    cout << "\nLast: " << list.back();
    cout << "\nAddress? " << list.data();

// sets r to a random #, get the # from array at r
    srand(time(0));
    int r = 0;
    for (int i = 0; i < 5; i++) 
        cout << "\nElement " << ((r = rand() % MAX) + 1) << ": " << list.at(r);

    cout << "\n\t-----SORTING-----\t\n";
    sort(list.begin(), list.end());
    cout << "sorted.";
    for (int val : list) cout << val << " ";

    int search = 0;
    cout << "\nWhat # would you like to search for: ";
    cin >> search;
    cin.ignore();

    array<int, MAX>::iterator it;
    it = find(list.begin(), list.end(), search);
    cout << "Value " << search;
    if (it != list.end())
        cout << " found in position " << it - list.begin();
    else
        cout << " was not found.";

//not using #include <numeric> for accumulate.
    int total = 0; 
    for (int i = 0; i < MAX; i++)
        total = list.at(i) + total;
    cout <<  "\nTotal of all #'s is: " << total;
    cout << "\n\n\t-----VECTOR-----\t\n\n";

// do it all again for <vector>

// Create the STD::array
    vector<int> table;
        
// Fill it with fin
    //ifstream fin;
    fin.open("table.txt");
    if (fin.good())
    {
       for (int i = 0; i < MAX; i++)
       {    
            int temp;
            fin >> temp;
            table.push_back(temp);
       }
        fin.close();  
    }    
    else
        cout << "File not found.\n";

    for (int val : table) cout << val << " ";

// have some fun with <array> functions
    cout << "\nEmpty? " << (table.empty() == 0? "False" : "True"); // neat
    cout << "\nFirst: " << table.front();
    cout << "\nLast: " << table.back();
    cout << "\nAddress? " << table.data();

// sets r to a random #, get the # from array at r
    srand(time(0));
    r = 0;
    for (int i = 0; i < 5; i++) 
        cout << "\nElement " << ((r = rand() % MAX) + 1) << ": " << table.at(r);

    cout << "\n\t-----SORTING-----\t\n";
    sort(table.begin(), table.end());
    cout << "sorted.";
    for (int val : table) cout << val << " ";

    search = 0;
    cout << "\nWhat # would you like to search for: ";
    cin >> search;
    cin.ignore();

    vector<int>::iterator iter;
    iter = find(table.begin(), table.end(), search);
    cout << "Value " << search;
    if (iter != table.end())
        cout << " found in position " << iter - table.begin();
    else
        cout << " was not found.";

//not using #include <numeric> for accumulate.
    total = 0; 
    for (int i = 0; i < table.size(); i++)
        total = table.at(i) + total;
    cout <<  "\nTotal of all #'s is: " << total;

}
