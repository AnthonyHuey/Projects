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
const int LEAVE = 46, JOIN = 39, SHIFT = 15;

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
        for (int i = 0; i < MAX; i++)
        {
            int roll = rand() % R_MAX; 
            if (roll < 50) // LEAVE
            {
                if (booth[i].empty())
                    cout << "Lane empty." << endl;
                else
                {
                    cout << "Lane: " << i + 1 << " Paid: ";
                    booth[i].front().print(); 
                    booth[i].pop_front();
                }
            }
            else // JOIN
            {
                    booth[i].push_back(Car());
                    cout << "Lane: " << i + 1 << " Joined: ";
                    booth[i].front().print(); 
            }
            /*
            else // SHIFT if (roll < 85)
            {
               cout << "Lane: " << i + 1 << " Switched: ";
               booth[i].back() 

            }
            */
        }
           
            for (int i = 0; i < MAX; i++)
            {
                cout << "Lane " << i + 1 << ":" << endl;
                for (int n = 0; n < booth[i].size(); n++) // Cars
                {
                    cout << "\t";
                    booth[i][n].print();
                }
            }
            time++; 
    }

  



/*
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
*/   
}