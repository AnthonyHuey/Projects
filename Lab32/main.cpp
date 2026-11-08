// Anthony Huey - 10/5/2026 - COSMC 210 - Lab 32: Toll Booth
// Add multiple lane to the toll booth
// Add a chance for cars to switch lanes
// 46% a car leaves / 39% a car joins / 15% a car shifts
// if a lnae is empty, 50/50 a car joins

#include "Car.h"
#include <deque>
#include <iostream>
#include <array>

const int INITIAL = 2, R_MAX = 100, MAX = 4;
const int LEAVE = 46, JOIN = 85;

int main()
{
    srand(time(0));
    array<deque<Car>, MAX> booth;

    cout << "Initial queue:" << endl;
    for (int i = 0; i < MAX; i++)           // how many booths/lanes
        for (int n = 0; n < INITIAL; n++)   // how many cars
            booth[i].push_back(Car());      // add cars.
    
    for (int i = 0; i < MAX; i++) // Lanes
    {
        cout << "Lane " << i + 1 << ":" << endl;
        for (int n = 0; n < INITIAL; n++) // Cars
        {
            cout << "\t";
            booth[i][n].print();
        } 
    }
    // roll for each lane
        // output results
    // repeat, keep track of time.
    int time = 0;
    while (time < 20)
    {
        cout << "\nTime: " << time + 1 << endl;
        time++;
        for (int i = 0; i < MAX; i++)
        {
            int roll = rand() % R_MAX; 
            if (!booth[i].empty()) // if the queue is not empty
            {
                if (roll < LEAVE) // LEAVE
                {
                    cout << "Lane: " << i + 1 << " Paid: ";
                    booth[i].front().print(); 
                    booth[i].pop_front();
                }
                else if (roll < JOIN) // JOIN
                {
                        booth[i].push_back(Car());
                        cout << "Lane: " << i + 1 << " Joined: ";
                        booth[i].back().print(); 
                }
                else  // SHIFT 
                {   
                    cout << "Lane: " << i + 1 << " Switched: ";
                    booth[i].back().print();
                    int lane = rand() % MAX; // picking a lane
                    while (lane == i) // can't be the lane we're in.
                        lane = rand() % MAX; // pick again
                    booth[lane].push_back(booth[i].back()); // copies car over.
                    booth[i].pop_back(); // delete original
                }
            }
            else if (roll < 50) // if it is empty, 50% to add a new car.
            {
                booth[i].push_back(Car());
                cout << "Lane: " << i + 1 << " Joined: ";
                booth[i].back().print(); 
            }
        }
        for (int i = 0; i < MAX; i++)
        {
            cout << "Lane " << i + 1 << " Queue:" << endl;
            for (int n = 0; n < booth[i].size(); n++) // Cars
            {
                if (booth[i].empty())
                    cout << " empty";
                else
                {
                    cout << "\t";
                    booth[i][n].print();
                }
            }
        }
    }   
}