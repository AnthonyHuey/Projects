// Anthony Huey - 9/25/2026 - COMSC 210 - Lab13: Student Grade Sorter
// Sort a list of student grades into an array of structs, ID/Score
// Write the results to a file, along with a summary.

#include <iostream>
#include <fstream>
#include <array>
#include <cmath> 

using namespace std;

// Hold the Input file data
struct Student
{
    int id;
    double grade;
};

const int MAX = 150; 

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

    // sort array, somewhat familiar from CS 200 minus the c style array
        // from what i remember, compare each i to a j if j is <, swap.
        for (int i = 0; i < list.size(); i++)
        {
            // starts at beginning then increments
            int min = i;

            // setup second loop to do comparison
            for (int j = i + 1; j < list.size(); j++)
                if (list[j].id < list[min].id)
                    min = j;

            // now swap, dont forget the grade...
            if (min != i)
            {
                swap(list[i].grade, list[min].grade);
                swap(list[i].id, list[min].id);
            }
        }

    // output array
    ofstream fout;
    fout.open("210-lab-13-grades-sorted.txt");
        for (int i = 0; i < list.size(); i++)
            {
                fout << list[i].id << "\t";
                fout << list[i].grade << "\n";
            }
        fout.close();

    // cout summary
    int min = 0;
    int max = 0;
    double mean = 0;
    int median = 0;
    
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].grade < list[min].grade)
            min = i;
        if (list[i].grade > list[max].grade)
            max = i;
    }
    cout << "Min Score: " << list[min].grade << " From ID: " << list[min].id;
    cout << "\nMax Score: " << list[max].grade << " From ID: " << list[max].id;

   
    for (int i = 0; i < list.size(); i++)
            mean = list[i].grade + mean;
    
    mean = mean / list.size();
    cout << "\nMean Score: " << mean;

    // need to find median grade. needs to be sorted first. just gonna resort
    for (int i = 0; i < list.size(); i++)
    {
            int min = i;
            for (int j = i + 1; j < list.size(); j++)
                if (list[j].grade < list[min].grade)
                    min = j;

            if (min != i)
            {
                swap(list[i].grade, list[min].grade);
                swap(list[i].id, list[min].id);
            }
    }
    // then find middle value, it'll be 75 ish
    // if th enumber is even, it's more complicated
    if (list.size() % 2 == 0)
        median = (list.size() / 2 - 1);
    else
        median = list.size() / 2;
    cout << "\nMedian Score: " << list[median].grade 
         << " from ID: " << list[median].id;

    // figure out what standard deviation is.
    // okay, its the "deviation" from the mean.

    // add the sum, of the square, of the difference the grades from the mean...
    double sum;
    for (int i = 0; i < list.size(); i++)
        sum = sum + (list[i].grade - mean) * (list[i].grade - mean);

    // then divide by size of list
    sum = sum / list.size();

    // take the square root
    sum = sqrt(sum);

    cout << "\nStandard Deviation: " << sum;
}
