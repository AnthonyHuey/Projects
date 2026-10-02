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
    Color(int r) {red = r;}                                     // Partial
    Color(int r, int g) {red = r, green = g;}                   // Partial
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
    Color test;
    test.setRed(255);
    test.setGreen(150);
    test.setBlue(25);
    cout << "\n-TEST-";
    test.print();

    test.setBlue(test.getGreen()); // Swaping test B with it's green value
    test.setGreen(15);
    cout << "\n-TEST-";
    test.print();

    Color pink;
    pink.setRed(255);
    pink.setGreen(192);
    pink.setBlue(203);
    cout << "\n-PINK-";
    pink.print();

    test.setRed(pink.getBlue()); // Swapping test R with pink's blue value
    cout << "\n-TEST-";
    test.print();
}