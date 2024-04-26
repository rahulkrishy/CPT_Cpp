/*
Member wise copy Initialization: 
- Two steps : (1) object creation + (2) member variable assignment
- Potential unnecessary copies of data
- Order of member variables doesn't matter

Initializer lists Initialization:  
- Initialization happens at real object creation
- Unnecessary copies avoided
- Order of member variables matters

Shallow Copy: 
    Duplicates the object structure but not the internal data;
    changes in one affect the other if involving mutable objects. 
    Shares the same memory location as the original object.

Deep Copy: 
    Creates a completely independent duplicate, including all internal data;
    changes in one do not affect the other. 
    Has a different memory location than the original object.
*/

#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {
private:
    // Member variables
    double base_radius{1};
    double height{1};

public:
    // Constructors

    // Default constructor
    Cylinder() = default;

    // Constructor with a default value for height
    Cylinder(double rad_param, double height_param = 5);

    // Functions (methods)

    // Calculate and return the volume of the cylinder
    double volume(){
        return PI * base_radius * base_radius * height;
    }

    // Accessor method to get the value of base_radius
    double get_base_radius() const {
        return base_radius;
    }

    // Accessor method to get the value of height
    double get_height() const {
        return height;
    }
};

// Memberwise copy initialization (commented out)
/*
Cylinder::Cylinder(double rad_param, double height_param){
    base_radius = rad_param;
    height = height_param;
    std::cout <<"Two param constructor called" << std::endl;
}
*/

// Constructor implementation using initializer list
Cylinder::Cylinder(double rad_param, double height_param) 
    : base_radius(rad_param), height(height_param) 
{
}

int main(){
    // Create a Cylinder object with a specified base radius (5) and default height (5)
    Cylinder c1(5);

    // Print the base radius, height, and volume of the cylinder
    std::cout << "Base Radius: " << c1.get_base_radius() << std::endl;
    std::cout << "Height: " << c1.get_height() << std::endl;
    std::cout << "Volume: " << c1.volume() << std::endl;

    return 0;
}
