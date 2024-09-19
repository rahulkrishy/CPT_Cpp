#ifndef DOG_H
#define DOG_H
#include "feline.h"
class Dog : public Feline
{
public:
    Dog() = default;
    Dog(std::string_view fur_style, std::string_view description);
    virtual ~Dog();
    
    virtual void bark() const{
        std::cout << "Dog::bark called : Woof!" << std::endl;
    }

    virtual void breathe()const override{
        std::cout << "Dog::breathe called for : " << m_description << std::endl;
    }

    virtual void run() const override final{                                        //no next derived run() function can be override(final - prevents access from downstream classes)
        std::cout << "Dog " << m_description << " is running" << std::endl;
    }

};

#endif // DOG_H

/*
final:
final keyword is used to indicate that a class, member function, or virtual function cannot be overridden or further derived from. 
It's used to prevent inheritance or overriding in derived classes, providing a way to enforce immutability or prevent certain types of modifications in the codebase.
*/