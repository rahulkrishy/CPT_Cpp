/*
(base)                 Animal (breathes)
       Feline(runs)                           Bird(flies)
Dog(barks)     Cat(miaw)             Pigeon (coos)   Crow (caws)

*/

#include <iostream>
#include "animal.h"
#include "feline.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"
#include "pigeon.h"
#include "crow.h"


int main(){

    //Animal polymorphism
    Dog dog1("dark gray","dog1");
    Cat cat1("black stripes","cat1");
    Pigeon pigeon1("white","pigeon1");
    Crow crow1("black","crow1");
    
    Animal* animals[]{&dog1,&cat1,&pigeon1,&crow1};
    
    for(const auto& animal : animals){
        animal->breathe();
    }

    std::cout << "------------" << std::endl;

    //Feline polymorphism
    Dog dog2("dark gray","dog2");
    Cat cat2("black stripes","cat2");
    // Pigeon pigeon2("white","pigeon2");  //Putting pigeon in felines will result in compiler error
                                        // pigeon is and Animal,a but is not a feline.
    Animal animal1("some animal");
    
    Feline* felines[] {&dog2,&cat2};
    
    for(const auto& feline : felines){
        feline->run();
    }


    std::cout << "------------" << std::endl;

    //Bird polymorphism
    Pigeon pigeon3("white","pigeon1");
    Crow crow3("black","crow1");
    
    Bird* birds[] {&pigeon3,&crow3};
    
    for(const auto& bird : birds){
        bird->fly();
    }
   
    return 0;
}


/*
When you call the virtual function through a base class pointer,
the access specifier in the base class determines whether the
function is accessible, regardless of the access specifier in the
derived class
-------------
In general, when the function call is done through dynamic binding,
the access specifier of the base class applies, if the call is done through
static binding, the access specifier of the derived class applies.
-------------
Best practice to not use default parameter or default arguments with vitual functions.
Default arguments are handled at compile time.Virtual functions are called at run time with polymorphism
If you use default arguments with virtual functions, you might get weird (erroneous) results with polymorphism.

*/