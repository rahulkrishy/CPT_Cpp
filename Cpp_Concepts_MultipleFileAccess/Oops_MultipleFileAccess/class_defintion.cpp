// This file provides the implementation details for the methods declared in class_declaration.h.
// ".cpp" is used for source files that contain definitions and implementations.
// It includes the class_declaration.h file to ensure consistency between declaration and definition.

#include "class_declaration.h" 

// 'Constructor' implementation for the Cylinder class.
Cylinder::Cylinder(double rad_param,double height_param){
    base_radius = rad_param;
    height = height_param;
 }

// Method implementation for calculating the volume of the Cylinder.
double Cylinder::volume(){
    return PI * base_radius * base_radius * height;
 }

