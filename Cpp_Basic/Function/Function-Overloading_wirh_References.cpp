// Function overloading is setting up different function with a same name , but only differences in parameters of the functions

#include <iostream>
#include <string>

//Ambiguous calls
void say_my_name( const std::string& name){
    std::cout << "Your name is (ref) : " << name << std::endl;
}

void say_my_name( std::string name){
    std::cout << "Your name is (non ref) : " << name << std::endl;
}

//Implicit conversions with references

double max(double a, double b){
    std::cout<< "double max called" << std::endl;
    return (a>b)?a:b;
}



//int& max(int& a, int& b){                  // it won't work, bcoz Temporarys won't work with non const references(string conversions, and some inplicit conversions), if its the case then complier goes for above double block(without reference type) 
const int& max(const int& a,const int& b){   // it must be const type to work on referneces, if not const here, then it might be explicitly conversion(static_cast<>) done before passing arguments)
    std::cout << "int max called" << std::endl;
    return (a>b)?a:b;
}

int main(){

    char a{6};
    char b{9};




    auto result = max(a,b);

   
    return 0;
}