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
    void addReview(Review&, string, double); 
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

void Movie::addReview(Review& head, string c, double r)
{
    Review *temp = new Review;
    temp->comment = c;
    temp->rating = r;
    temp->next = nullptr;

    
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
    title = rhs.title;

    Review *current = rhs.head;
    Review *tail = nullptr;
    while (current != nullptr)
        {
            Review *temp = new Review;
            temp->comment = current->comment;
            temp->rating = current->rating;
            temp->next = nullptr;
            //
            if (tail != nullptr)
                tail->next = temp;
            else
                head = temp;
            tail = temp;
            current = current->next;
        }
    
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

        // okay it took awhile for me to get this so im gonna comment everything
        Review *current = rhs.head;// track which "node" where gonna copy over
        Review *tail = nullptr;    // keeps track of the end, to link everything
        while (current != nullptr) // walks to the end of the list
        {
            Review *temp = new Review;  // new object to hold the copy data
            temp->comment = current->comment;   // copy over comment
            temp->rating = current->rating;     // copy over rating
            temp->next = nullptr;               // set the next to null 
                                                // in case this is the end  
            if (tail != nullptr)    // check if this is the head or not
                tail->next = temp;  // smove tail to correct position
            else
                head = temp;        // set the head
            tail = temp;            // move tail lto correct position.
        }
    
    }
    return *this;
}
