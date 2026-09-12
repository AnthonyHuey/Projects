// Anthony Huey - 9/12/2026 - Arrays & Functions 1
// Use functions to manipulate dynamically allocated arrays

#include <iostream>

using namespace std;

// Fill Array with data
//enterArrayData();

// Output the arrays data on a single line
//outputArrayData();

// Add all the values of the array up and output the sum
//void sumArray();

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
    {
        cout << "List: " << ptr[i] << " ";
    }
       for (int i = 0; i < MAX; i++)
    {
       cout <<"\n Another list: " << *(ptr + i) << " ";
    }

    }
 


/*
void sumArray()
{
    double sum;
    
    cout << "Sum of all values: " << sum;
}
    */