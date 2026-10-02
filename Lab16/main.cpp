// Anthony Huey - 10/2/2026 - COMSC 210 - Lab 16: Class Constructors
// Modify lab14 with default/parameter/partial constructors

#include <iostream>

using namespace std;

class Color
{
private:
    int red;
    int green;
    int blue;
public:
// constructors go here
    Color() {red = 0, green = 0, blue = 0;}                     // Default
    Color(int b) {red = 0, green = 0, blue = b;}            // Partial/Sets blue
    Color(int r, int g) {red = r, green = g, blue = 0;}     // Partial/Sets R&G
    Color(int r, int g, int b) {red = r, green = g, blue = b;}  // Parameter

    void setRed(int r) {red = r;}
    void setGreen(int g) {green = g;}
    void setBlue(int b) {blue = b;}

    int getRed() const {return red;}
    int getGreen() const {return green;}
    int getBlue() const {return blue;}

    void print() const {cout << "\nRed: " << red << "\nGreen: " << green 
                            << "\nBlue: " << blue;} 
};

int main()
{
    Color defaultColor;
    Color partial {145, 50};
    Color partialColor {10};
    Color parameter {250, 75, 90};

    cout << "\n\n---Default: ";
    defaultColor.print();

    cout << "\n\n---Partial: ";
    partial.print();

    cout << "\n\n---The other Partial: ";
    partialColor.print();

    cout << "\n\n---Parameter: ";
    parameter.print();

    srand(time(0));
    Color random {rand(),rand(),rand()};
    cout << "\n\n---Random: ";
    random.print();

}