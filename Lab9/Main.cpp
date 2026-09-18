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

    // sets r toa random #, get the # from array at r
    srand(time(0));
    int r = 0;
    for (int i = 0; i < 5; i++) 
        cout << "\nElement " << ((r = rand() % MAX) + 1) << ": " << list.at(r);

    int search = 0;
    cout << "What # would you like to search for: ";
    cin >> search;
    cin.ignore();

    array<int, MAX>::iterator it;
    it = find(list.begin(), list.end(), search);
    cout << "Value " << search;
    if (it != list.end())
        cout << " found in position " << it - list.begin();
    else
        cout << " was not found.";


    // do it all again for <vector>

}
