// Cpp Modules
/*
In C++, a module is a language feature introduced in C++20 that allows developers to organize and encapsulate code into reusable units called modules. 
Modules provide an alternative to the traditional header file-based inclusion model used in C and C++.

Project files
. math.ixx
. main.cpp

The .ixx file extension is often used as a convention for C++ source files that contain implementation details or private implementation details of a class or module. 
It's similar to the .cpp extension, but the choice of .ixx may indicate that the file is intended to be included within other source files rather than compiled on its own.

Export Import:
	-export and import works at the same time by 'export import module/template/namespace functionName' to work on different interface unit
	-You can export Variables, functions, classes, function templates, class templates, concepts.
	-You can't export entities with internal linkage, like names living inside anonymous namespaces and those qualified with the static keyword
	-You can only export things that live at the namespace level. For example, you can't export the member variables of a class.
	-Template code should live in one module file, separating into different interface files or implementation files will lead to weird errors

Execution: 
GCC(13.2.0)
    Run below comments in the terminal
	. g++ -fmodules-ts -x c++-system-header iostream   // if any other header is used, then run in terminal next to it, example if cmath header is used, run 'g++ -fmodules-ts -x c++-system-header cmath'
	. g++ -fmodules-ts -c -x c++ mult_div.ixx          //sub modules should be run first
	. g++ -fmodules-ts -c -x c++ math.ixx
	. g++ -fmodules-ts -c -x c++ print.ixx
	. g++ -fmodules-ts -c add_impl.cpp
	. g++ -fmodules-ts -c subtract_impl.cpp
	. g++ -fmodules-ts -c print_info.cpp
	. g++ -fmodules-ts main.cpp math.o mult_div.o print.o add_impl.o subtract_impl.o print_info.o -o main.exe
    . .\main.exe

Visual C++ (Windows)
	. Create a console project and rename the file containing main to main.cpp
	. Set the standard to C++20
	. Right click on the solution name in Project Explorer and select add> Module
	. Add a module file named math.ixx and put in the code
	. Add a module file named mult_div.ixx and put in the code
	. Add a module file named print.ixx and put in the code
	. Add a new cpp file named add_impl.cpp and put in the code.
	. Add a new cpp file named subtract_impl.cpp and put in the code.
	. Add a new cpp file named print_info.cpp and put in the code.
	. Put the code in the main.cpp file
	. Build and run the project.
	. If <iostream> can't be processed go to properties> C/C++> General and toggle `Scan Sources for Module Dependencies` to true.
*/

import <iostream>;
import math;       //import entire module
//import math.mult_div;  //import sub module
import print;

int main() {
    int a = 10, b = 5;
    
    // Perform arithmetic operations

		std::cout<<"num1: "<<a<<std::endl<<"num2: "<<b<<std::endl;
		std::cout<<"-----------------"<<std::endl;

		auto result = add(a, b);                                 //here add and subtract function in main module
    std::cout << "addition   : " << result << std::endl;

		result = subtract(a, b);
    std::cout << "subraction : " << result << std::endl;

		auto result1 = mult(10, 20);                              //multiplication and division function in sub module
    std::cout << "Multiplication : " << result1 << std::endl;

		std::cout<<"-----------------"<<std::endl;

		print_info("hello");
   
    return 0;
}
