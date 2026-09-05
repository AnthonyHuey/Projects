// Anthony Huey - 9/4/2026 - Vector of structs
// Struct stores RGB values. 
// Use said struct in a vector and fill with random values.
// Output neatly to console.

#include <iostream>
#include <vector> 

using namespace std;

struct Color
{
   int r;
   int g;
   int b;
};

int main()
{
    Color test{25, 50, 75};
    cout << test.r << " " << test.g << " " << test.b << "\n\n";

    // create a struct vector.
    vector<Color> list = { {75,50,25} , {1,2,3} };
    for (const auto& a : list)
    {
        cout << a.r << " " << a.g << " " << a.b;
    }
    // fill it with random data

    // output

}


