// Anthony Huey - 9/25/2026 - COMSC 210 - Lab13: Student Grade Sorter
// Sort a list of student grades into an array of structs, ID/Score
// Write the results to a file, along with a summary.

#include <iostream>
#include <fstream>
#include <array>

using namespace std;

// Hold the Input file data
struct Student
{
    int id;
    double grade;
};

const int MAX = 151; // just for testing now, probably

int main()
{
    // create array
    array<Student, MAX> list;
    // fill array with data
    ifstream fin;
    fin.open ("210-lab-13-grades.txt");
    if (fin.good())
    {
        for (int i = 0; i < list.size(); i ++)
        {   
            fin >> list[i].id; 
            fin >> list[i].grade; 
        }
    }
    else 
        cout << "File not found.\n";

    // checking that the file input worked;
    cout << " ID \t GRADE ";
    for (int i = 0; i < (list.size() - 1); i++)
        {
            cout << "\n" << list[i].id << "\t" << list[i].grade;
        }
    // sort array
        

    // output array

    
}
