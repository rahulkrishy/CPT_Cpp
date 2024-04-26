/*
// Destructor:
Special methods that are called when an object dies. 
They are needed when the object needs to release some dynamic memory, or for some other kind of clean up.
Destructor will never have a parameters in c++

When destructor called?
• When a local stack object goes out of scope (dies).
• When a heap object is released with delete.
• When an object is passed by value to a function.
• When a local object is returned from a function (for some compilers).

Order of constructor destructor calls?
The constructor object created last will be called the destructor first, bcoz current constructor objects can depends on previous constructor objects, so they make call in reverse order.

*/


#include <iostream>
#include <string_view>

class Dog{

  private : 
      std::string name;
      std::string breed;
      int * p_age{nullptr}; //pointer

  public : 
      Dog() = default;    // default constructor
      Dog(std::string_view name_param, std::string_view breed_param, int  age_param);  // constructor
      ~Dog();            // destructor declaration (destructor it will never have a parameter in c++)
    //~Dog() {}; //destructor declaration (~Dog() {} - also works without semicolon)
};

// class definition outside the class
Dog::Dog(std::string_view name_param, std::string_view breed_param, int  age_param){
    name = name_param;
    breed = breed_param;
    p_age = new int;     // dynamic memory allocation
    *p_age = age_param;  // assigning value to the pointer
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog(){
    delete p_age;
    std::cout << "Dog destructor called for : " << name << std::endl;
}

void some_func(){
    // class
    Dog dog("Fluffy","Shepherd",2); //once initialized, constructor and destructor automatically calls
}

// main
int main(){ 

    some_func();
    
    std::cout << "Done!" << std::endl;
    return 0;
}
