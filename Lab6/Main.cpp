// Anthony Huey - 9/12/2026 - Arrays & Functions 1
// Use functions to manipulate dynamically allocated arrays
// USE POINTER NOTATION

#include <iostream>

using namespace std;

// Fill Array with data
double* enterArrayData();

// Output the arrays data on a single line
void outputArrayData(double[]);

// Add all the values of the array up and output the sum
void sumArray(double[]);
// Max size of the array

const int MAX = 5;

int main()
{
    double *testptr = nullptr;
    testptr = enterArrayData();         // Create/fill array
    cout << "Data entry complete. ";
    outputArrayData(testptr);           // Output 
    cout << "\n";
    sumArray(testptr);                  // Sum

    delete [] testptr;                  // never forget to delete.
}

double* enterArrayData()
{
    double *array = nullptr;
    array = new double[MAX];
    cout << "\nData entry fo the array: \n";
    for (int i = 0; i < MAX; i++)
    {
        double entry = 0;
        cout << "Element#" << i << ": ";
        cin >> entry;
        cin.ignore();
        *(array + i) = entry; 
    }
    return array;
}

void outputArrayData(double array[])
{
    cout << "Outputting array elements: ";
    for (int i = 0; i < MAX; i++)
        cout << *(array + i) << " ";
}

void sumArray(double array[])
{
    double sum = 0;
    for (int i = 0; i < MAX; i++)
        sum = *(array + i) + sum;
    cout << "Sum of all values: " << sum;
}
    