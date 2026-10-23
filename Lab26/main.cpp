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
#include "VLS.h"
using namespace std;
using namespace std::chrono;

const int LOOPS = 15, ROWS = 4, COLS = 3, CUBE = 2;
int main() 
{
    double chart[CUBE][ROWS][COLS];
    vector<string> myVector;
    list<string> myList;
    set<string> mySet;

    /* test for the 3d array
    for(int i = 0; i < CUBE; i++)
        for (int j = 0; j < ROWS; j++)
            for (int n = 0; n < COLS; n++)
                chart [i][j][n] = rand();
      for(int i = 0; i < CUBE; i++)
        for (int j = 0; j < ROWS; j++)
            for (int n = 0; n < COLS; n++)
                cout << chart[i][j][n] << " ";
    cout << "Chart test" << chart[0][0][0];
    */
   /* ok where to start. need to pass the times/duration to the 3D array.
    - pass the array as a reference?
    - could also return the time/duration?
        - i dont think return would work for the read.

    gonna ingore the read for now, just gonna use return fo the other funcs
*/

    cout << "\t| VECTOR |\t| LIST |\t| SET |\n" << "READ "; // good enough.
// --- READ -------------------------------------------------------------------
    // functions open the file then pass back the filled container
    myVector = readVector("names.txt");
    myList = readList("names.txt");
    mySet = readSet("names.txt");

// --- SORT -------------------------------------------------------------------
    // sorts the container, simple enough.
    cout << "\nSORT ";
    chart[0][1][1] sortVector(myVector);
    sortList(myList);
    cout << "\t| -1 |"; // set is already sorted

// -- INSERT ------------------------------------------------------------------
    // insert "TESTCODE" into the middle of each
    cout << "\nINSERT ";
    insertVector(myVector);
    insertList(myList);
    insertSet(mySet);
  
// --- DELETE -----------------------------------------------------------------
    // delete the middle-ish element of each.
    cout << "\nDELETE "; 
    deleteVector(myVector);
    deleteList(myList);
    deleteSet(mySet);
   
    return 0;

    
}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
nanoOutput(start, end);
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
