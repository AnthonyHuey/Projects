// Anthony Huey - 9/20/2026 - COMSC 210 - Pointers 2, Dynamic array of structs.
// Initial idea is a car rental service for the struct 
//      First/Last name, 
//      VIN of the car rented?
//      How many days to rent?
// need to think about what the dynamic array in the struct will be

#include <array>
#include <iostream>

using namespace std;

const int MAX = 2;

struct Customer 
{
   string fName; 
   string lName;

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
    cout << "\n";

    // build the array
    array<Customer, MAX> *ptr = nullptr;
    ptr = new array<Customer, MAX>;

    for (int i = 0; i < c; i++)
    //


}