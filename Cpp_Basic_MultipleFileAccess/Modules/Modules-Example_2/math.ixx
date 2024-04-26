// Module interface unit (.ixx)

module;
// Global module fragment
// add if any

export module math; // Module declaration

export import math.mult_div; //sub module

//Module preamble
import <iostream>;

//Module purview
export{

	double add(double a, double b);
	double subtract(double a, double b);

}