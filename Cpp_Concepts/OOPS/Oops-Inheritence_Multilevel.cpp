// 3)Multilevel Inheritance:
/*
    Vehicle 
       |
      Bus
       | 
      Cars       
      
Base Class: Vehicle
Intermediate Class: Bus
Derived Class: Car
Description: In multilevel inheritance, the Bus class serves as an intermediate class between the Vehicle class and the Car class. 
The Car class inherits attributes and behaviors from both the Vehicle and Bus classes.
*/
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

// Base class
class Vehicle
{
public:
    // Public member variables
    string_view m_vehicle_type;
    string_view m_vehicle_color;
    int m_vehicle_capacity;

protected:
    // Protected member variable
    int m_vehicle_year;

public:
    // Constructor using string_view
    Vehicle(string_view vehicle_type, string_view vehicle_color, int vehicle_capacity, int vehicle_year)
        : m_vehicle_type(vehicle_type),
          m_vehicle_color(vehicle_color),
          m_vehicle_capacity(vehicle_capacity),
          m_vehicle_year(vehicle_year)
    {}

    // Function to display vehicle store information
    void vehicle_store_info()
    {
        cout << "Welcome to Vehicle Store" << endl;
    }

    // Destructor
    ~Vehicle() {}
};

// Bus class inheriting from Vehicle
class Bus : public Vehicle
{
public:
    // Constructor using string_view
    Bus(string_view vehicle_type, string_view vehicle_color, int vehicle_capacity, int vehicle_year)
        : Vehicle(vehicle_type, vehicle_color, vehicle_capacity, vehicle_year) // Call base class constructor
    {}

    // Function to display bus information
    void bus_info()
    {
        // Accessing member variables from Vehicle class
        cout << "bus_type: " << m_vehicle_type << endl
             << "bus_color: " << m_vehicle_color << endl
             << "bus_capacity: " << m_vehicle_capacity << endl
             << "bus_year: " << m_vehicle_year << endl;
    }
};

// Car class inheriting from Bus
class Car : public Bus
{
public:
    // Additional member variable for Car class
    int m_bus_capacity;

public:
    // Constructor using string_view
    Car(string_view vehicle_type, string_view vehicle_color, int vehicle_capacity, int vehicle_year, int bus_capacity)
        : Bus(vehicle_type, vehicle_color, vehicle_capacity, vehicle_year), // Call Bus class constructor
          m_bus_capacity(bus_capacity) // Initialize m_bus_capacity
    {}

    // Function to display car information
    void car_info()
    {
        // Accessing member variables from Vehicle class
        cout << "car_type: " << m_vehicle_type << endl
             << "car_color: " << m_vehicle_color << endl
             << "car_capacity: " << m_vehicle_capacity << endl
             << "car_year: " << m_vehicle_year << endl;

        // Accessing member variables from Bus class
        cout << "bus_capacity: " << m_bus_capacity << endl;
    }
};

int main()
{   
    // Creating an object of the Bus class
    Bus bus("large_bus", "black", 50, 2024);

    cout << "-------------------------" << endl;
    // Displaying vehicle store information
    bus.vehicle_store_info();
    cout << "-------------------------" << endl;

    cout << "Bus information:" << endl;
    // Displaying bus information
    bus.bus_info();

    cout << "-------------------------" << endl;
    
    // Creating an object of the Car class
    Car car("sedan", "blue", 5, 2024, 50); 
    cout << "Car information:" << endl;
    // Displaying car information
    car.car_info();

    return 0;
}
