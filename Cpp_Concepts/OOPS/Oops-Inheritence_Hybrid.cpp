// 5)Hybrid Inheritance: - combination of one or more types of inheritences
/*
    Vehicle
       |   
      Bus
       |
      Cars     Vehicle_Insurance
       |______________|
              |
       Vehicle_Insurance

Base Class: Vehicle - Represents a generic vehicle with basic attributes such as type, color, capacity, and year.
Derived Class 1: Bus - Inherits from Vehicle and adds bus-specific attributes like type, color, capacity, and year. It provides functionality to display bus information.
Derived Class 2: Car - Inherits from Bus and represents a car with attributes inherited from Vehicle and Bus. It adds functionality to display car information.
Seperate Class: Vehicle_Insurance - Inherits from Vehicle and adds an insurance period attribute. It provides functionality to display the insurance period.
Hybrid Class: Vehicle_Price - Inherits from both Car and Vehicle_Insurance, combining attributes and functionality related to both a car and insurance. It represents the price of a vehicle including insurance information.
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
    // Constructor using string_view
    Car(string_view vehicle_type, string_view vehicle_color, int vehicle_capacity, int vehicle_year)
        : Bus(vehicle_type, vehicle_color, vehicle_capacity, vehicle_year) // Call Bus class constructor
    {}

    // Function to display car information
    void car_info() // Changed from bus_info to car_info
    {
        // Accessing member variables from Vehicle class
        cout << "car_type: " << m_vehicle_type << endl
             << "car_color: " << m_vehicle_color << endl
             << "car_capacity: " << m_vehicle_capacity << endl
             << "car_year: " << m_vehicle_year << endl;
    }

    // Destructor
    ~Car() {}
};

// Vehicle_Insurance class inheriting from Vehicle
class Vehicle_Insurance : public Vehicle
{
protected:
    // Protected member variable
    int m_insurance_period;

public:
    // Constructor using string_view
    Vehicle_Insurance(string_view vehicle_type, string_view vehicle_color, int vehicle_capacity, int vehicle_year, int insurance_period)
        : Vehicle(vehicle_type, vehicle_color, vehicle_capacity, vehicle_year), // Call base class constructor
          m_insurance_period(insurance_period)
    {}

    // Function to display insurance period
    void insurance_info()
    {
        // Accessing member variables from Vehicle class
        cout << m_insurance_period << " years" << endl;
    }

    // Destructor
    ~Vehicle_Insurance() {}
};

// Vehicle_Price class inheriting from Car and Vehicle_Insurance
class Vehicle_Price : public Car, public Vehicle_Insurance
{
public:
    // Constructor using string_view
    Vehicle_Price(string_view vehicle_type, string_view vehicle_color, int vehicle_capacity, int vehicle_year, int insurance_period)
        : Car(vehicle_type, vehicle_color, vehicle_capacity, vehicle_year), // Call Car class constructor
          Vehicle_Insurance(vehicle_type, vehicle_color, vehicle_capacity, vehicle_year, insurance_period) // Call Vehicle_Insurance class constructor
    {}

    // Destructor
    ~Vehicle_Price() {}
};

int main()
{    
    // Creating an object of the Bus class
    Bus bus("large_bus", "black", 50, 2024);

    cout << "-------------------------" << endl;
    // Displaying vehicle store information
    bus.vehicle_store_info();
    cout << "-------------------------" << endl;

    // Displaying bus information
    cout << "Bus Information:" << endl;
    bus.bus_info();
    
    // Creating an object of the Vehicle_Price class for the bus
    Vehicle_Price bus_price("large_bus", "black", 50, 2024, 5);
    // Displaying insurance information for the bus
    cout << "Insurance Period for Bus : ";
    bus_price.insurance_info();

    cout << "-------------------------" << endl;
    
    // Creating an object of the Car class
    Car car("sedan", "blue", 5, 2023);
    // Displaying car information
    cout << "Car Information:" << endl;
    car.car_info();
    
    // Creating an object of the Vehicle_Price class for the car
    Vehicle_Price car_price("sedan", "blue", 5, 2023, 3);
    // Displaying insurance information for the car
    cout << "Insurance Period for Car : ";
    car_price.insurance_info();

    return 0;
}
