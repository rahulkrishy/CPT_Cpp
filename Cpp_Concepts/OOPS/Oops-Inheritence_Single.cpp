// Inheritence
/*
Inheritance is a fundamental concept in object-oriented programming (OOP) 
where a new class (derived or child class) is created from an existing class (base or parent class), 
inheriting its properties and behaviors. The derived class can then extend or modify the functionality of the base class, providing code reusability and organization.

Inheritance in object-oriented programming can be categorized into different types based on how classes inherit properties and behaviors from each other. 
The main types of inheritance include:

1)Single Inheritance: 
        A 
        |
        B
In single inheritance, a derived class inherits properties and behaviors from a single base class. 
This is the simplest form of inheritance and is commonly used in most object-oriented programming languages like C++, Java, and Python.

2)Multiple Inheritance: 
        A   B
        |___|
          |
          C

Multiple inheritance allows a derived class to inherit properties and behaviors from multiple base classes. 
This means that a derived class can have more than one parent class. While powerful, multiple inheritance can lead to complexities such as the diamond problem, where ambiguity arises due to conflicting methods or attributes from different parent classes.

3)Multilevel Inheritance:
        A 
        |
        B
        | 
        C       
In multilevel inheritance, a derived class inherits properties and behaviors from another derived class, creating a hierarchical chain of inheritance. 
This means that a class can serve as both a base class and a derived class in a multilevel inheritance hierarchy.

4)Hierarchical Inheritance: 
         A
       __|__
      B     C
Hierarchical inheritance involves a single base class with multiple derived classes. 
Each derived class inherits properties and behaviors from the same base class, forming a hierarchical relationship among classes.

5)Hybrid Inheritance: 
        A 
        |   
        B___C
          |
          E
Hybrid inheritance combines different types of inheritance, such as single, multiple, multilevel, or hierarchical inheritance, to create complex class relationships. 
It allows developers to leverage the benefits of multiple inheritance while managing its complexities.

*/
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 1) Single Inheritance
/*
    Vehicle
       |
      Cars
      
Base Class: Vehicle
Derived Class: Car
Description: In single inheritance, the Car class inherits attributes and behaviors from the Vehicle class. 
It adds specific characteristics related to cars while retaining the general properties defined in the Vehicle class.
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
    string_view m_vehicle_type;
    string_view m_vehicle_color;
    int m_vehicle_seat;

protected:
    // Protected member variable
    int m_vehicle_year;

private:
    // Private member variable
    string_view m_vehicle_owner;

public:
    // Constructor using string_view
    vehicle(string_view vehicle_type, string_view vehicle_color, int vehicle_seat, int vehicle_year, string_view vehicle_owner)
        : m_vehicle_type(vehicle_type),
          m_vehicle_color(vehicle_color),
          m_vehicle_seat(vehicle_seat),
          m_vehicle_year(vehicle_year),
          m_vehicle_owner(vehicle_owner)
    {}

    // Function to display vehicle store information
    void vehicle_store_info()
    {
      cout << "Welcome to Vehicle Store" << endl;
    }

    // Destructor
    ~vehicle() {}
};

// Derived class
class Cars : public vehicle
{
public:
    // Constructor for Cars class
    Cars(string_view vehicle_type, string_view vehicle_color, int vehicle_seat, int vehicle_year, string_view vehicle_owner)
        : vehicle(vehicle_type, vehicle_color, vehicle_seat, vehicle_year, vehicle_owner) // Call base class constructor
    {}

    // Function to display car information
    void cars_info()
    {
        cout << "vehicle_type: " << m_vehicle_type << endl // Accessing base class member variables
             << "vehicle_color: " << m_vehicle_color << endl
             << "vehicle_seat: " << m_vehicle_seat << endl
             << "vehicle_year: " << m_vehicle_year << endl;
            //  << "vehicle_owner " << m_vehicle_owner << endl; // m_vehicle_owner is private in base class, so it's not accessible here
    }
};

int main()
{
    // Creating an object of the derived class Cars
    Cars car1("car", "black", 4, 2024, "krishy");

    // Displaying vehicle store information
    car1.vehicle_store_info();
    cout << "-------------------------" << endl;
    // Displaying car information for car1
    car1.cars_info();

    cout << "-------------------------" << endl;

    // Creating a second object of the derived class Cars
    Cars car2("car", "blue", 6, 2024, "rahul");

    // Displaying car information for car2
    car2.cars_info();

    return 0;
}
