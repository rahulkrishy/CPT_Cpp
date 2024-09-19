// Cpp Modules
/*
In C++, a module is a language feature introduced in C++20 that allows developers to organize and encapsulate code into reusable units called modules. 
Modules provide an alternative to the traditional header file-based inclusion model used in C and C++.

Project files
. math.ixx
. main.cpp

The .ixx file extension is often used as a convention for C++ source files that contain implementation details or private implementation details of a class or module. 
It's similar to the .cpp extension, but the choice of .ixx may indicate that the file is intended to be included within other source files rather than compiled on its own.

Execution: 
GCC(13.2.0)
    Run below comments in the terminal
	. g++ -fmodules-ts -x c++-system-header iostream
	. g++ -fmodules-ts -c -x c++ math.ixx
	. g++ -fmodules-ts -c math_impl.cpp
	. g++ -fmodules-ts main.cpp math.o math_impl.o -o main.exe
    . .\main.exe

Visual C++ (Windows)
		. Create a console project and rename the file containing main to main.cpp
		. Set the standard to C++20
		. Right click on the solution name in Project Explorer and select add> Module
		. Add a module file named math.ixx and put in the code
		. Add a new cpp file named math_impl.cpp and put in the code.
		. Put the code in the main.cpp file
		. Build and run the project.
		. If <iostream> can't be processed go to properties> C/C++> General and toggle `Scan Sources for Module Dependencies` to true.
*/

import <iostream>;
import math_stuff;

int main()
{
    auto result = add(10, 20);
    std::cout << "result : " << result << std::endl;

    greet("John");

    print_name_length("John");

    Point point1(22, 44);
    std::cout << "point1 : " << point1 << std::endl;
}
