// Custom type conversion
// Custom Copy Assignment Operator
/*
A custom copy assignment operator in C++ provides more control and flexibility over the default copy assignment behavior. 
The advantages of using a custom copy assignment operator include:
Deep Copying: If your class contains dynamic memory or resources, a custom copy assignment operator allows you to perform a deep copy, ensuring that the copied object has its own copy of the resources rather than just copying pointers.
Selective Copying: You can selectively copy certain members or perform additional operations during the assignment, depending on the specific requirements of your class.
Handling Self-Assignment: The custom operator allows you to handle self-assignment scenarios gracefully, preventing issues that might arise when an object is assigned to itself.
Resource Management: If your class involves resource management (e.g., file handles, network connections), a custom copy assignment operator allows you to manage those resources appropriately during the assignment process.
*/

#include <iostream>
#include "point.h"

int main(){

    
    Point p1(10,10,10);
    Point p2(20,20,20);
    Point p77(3,3,3);

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    std::cout << "-----" << std::endl;

    //Assignment
    //p1 = p2 = p77;
    //p1.operator=(p2).operator=(p77);
    p1.operator=(p2.operator=(p77));

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    //Change data
    p1.set_data(55);

    std::cout << "-----------" << std::endl;
    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;
   

   //
   /*
   Point p3(30,30,30);
   Point p4 = p3;

   std::cout << "p3 : " << p3 << std::endl;
   std::cout << "p4 : " << p4 << std::endl;

   p3.set_data(77);

   std::cout << "-----" << std::endl;
   std::cout << "p3 : " << p3 << std::endl;
   std::cout << "p4 : " << p4 << std::endl;


   std::cout << "Done!" << std::endl;
   */

    
    return 0;
}