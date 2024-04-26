// 4)Hierarchical Inheritance: 
/*
     vehicle
     ___|___
    Bus    Cars
    
Base Class: Vehicle
Derived Classes: Car, Bus
Description: In hierarchical inheritance, both the Car and Bus classes inherit directly from the Vehicle class. 
Each derived class represents a distinct type of vehicle but shares common attributes and behaviors defined in the Vehicle class.
*/

#include <iostream>
#include <string>
#include <string_view>
using namespace std;

// Base class
class vehicle
{
public:
    // Public member variables
    string_view m_car_type;
    string_view m_car_color;
    int m_car_capacity;

protected:
    // Protected member variable
    int m_car_year;

private:
    // Private member variable
    string_view m_car_owner;

public:
    // Constructor using string_view
    vehicle(string_view car_type, string_view car_color, int car_capacity, int car_year, string_view car_owner)
        : m_car_type(car_type),
          m_car_color(car_color),
          m_car_capacity(car_capacity),
          m_car_year(car_year),
          m_car_owner(car_owner)
    {}

    // Function to display vehicle store information
    void vehicle_store_info()
    {
        cout << "Welcome to Vehicle Store" << endl;
    }

    // Destructor
    ~vehicle() {}
};

// Car class inheriting from vehicle
class Car : public vehicle
{
public:
    // Constructor using string_view
    Car(string_view car_type, string_view car_color, int car_capacity, int car_year, string_view car_owner)
        : vehicle(car_type, car_color, car_capacity, car_year, car_owner) // Call base class constructor
    {}

    // Function to display car information
    void car_info()
    {
        cout << "car_type: " << m_car_type << endl // Accessing member variables from vehicle class
             << "car_color: " << m_car_color << endl
             << "car_capacity: " << m_car_capacity << endl
             << "car_year: " << m_car_year << endl;
            //  << "car_owner: " << m_car_owner << endl; // Accessing private member variable from the base class
    }
};

// Bus class privately inheriting from vehicle
class Bus : private vehicle // Error: Change to private inheritance
{
public:
    // Constructor using string_view
    Bus(string_view car_type, string_view car_color, int car_capacity, int car_year, string_view car_owner)
        : vehicle(car_type, car_color, car_capacity, car_year, car_owner) // Call base class constructor
    {}

    // Function to display bus information
    void bus_info()
    {
        cout << "bus_type: " << m_car_type << endl // Accessing member variables from vehicle class
             << "bus_color: " << m_car_color << endl
             << "bus_capacity: " << m_car_capacity << endl
             << "bus_year: " << m_car_year << endl;
            //  << "bus_owner: " << m_car_owner << endl; // Accessing private member variable from the base class
    }

    // Make vehicle_store_info function accessible from derived class
    using vehicle::vehicle_store_info;
};

int main()
{
    // Creating an object of the Car class
    Car car("sedan", "blue", 5, 2023, "car_owner");

    // Displaying vehicle store information
    car.vehicle_store_info();
    cout << "-------------------------" << endl;
    cout << "Car information" << endl;
    // Displaying car information
    car.car_info();

    cout << "-------------------------" << endl;
    // Creating an object of the Bus class
    Bus bus("large_bus", "black", 50, 2024, "bus_owner");

    // Displaying vehicle store information
    bus.vehicle_store_info();
    cout << "-------------------------" << endl;
    cout << "Bus information" << endl;
    // Displaying bus information
    bus.bus_info();

    return 0;
}
