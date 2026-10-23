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
/*
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
    chart[0][0][0] = readVector("names.txt", myVector);
    chart[0][0][1] = readList("names.txt", myList);
    chart[0][0][2] = readSet("names.txt", mySet);

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

    for (int j = 0; j < ROWS; j++) // don't forget to take the avverage...
        for (int n = 0; n < COLS; n++)
            chart[1][j][n] /= LOOPS;

    cout << "Previous runs runtime: ";
    for (int j = 0; j < ROWS; j++)
    {
        cout << endl;
        for (int n = 0; n < COLS; n++)
            cout << "| "<< chart[0][j][n] << " |";
    }

    cout << "\n Average across " << LOOPS << " runs: ";
    for (int j = 0; j < ROWS; j++)
    {
        cout << endl;
        for (int n = 0; n < COLS; n++)
            cout << "| "<< chart[1][j][n] << " |";
    }
    return 0;
}

