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
    void setTitle(string t) {title = t;};
    void setYear(int y) {year = y;};
    void setName(string n) {name = n;};

    string getTitle() const {return title;};
    int getYear() const {return  year;};
    string getName() const {return name;};

    void print() const {cout << "\nMovie: " << title 
                            << "\n\tYear released: " << year
                            << "\n\tScreenwriter: " << name;};

};
// Hold the input from the file.
struct Input
{
    string title;
    int year;
    string name;
};

const int MAX = 4;

int main()
{
    array<Input, MAX> input;
    array<Movie, MAX> movies;

    cout << "Reading data from file...\n";
    ifstream fin;
    fin.open ("input.txt");
    if (fin.good())
    {
        for (int i = 0; i < input.size(); i ++)
        {   
          getline(fin, input[i].title);
          fin >> input[i].year;
          fin.ignore();
          getline(fin, input[i].name);
        }
        fin.close();
    }
    else 
        cout << "\nFile not found.\n";

    // put all the input data into the class.
    for (int i = 0; i < input.size(); i++)
    {
        movies[i].setTitle(input[i].title);
        movies[i].setYear(input[i].year);
        movies[i].setName(input[i].name);
    }
    // output from array
    //cout << "\nFROM ARRAY";
    for (int i = 0; i <input.size(); i++)
    {
        cout << "\nMovie: " << input[i].title;
        cout << "\n\tYear released: " << input[i].year;
        cout << "\n\tScreenwriter: " << input[i].name;
    }

    // output from class
    //cout << "\n\nFROM CLASS";
    //for (int i = 0; i <movies.size(); i++)
    //    {
    //       movies[i].print();
    //    }



}