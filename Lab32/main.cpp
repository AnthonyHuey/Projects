// Anthony Huey - 10/5/2026 - COSMC 210 - Lab 32: Toll Booth
// Use Car.h, to create a "toll booth",
// Use a structure of Car's in a deque, 
// start with 2 cars, 55% one leaves , 45% one arrives

#include "Car.h"
#include <deque>
#include <iostream>
const int INITIAL = 2, R_MAX = 100;

int main()
{
    srand(time(0));
    deque<Car> booth(INITIAL);

    cout << "Initial queue: " << endl;
    cout << "\t";
    booth[0].print();
    cout << "\t";
    booth[1].print();
    while (booth.size() != 0)
    {
        int roll = (rand() % R_MAX);
        if (roll < 45)
            booth.push_back(Car());
        else
            booth.pop_front();
        
        for (int i = 0; i < booth.size(); i++)
        {   
            cout <<  "Time: " << i + 1; 
            booth[i].print();
        }
    }
}