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
// Hold the input from the file.
struct Input
{
    string title;
    int year;
    string name;
};

int main()
{
    array<Input,4> input;

    cout << "Reading data from file";
    ifstream fin;
    fin.open ("input.txt");
    if (fin.good())
    {
        for (int i = 0; i < input.size(); i ++)
        {   
           fin >> input[i].title;
           fin >> input[i].year;
           fin >> input[i].name;
        }
        fin.close();
    }
    else 
        cout << "\nFile not found.\n";

    for (int i = 0; i <input.size(); i++)
    {
        cout << "\nTitle: " << input[i].title;
        cout << "\nYear: " << input[i].year;
        cout << "\nName: " << input[i].name;
    }



}