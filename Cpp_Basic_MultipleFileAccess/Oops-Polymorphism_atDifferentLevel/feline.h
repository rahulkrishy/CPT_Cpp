#ifndef FELINE_H
#define FELINE_H
#include "animal.h"
class Feline : public Animal
{
public:
    Feline() = default;
    Feline(std::string_view fur_style, std::string_view description);
    virtual ~Feline();                                                     // vitual destructor 
    
    virtual void run() const{
        std::cout << "Feline " << m_description << " is running" << std::endl;
    }
    std::string m_fur_style;
};

#endif // FELINE_H

/*
// vitual destructor :
A virtual destructor in C++ is a destructor declared with the virtual keyword in the base class. 
It ensures that destructors are called in the correct order when deleting objects through base class pointers. 
This is crucial for proper memory deallocation in polymorphic hierarchies to prevent memory leaks. 
It allows derived class destructors to be called when deleting objects via base class pointers, ensuring that all resources are properly released.
*/
