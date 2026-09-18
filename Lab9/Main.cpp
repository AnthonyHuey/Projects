// Anthony Huey - 9/18/2026 - COMSC 210 - STD::array & STD Vector
// Show understanding of STD::array/vector

#include <iostream>
#include <array>
#include <vector>
#include <fstream>


using namespace std;

const int MAX = 10;

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

    // sets r to a random #, get the # from array at r
    srand(time(0));
    int r = 0;
    for (int i = 0; i < 5; i++) 
    cout << "\nElement " << ((r = rand() % MAX) + 1) << ": " << list.at(r);

    cout << "\nMax: " << *max_element(list.begin(), list.end());
    cout << "\nMin: " << &min_element(list.begin(), list.end());


    


    // do it all again for <vector>

}