// Oops - Multiple File Access
// Main File (where the program execution starts.)
// It includes necessary headers, such as iostream and the class_declaration.h file.
// It creates an instance of the Cylinder class, calculates its volume, and prints the result.


#include <iostream>
// #include "constant.h"
#include "class_declaration.h"

int main(){
    // Create an instance of the Cylinder class with specified parameters.
    Cylinder cylinder1(10,10);

    // Calculate and print the volume of the Cylinder.
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    std::cout<<"--Done--"<<std::endl;
    return 0;
}


