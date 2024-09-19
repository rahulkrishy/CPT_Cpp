// This file declares the class Cylinder.
// Header files(.h) usually contain class declarations, function prototypes, and constants
// It includes the constant.h file for the constant value PI.
// We define the class's member variables and methods here.

#include "constant.h"

class Cylinder {
  private : 
    // Member variables for the Cylinder class.
    double base_radius{1};
    double height{1};
  
  public : 
    // Constructors for the Cylinder class.
    Cylinder() = default;
    Cylinder(double rad_param,double height_param);

    // Methods(Functions) for the Cylinder class.
    double volume();
        
};
