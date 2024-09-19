// 2)Multiple Inheritance: 
/*
    vehicle   Bus
        |_____|
           |
          Cars
          
Base Class: vehicle - Represents a generic vehicle with basic attributes like type, color, capacity, and year.
Separate Class: Bus - Represents a specific type of vehicle, focusing on attributes related to buses such as type and capacity.
Derived Class: Cars - Inherits from both vehicle and Bus, combining attributes from both classes to represent a car with additional bus-related information.
Description: The Cars class combines characteristics of both a generic vehicle and a bus, providing a comprehensive representation of a car with added bus-specific attributes.
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

// Bus class
class Bus
{
public:
    // Public member variables specific to Bus
    string_view m_bus_type;
    int m_bus_capacity;

public:
    // Constructor using string_view
    Bus(string_view bus_type, int bus_capacity)
        : m_bus_type(bus_type),
          m_bus_capacity(bus_capacity)
    {}

    // Function to display bus information
    void bus_info()
    {
        cout << "bus_type: " << m_bus_type << endl // Accessing member variables
             << "bus_capacity: " << m_bus_capacity << endl;
    }

    // Destructor
    ~Bus() {}
};

// Derived class Cars inheriting from both vehicle and Bus
class Cars : public vehicle, public Bus
{
public:
    // Constructor for Cars class
    Cars(string_view car_type, string_view car_color, int car_capacity, int car_year, string_view car_owner,
         string_view bus_type, int bus_capacity)
        : vehicle(car_type, car_color, car_capacity, car_year, car_owner), // Call base class constructor
          Bus(bus_type, bus_capacity) // Call Bus class constructor
    {}

    // Function to display car information
    void cars_info()
    {
        cout << "car_type: " << m_car_type << endl // Accessing vehicle class member variables
             << "car_color: " << m_car_color << endl
             << "car_capacity: " << m_car_capacity << endl
             << "car_year: " << m_car_year << endl;

        // Displaying bus information using Bus class member variables
        cout << "bus_type: " << m_bus_type << endl
             << "bus_capacity: " << m_bus_capacity << endl;
    }
};

int main()
{
    // Creating an object of the derived class Cars
    Cars car1("mini car", "black", 4, 2024, "krishy", "large_bus", 50);

    // Displaying vehicle store information
    car1.vehicle_store_info();
    cout << "-------------------------" << endl;
    cout << "Vehicle set_1" << endl;
    // Displaying car information for car1
    car1.cars_info();

    cout << "-------------------------" << endl;
    cout << "Vehicle set_2" << endl;

    // Creating a second object of the derived class Cars
    Cars car2("large car", "blue", 6, 2024, "rahul", "mini_bus", 20);

    // Displaying car information for car2
    car2.cars_info();

    return 0;
}
