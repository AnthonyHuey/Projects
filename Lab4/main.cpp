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
    cout << "\n LIST SIZE: " << n;

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
    
    cout << "\n\n" << "Color#\tR Value\tG Value\tB Value\n";
    for (const auto& f : list)
    { 
        int i = 1;
        cout << i << "\t" << f.r << "\t" << f.g << "\t" << f.b << "\n";
        i++;
    }


    /*never used rand so doing some tests/learning
    vector<int> learn;
    const int MIN = 25;
    const int MAX = 50;

    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        learn.push_back(rand() % (MAX-MIN+1) + MIN);
    }
    for (int val : learn) cout << val << " ";
    */
}


