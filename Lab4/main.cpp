// Anthony Huey - 9/4/2026 - Vector of structs
// Struct stores RGB values. 
// Use said struct in a vector and fill with random values.
// Output neatly to console.

#include <iostream>
#include <iomanip>
#include <vector> 

using namespace std;

struct Color
{
   int r;
   int g;
   int b;
};

// used for the random #'s
const int MAX = 50;
const int MIN = 25;
const int CMAX = 255;
const int CMIN = 1;

int main()
{
    // create a struct vector.
    vector<Color> list = { {75,50,25} , {1,2,3} };
    cout << "\n----------PRE SWAP--------------\n";
    for (const auto& a : list)
        cout << a.r << " " << a.g << " " << a.b << " \n";
    
    // Generate a # between 25 - 50
    srand(time(0));
    int n = (rand() % (MAX-MIN+1) + MIN);
    cout << "\nLIST SIZE: " << n;

    // fill temp struct with n random data
    vector<Color> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({rand() % (CMAX-CMIN+1) + CMIN, 
                        rand() % (CMAX-CMIN+1) + CMIN,
                        rand() % (CMAX-CMIN+1) + CMIN});
    }
    // copy the structs data over
    list.swap(temp);
    cout << "\n----------POST SWAP--------------\n";
    for (const auto& a : list)
        cout << a.r << " " << a.g << " " << a.b << " \n";

    // output  
    cout << "\n\n" << "Color #\tR Value\tG Value\tB Value\n";
    cout << "-------\t-------\t-------\t-------\n";
    int num = 1;
    for (const auto& f : list)
    { 
        cout << right
             << setw(4) << num << "\t" 
             << setw(5) << f.r << "\t" 
             << setw(5) << f.g << "\t" 
             << setw(5) << f.b << "\n";
        num++;
    }
}


