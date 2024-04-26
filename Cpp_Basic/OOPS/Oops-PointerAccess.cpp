#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
private:
    double base_radius{1};
    double height{1};

public:
    Cylinder() = default;
    Cylinder(double rad_param, double height_param);

    double volume();
    double get_base_radius();
};

// Outside class access
Cylinder::Cylinder(double rad_param, double height_param) {
    base_radius = rad_param;
    height = height_param;
}

double Cylinder::volume() {
    return PI * base_radius * base_radius * height;
}

double Cylinder::get_base_radius() {
    return base_radius;
}

int main() {
    // Creating a Cylinder object on the stack with specified parameters.
    Cylinder cylinder1(10, 10);

    std::cout << "Volume(cylinder1): " << cylinder1.volume() << std::endl;

    // Managing a 'stack' object through pointers.
    Cylinder* p_cylinder1 = &cylinder1;

    // Accessing the volume through the pointer to the Cylinder object.
    std::cout << "Volume(cylinder1 via pointer): " << p_cylinder1->volume() << std::endl;

    // Creating a Cylinder object on the 'heap' using the new operator. (Dynamically allocating memory)
    Cylinder* p_cylinder2 = new Cylinder(100, 2);

    // Accessing and printing the volume and base radius of cylinder2.
    // std::cout << "Volume(cylinder2): " << (*p_cylinder2).volume() << std::endl;    //ugly syntax
    std::cout << "Volume(cylinder2): " << p_cylinder2->volume() << std::endl;         // better syntax
    std::cout << "Base Radius(cylinder2): " << p_cylinder2->get_base_radius() << std::endl;

    // Deallocating memory for the heap-allocated cylinder2 object.
    delete p_cylinder2;

    return 0;
}
