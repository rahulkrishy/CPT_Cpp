// Setters and Getters - Method to read or modify member variables in the class

#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {
  private : 
    //Member variables
    double base_radius{1};
    double height{1};
  
  public : 
    //Constctors
    Cylinder() = default;
    Cylinder(double rad_param,double height_param){
        base_radius = rad_param;
        height = height_param;
    }

    //Functions (methods)
    double volume(){
        return PI * base_radius * base_radius * height;
    }
        
    //getter method
    double get_base_radius(){
        return base_radius;
    }
    double get_height(){
        return height;
    }

    // Setters method
    void set_base_radius(double rad_param){
        base_radius = rad_param;
    }

    void set_height(double height_param){
        height = height_param;
    }
    
};



int main(){
    Cylinder cylinder1(10,10);
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    //Reading by getters Method
    std::cout << "get_base_radius: "<< cylinder1.get_base_radius()<< std::endl;
    std::cout << "get_height: "<< cylinder1.get_height()<< std::endl;

    //Modifing by setters Method
    cylinder1.set_base_radius(100);
    cylinder1.set_height(10);

    std::cout << "volume : " << cylinder1.volume() << std::endl;


    return 0;
}