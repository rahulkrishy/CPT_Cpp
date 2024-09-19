// Module interface unit (.ixx)
module;

// Global module fragment
#include<string>

export module print; // Module declaration (also export and import at the same time by 'export import module print' to work on different interface unit)
//Module preamble
import <iostream>;

//Module purview
export{

	void print_info(std::string info);

}