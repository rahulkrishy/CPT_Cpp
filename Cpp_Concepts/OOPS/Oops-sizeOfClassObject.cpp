// Size of object = sum of sizeof member variables, regardless of the member functions

#include <iostream>
#include <string>

class Dog{
    public : 
     Dog() = default;
     void prin_info(){

     }
     void do_something(){

     }

     private :
      size_t leg_count; //8
      size_t arm_count; //8
      int * p_age; // 8
      char letter; //8
      std::string name; //32
};


int main(){

    Dog dog1;
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl; //8
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl; //8
    std::cout << "sizeof(char) : " << sizeof(char) << std::endl; //1

    std::cout << "sizeof(Dog) : " << sizeof(Dog) << std::endl; //8

    // String is stored as const char pointer
    // Size of string is always same, regardless of how long the string is. //32
    // The size of pointer depends of the pointer and not on size of what it is pointing to.
    
    std::string name{"I am the king!"}; 
    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;

    std::cout << "sizeof(dog1) : " << sizeof(dog1) << std::endl; 

    // sizeof(Dog): 64 bytes 
    // 8*3 = 24 
    // + (char 1,but due to additional padding or alignment imposed by the compiler) = 8 
    // + (string 32 bytes for 64 bit os) 32 
    // = 64 
   
    return 0;
}