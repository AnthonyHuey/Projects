// Anthony Huey - 9/26/2026 - COMSC 210 - Lab15: Movie Class
// Movie class, screen writer / yaer released / title
// same set/get adn print member funcs
// gets data from input file, Title - Year - Name
// put that data into an object then into the class

#include <iostream>
#include <array>
#include <fstream>
#include <string>

using namespace std;

// class for movie data
class Movie
{
private:
    string title;
    int year;
    string name;
public:
    void setTitle(string t) {};
    void setYear(int y) {};
    void setName(string n) {};

    string getTitle() const {};
    int getYear() const {};
    string getName() const {};

    void print() const {};

};
struct Input
{
    string title;
    int year;
    string name;
};

int main()
{




}