// Anthony Huey - 9/26/2026 - COMSC 210 - Lab14: Color Class
// Create a Color class that has 3 private RGB values
// Setter/Getter and print() member functions
// Make a few in main, test them out.

#include <iostream>

using namespace std;

class Color
{
private:
    int red;
    int green;
    int blue;
public:
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
    test.print();
    test.setBlue(test.getGreen());
    test.print();

    Color pink;
    pink.setRed(255);
    pink.setGreen(192);
    pink.setBlue(203);
    pink.print();
    test.setRed(pink.getBlue());
    test.print();

}