// Anthony Huey - 9/3/2026 - Lab3 Resaurant Structs
//create a struct, fill it with user data, output to console

#include <iostream>
#include <string>

using namespace std;

// Struct Template
struct Restaurant
{
    string name;
    int chairs;
    int tables;
    bool open;
};
// Function for filling struct with user data
Restaurant uInput();
// Function for outputting struct to console
void output(const Restaurant&);

int main()
{

   // Make the struct,
   Restaurant test = uInput();
   // Output the struct.

}
Restaurant uInput()
{

}
void output(const Restaurant&)
{

}