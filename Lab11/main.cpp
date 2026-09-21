// Anthony Huey - 9/20/2026 - COMSC 210 - Pointers 2, Dynamic array of structs.
// Initial idea is a car rental service for the struct 
//      Name,
//      # of cars rented 
//      VIN of the car rented?
//  I know VIN aren't just numbers but were keeping it simple.

#include <iostream>
#include <string>

using namespace std;

struct Customer 
{
   string name; 
   int count; // How many cars rented
   int *vin; //  VIN of the cars rented. 
   
};

int main()
{
    //ok, get the amount of customers.
    int c = 0;
    cout << "How many customers are renting today: ";
    cin >> c;
    cin.ignore();
  
    // build the array
    Customer *customers = new Customer[c]; 

    // Get the customer name, how many cars.
    for (int i = 0; i < c; i++)
    {
        cout << "\nCustomer #" << (i+1) << "'s name: ";
        getline(cin, customers[i].name);

        cout << "How many cars did they rent: ";
        cin >> customers[i].count;
        cin.ignore();

        // create the struct array based on how many cars rented, then fill it.
        customers[i].vin = new int[customers[i].count];

        for (int n = 0; n < customers[i].count; n++)
        {
            cout << " VIN of car #" << (n + 1) << ": ";
            cin >> customers[i].vin[n];
            cin.ignore();
        }
    }
    // Output to check work.
    for (int i = 0; i < c; i++)
    {
        cout << "\n" << customers[i].name << " rented " << customers[i].count
             << " car(s)." << "\nCar(s) VIN is: ";
        for (int n = 0; n < customers[i].count; n++)
            cout << "\n#" << customers[i].vin[n];
    }

    // Deleting the memnory
    for (int i = 0; i < c; i++)
        delete[] customers[i].vin;
    delete[] customers;
}