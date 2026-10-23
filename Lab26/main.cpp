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
    long chart[CUBE][ROWS][COLS] = {};
    vector<string> myVector;
    list<string> myList;
    set<string> mySet;

/*  test for the 3d array
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

    gonna ingore the read for now, just gonna use return for the other funcs
    why did i think doubles would work?


   // cout << "\t| VECTOR |\t| LIST |\t| SET |\n" << "READ "; // good enough.
// --- READ -------------------------------------------------------------------
    // functions open the file then pass back the filled container
    myVector = readVector("names.txt");
    myList = readList("names.txt");
    mySet = readSet("names.txt");
    chart[0][0][0] = 0;
    chart[0][0][1] = 0;
    chart[0][0][2] = 0;
// --- SORT -------------------------------------------------------------------
    // sorts the container, simple enough.
   // cout << "\nSORT ";
    chart[0][1][0] = sortVector(myVector);
    chart[0][1][1] = sortList(myList);
    chart[0][1][2] = -1 ;

// -- INSERT ------------------------------------------------------------------
    // insert "TESTCODE" into the middle of each
    //cout << "\nINSERT ";
    chart[0][2][0] = insertVector(myVector);
    chart[0][2][1] = insertList(myList);
    chart[0][2][2] = insertSet(mySet);
  
// --- DELETE -----------------------------------------------------------------
    // delete the middle-ish element of each.
   // cout << "\nDELETE "; 
    chart[0][3][0] = deleteVector(myVector);
    chart[0][3][1] = deleteList(myList);
    chart[0][3][2] = deleteSet(mySet);



    ok

    loop through first layer. 
    in row 0, column 0 use readVector
    in row 0, column 1 use readList
    in row 0, column 2 use readSet

    repeat for each row.

    save each result to a ongoing tally for layer 1. worry later

    repeat 15 times. x

    work backwards?
*/
for (int l = 0; l < LOOPS; l++) // loop 15 times
{
// --- READ ---
    chart[0][0][0] = readVector("names.txt");;
    chart[0][0][1] = readList("names.txt");;
    chart[0][0][2] = readSet("names.txt", mySet);;

 //--- SORT ---
    chart[0][1][0] = sortVector(myVector);
    chart[0][1][1] = sortList(myList);
    chart[0][1][2] = 0;

 //--- INSERT ---              
    chart[0][2][0] = insertVector(myVector);
    chart[0][2][1] = insertList(myList);
    chart[0][2][2] = insertSet(mySet);
  
 //--- DELETE ---
    chart[0][3][0] = deleteVector(myVector);
    chart[0][3][1] = deleteList(myList);
    chart[0][3][2] = deleteSet(mySet);
 

    for (int j = 0; j < ROWS; j++)
        for (int n = 0; n < COLS; n++)
            chart[1][j][n] += chart[0][j][n];
}


    for (int j = 0; j < ROWS; j++)
    {
        cout << endl;
        for (int n = 0; n < COLS; n++)
            cout << "| "<< chart[0][j][n] << " |";
    }
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now();
auto end = high_resolution_clock::now();
nanoOutput(start, end);
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
