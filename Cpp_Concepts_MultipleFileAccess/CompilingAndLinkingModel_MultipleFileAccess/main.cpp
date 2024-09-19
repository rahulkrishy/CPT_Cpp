// CompilingAndLinkingModel_MultipleFileAccess
/*
- 3 Steps: Preprocessing -> Compilation -> Linking
- IDEs actually call compilers behind the scenes for us to compile our code and generate an binary we can run. 
- Compile and link in one go: " g++ -o main.exe main.cpp utilities.cpp "
- Compile only, generate object files: " g++ -c main.cpp utilities.cpp "
- Link up object files: " g++ -o main.exe main.o utilities.o "
*/

#include <iostream>
#include "utilities.h"

int main(){

    double result = add(10.5,20.5);
    std::cout << "result : " << result << std::endl;
    
    return 0;
}