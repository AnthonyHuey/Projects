// Anthony Huey - 9/18/2026 - COMSC 210 - STD::array & STD Vector
// Show understanding of STD::array/vector

#include <iostream>
#include <array>
#include <vector>
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
        fin >> list;


    }
    else
        cout << "File not found.\n";

    // have some fun with <array> functions

    // do it all again for <vector>

}