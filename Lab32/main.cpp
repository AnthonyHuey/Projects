// Anthony Huey - 10/5/2026 - COSMC 210 - Lab 32: Toll Booth
// Use Car.h, to create a "toll booth",
// Use a structure of Car's in a deque, 
// start with 2 cars, 55% one leaves , 45% one arrives

#include "Car.h"
#include <deque>

int main()
{
    deque<Car> booth {{},{}};
    booth.push_front(Car());
    booth.push_front(Car());
    booth[0].print();
}