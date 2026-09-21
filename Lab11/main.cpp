// Anthony Huey - 9/20/2026 - COMSC 210 - Pointers 2, Dynamic array of structs.
// Initial idea is a car rental service for the struct 
//      First/Last name, 
//      VIN of the car rented?
//      How many days to rent?
// need to think about what the dynamic array in the struct will be

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

    // Get the customer name, how many cars, then create the array for the VINs.
    for (int i = 0; i < c; i++)
    {
        cout << "\nCustomer #" << (i+1) << " name: ";
        getline(cin, customers[i].name);

        cout << "How many cars did they rent?";
        cin >> customers[i].count;
        cin.ignore();

        // create array based on how many cars rented
        for (int n = 0; n < customers[i].count; n++)
        {
            cout << " VIN of car #" << (n + 1) << ": ";
            cin >> customers[i].vin[n];
        }
    }
    
    cout << "\n\nDid it work?\n\n";
    for (int i = 0; i < c; i++)
    {
        cout << customers[i].name << " rented " << customers[i].count
             << " car(s)." << "\nCar(s) VIN is:";
        for (int n = 0; n < customers[i].count; i++)
            cout << "\n#" << customers[i].vin[n];
    }



}