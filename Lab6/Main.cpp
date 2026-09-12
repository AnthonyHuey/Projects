// Anthony Huey - 9/12/2026 - Arrays & Functions 1
// Use functions to manipulate dynamically allocated arrays
// USE POINTER NOTATION

#include <iostream>

using namespace std;

// Fill Array with data
double enterArrayData(double[]);

// Output the arrays data on a single line
double outputArrayData(double[]);

// Add all the values of the array up and output the sum
void sumArray(double[]);
// Max size of the array
const int MAX = 5;

int main()
{
    // Create the array/Fill it with data

    // Output

    // Sum
    
    // quick tests
    double array[MAX] = {1,2,3,4,5};

    double *ptr = nullptr; 

    ptr = array;

    for (int i = 0; i < MAX; i++)
        cout << "List: " << ptr[i] << " ";
   
    for (int i = 0; i < MAX; i++)
        cout <<"\n Another list: " << *(ptr + i) << " ";

    cout << "\n\nDYNAMIC MEMORY\n\n";

    double *newptr = nullptr;
    newptr = new double[MAX];

    for (int i = 0; i < MAX; i++)
        newptr[i] = i + 1;

    cout << "List: "; 
    for (int i = 0; i < MAX; i++)
        cout << newptr[i] << " ";

    // passing the tests to a function now
    cout << "\nTESTING SUM FUNCTION\n";
    sumArray(newptr);

    delete newptr;
}

void sumArray(double array[])
{
    double sum = 0;
    for (int i = 0; i < MAX; i++)
        sum = *(array + i) + sum;
    cout << "Sum of all values: " << sum;
}
    