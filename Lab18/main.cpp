// Anthony Huey - 10/4/2026 - COMSC 210 - Lab 18: Movies reviews
// Class that holds a title, and a linked list of structs with rating and review
// also get the reviews from input file. no user input.

#include <iostream>
#include <string>
#include <array>

using namespace std;
 
class Movies
{
private: // Title / linked list struct, with rating and reviews
    string title;
    struct Review
    {
        string review;
        int rating;
        Review *next;
    };
public:

};

const int MAX = 4;

int main()
{



}
