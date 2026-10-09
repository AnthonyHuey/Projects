// Anthony Huey - 10/9/2026 - COMSC 210 - Lab 20: Chair Maker 3000
// Amend the given code to:
// By defualt randomly selte 3 or 4 legs and price between $100.00 - $999.99
// Modify the paramater constructor to include the prices

#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 3;
const int MIN = 10000;
const int MAX = 99999;

class Chair 
{
    private:
        int legs;
        double * prices;
    public:
    // constructors
    Chair() // defualt
    {
        prices = new double[SIZE];
        if (rand() % 2 == 0)
            legs = 3;
        else
            legs = 4;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN+1) + MIN) / 100.00;
    }
    Chair(int l, double p[]) // paramater
    {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }
    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }
    void setPrices(double p1, double p2, double p3)
    {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }
    double getAveragePrices()
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    void print() 
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};
int main() 
{
    srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with constructor
    double p[SIZE] = {425.25, 534.34, 752.52};
    Chair *livingChair = new Chair(4, p);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;
    
    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    /* Use defualt constructors instead.
    collection[0].setLegs();
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    */

    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    return 0;
}