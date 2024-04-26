/*
Anonymous Namespaces:
When the compiler sees an anonymous namespace declaration it will generate an
internal name for the namespace
The generated unique namespace name is not accessible to YOU, the developer
There can only be one anonymous namespace for a single translation unit. If you set
up multiple anonymous namespace blocks, they'll just be extensions to the first one
Anonymous namespaces in different translation units are completely separate
though, the compiler generates different unique namespace names for them
behind the scenes
Because we don't have access to the compiler generated namespace name for
anonymous namespaces, names declared inside anonymous namespaces are only
reachable/usable in the TU where they were declared.
Names in an anonymous namespace are only reachable/usable from the
TU where they were declared/defined.
*/

#include <iostream>

namespace{
    double add(double a, double b); // Declaration
} 


int main(){

    double result = add(10.2,20.2);
    std::cout << "result : " << result << std::endl;
   
    return 0;
}


namespace{
    double add(double a, double b){
        return a + b;
    }
} 