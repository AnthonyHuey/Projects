// Anthony Huey - 9/23/2026 - COMSC 210 - Lab26 DATA Structures Olympics
// ok, change things to store the resulting in a 3d array
// loop the races 15ish times and average the results.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include "VLS.h"
using namespace std;

// Cube = depth/sets of data, Rows&Columns = the acutual data
const int LOOPS = 15, ROWS = 4, COLS = 3, CUBE = 2;
int main() 
{
/*
    ok
    go through first layer. 
    in row 0, column 0 use readVector
    in row 0, column 1 use readList
    in row 0, column 2 use readSet

    repeat for each row.

    save each result to a ongoing tally for layer 1.

    repeat 15 times. 
*/ 

    long long chart[CUBE][ROWS][COLS] = {};
    vector<string> myVector = {}; 
    list<string> myList = {};   
    set<string> mySet = {};
    const string labels[ROWS] = {"READ", "SORT", "INSERT", "DELETE"};
    for (int l = 0; l < LOOPS; l++) // loop 15 times
    {
        myVector = {}; // clear for each loop or it gets silly.
        myList = {};   
        mySet = {};

    // --- READ ---
        chart[0][0][0] = readVector("names.txt", myVector); //  passed by ref
        chart[0][0][1] = readList("names.txt", myList);    // returns a long
        chart[0][0][2] = readSet("names.txt", mySet);     // placed in chart

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
    
        for (int j = 0; j < ROWS; j++) // add together all chart values.
            for (int n = 0; n < COLS; n++)
                chart[1][j][n] += chart[0][j][n];
        
    }
    for (int j = 0; j < ROWS; j++) // don't forget to take the average...
        for (int n = 0; n < COLS; n++)
            chart[1][j][n] /= LOOPS;
// PREVIOUS --- prints the first layer, holds the previous runs data
    cout << "Previous run runtime: ";
    cout << "\nOPERATION\t| VECTOR |\t| LIST |\t| SET | ";
    for (int j = 0; j < ROWS; j++)
    {
        cout << endl;
        cout << labels[j] << "\t";
        for (int n = 0; n < COLS; n++)
            cout << "\t| "<< chart[0][j][n] << " |";
    }
// AVERAGE --- prints the second "layer" which hold the average
    cout << "\n Average across " << LOOPS << " runs: ";
    cout << "\nOPERATION\t| VECTOR |\t| LIST |\t| SET | ";
    for (int j = 0; j < ROWS; j++)
    {
        cout << endl;
        cout << labels[j] << "\t";
        for (int n = 0; n < COLS; n++)
            cout << "\t| "<< chart[1][j][n] << " |";
    }
    return 0;
}

