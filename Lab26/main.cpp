// Anthony Huey - 9/23/2026 - COMSC 210 - Lab26 DATA Structures Olympics
// ok, change things to store the resulting in a 3d array
// loop the races 15ish times and average the results.

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// it would be a lot easier to just write a sinlge function for each race
// i loosly remember template but i'd have to relearn it, 
// also i don't even know if it would be allowed. ehh

void nanoOutput(high_resolution_clock::time_point, 
                high_resolution_clock::time_point); 
const int MAX = 20000, LOOPS = 15, ROWS = 4, COLS = 3, CUBE = 2;
int main() 
{
   // double chart[CUBE][ROWS][COLS]; // this is right, took me a while.
    vector<string> myVector;
    list<string> myList;
    set<string> mySet;
    cout << "\t| VECTOR |\t| LIST |\t| SET |\n" << "READ "; // good enough.
// --- READ -------------------------------------------------------------------
    // in the names.txt into each and time it
    ifstream fin;
    fin.open("names.txt");
    if (fin.good()) 
    {   
        auto start = high_resolution_clock::now();
        for (int i = 0; i < MAX; i++)
        {
            string line;
            getline(fin, line);
            myVector.push_back(line);
        }
        auto end = high_resolution_clock::now();
        nanoOutput(start, end);

        start = high_resolution_clock::now();
        for (int i = 0; i < MAX; i++)
        {
            string line;
            getline(fin, line);
            myList.push_back(line);
        }
        end = high_resolution_clock::now();
        nanoOutput(start, end);

        start = high_resolution_clock::now();
        for (int i = 0; i < MAX; i++)
        {
            string line;
            getline(fin, line);
            mySet.insert(line);
        }
        end = high_resolution_clock::now();
        nanoOutput(start, end);

    fin.close();
    }
    else 
        cout << "File not found.\n";

// --- SORT -------------------------------------------------------------------
    // sort each of them, and time it. Set is exempt it gets -1
    cout << "\nSORT ";

    auto start = high_resolution_clock::now();
    sort(myVector.begin(), myVector.end()); // easy way out
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);

    start = high_resolution_clock::now();
    myList.sort();
    end = high_resolution_clock::now();
    nanoOutput(start, end);

    cout << "\t| -1 |"; // set is already sorted

// -- INSERT ------------------------------------------------------------------
    // insert "TESTCODE" into the middle of each, and time it.
    cout << "\nINSERT ";

    start = high_resolution_clock::now();
    myVector.insert(myVector.begin() + myVector.size() / 2, "TESTCODE");
    end = high_resolution_clock::now();
    nanoOutput(start, end);

    auto it = myList.begin();
    advance(it, myList.size() / 2);
    start = high_resolution_clock::now();
    myList.insert(it, "TESTCODE"); // took it/advance out, just testing insert.
    end = high_resolution_clock::now();
    nanoOutput(start, end);

    // uhh? sets are always sorted so there's no point to set a position right? 
    auto sit = mySet.begin(); // the delete needs the middle so might aswell - 
    advance(it, mySet.size() / 2); // - do this here.
    start = high_resolution_clock::now(); 
    mySet.insert(sit, "TESTCODE"); 
    end = high_resolution_clock::now();
    nanoOutput(start, end);

// --- DELETE -----------------------------------------------------------------
    // delete the middle-ish element of each and time it
    cout << "\nDELETE "; // These all use erase, another good spot for template.

    start = high_resolution_clock::now();
    myVector.erase(myVector.begin() + myVector.size() / 2);
    end = high_resolution_clock::now();
    nanoOutput(start, end);

    start = high_resolution_clock::now();
    myList.erase(it); 
    end = high_resolution_clock::now();
    nanoOutput(start, end);

    start = high_resolution_clock::now();
    mySet.erase(sit);
    end = high_resolution_clock::now();
    nanoOutput(start, end);

    return 0;
}

void nanoOutput(high_resolution_clock::time_point start, 
                high_resolution_clock::time_point end) 
{ 
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "\t| " << duration.count() << " |"; 
}
/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
nanoOutput(start, end);
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
