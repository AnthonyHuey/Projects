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
        fin.close();
    }
    else 
        cout << "File not found.\n";
    

    /* checking that the file input worked;
    cout << " ID \t GRADE ";
    for (int i = 0; i < (list.size() - 1); i++)
        cout << "\n" << list[i].id << "\t" << list[i].grade;
    */

    // sort array, somewhat familiar from CS 200 minus the c style array
        // from what i remember, compare each i to a j if j is < swap.
        for (int i = 0; i < list.size(); i++)
        {
            // starts at beginning then increments
            int min = i;

            // setup second loop to do comparison
            for (int j = i + 1; j < list.size(); j++)
                if (list[j].grade < list[min].grade)
                    min = j;

            // now swap, dont forget the ID
            if (min != i)
            {
                swap(list[i].grade, list[min].grade);
                swap(list[i].id, list[min].id);
            }
        }

    // output array
    ofstream fout;
    fout.open("210-lab-13-grades-sorted.txt");
        for (int i = 1; i < list.size(); i++)
            {
                fout << list[i].id << "\t";
                fout << list[i].grade << "\n";
            }
        fout.close();
}
