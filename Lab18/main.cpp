// Anthony Huey - 10/4/2026 - COMSC 210 - Lab 18: Movies reviews
// Class that holds a title, and a linked list of structs with rating and review
// also get the reviews from input file. no user input.

#include <iostream>
#include <string>
#include <array>

using namespace std;
 
class Movie
{
private: // Title / linked list struct, with rating and reviews
    string title;
    struct Review
    {
        string comment;
        double rating;
        Review *next;
    };
    Review *head = nullptr;

public:
    void setTitle(string t) {title = t;} 
    string getTitle() const {return title;} 
    void addReview(); 
    double averageRating();
    void output();

    ~Movie(); // Destructor / It was the ~ i couldn't remember...
    Movie (const Movie &rhs); // Copy Constructor
    Movie& operator=(const Movie&); // Copy assignment
};

const int MAX = 4;

int main()
{
    // create the Movies object/container/array


    // Fill it with data from input.txt
    // ratings are a random double from 1.0-5.0

    // output said data


}

Movie::~Movie() // Deconstructor
{
    while (head != nullptr)
    {
        Review *temp = head;
        head = head->next;
        delete temp;
    }
}

Movie::Movie(const Movie &rhs) // Copy Constructor
{

}

Movie& Movie::operator=(const Movie &rhs) // Copy assignment
{
if (&rhs != this)
{
    while (head) // clear data
    {
        Review *temp = head;
        head = head->next;
        delete temp;
    }

    title = rhs.title; //copy title
    // then copy everything else
    Review *current = rhs.head;
 
}

return *this;
}
