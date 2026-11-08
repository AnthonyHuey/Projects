// Anthony Huey - 10/5/2026 - COSMC 210 - Lab 32: Toll Booth
// Add multiple lane to the toll booth
// Add a chance for cars to switch lanes
// 46% a car leaves / 39% a car joins / 15% a car shifts
// if a lnae is empty, 50/50 a car joins

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
    int time = 1;
    while (booth.size() != 0)
    {   
        int roll = (rand() % R_MAX);
        if (roll < 45)
        {
            cout << "\nTime: " << time << " Operation: ";
            booth.push_back(Car());
            cout << "Joined lane: "; 
            booth.back().print();
        }
        else
        {
            cout << "\nTime: " << time << " Operation: ";
            cout << "Car paid: "; 
            booth.front().print();
            booth.pop_front();
        }
        
        for (int i = 0; i < booth.size(); i++)
        {   
            cout << "\t";
            booth[i].print();
        }
        time++;
        if (booth.empty())
            cout << "Queue:\n     Empty";
    }
}