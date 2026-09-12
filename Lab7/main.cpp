// Anthony Huey - 9/12/2026 - Lab 7: Dynamic Arrays & Functions 2
// create a dynamic string array, call functions to reverse and output.
// POINTER NOTATION, surely it's not much harder than doubles right.

#include <iostream>
#include <string>

using namespace std;

// Reverses the elements of the array
string* reverseArray(string[]); 

// Output array.
void displayArray(string[]);

const int MAX = 5;

int main()
{
   // Create/populate the array
   string *names = nullptr;
   names = new string[MAX]{"Janet","Jeffe","Jin","Joe","Junio"}; 

   cout << "Original array: ";
   for (int i = 0; i < MAX; i++)
        cout << *(names + i) << " ";
    cout << "\n";

   // Reverse it
   names = reverseArray(names);

   // Output it
   displayArray(names);

   delete [] names;
}

string* reverseArray(string array[])
{
    string temp;
    for (int i = 0; i < MAX / 2; i++)
    {
        temp = *(array + i);
        *(array + i) = *(array + (MAX - 1 - i));
        *(array + (MAX - 1 - i)) = temp;
    }
    return array;
}

void displayArray(string array[])
{
    cout << "Reversed array: ";
    for (int i = 0; i < MAX; i++)
        cout << *(array + i) << " ";
}