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
        string comment;
        int rating;
        Review *next;
    };
public:

// AddReview

// Average?

// Output

// Destructor

// Copy Constructor

// Copy assignment

};

const int MAX = 4;

int main()
{
    // create the Movies object/container/array


    // Fill it with data from input.txt
    // ratings are a random double from 1.0-5.0

    // output said data


}
