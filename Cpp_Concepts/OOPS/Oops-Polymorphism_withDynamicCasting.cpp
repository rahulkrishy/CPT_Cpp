// Oops-Polymorphism_withDynamicCasting
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    virtual ~Base() {} // Virtual destructor for polymorphism

    // Polymorphic function
    virtual void polymorphic_function() {
        cout << "Polymorphic function in Base class" << endl;
    }

    // Non-polymorphic function
    void non_polymorphic_function() {
        cout << "Non-polymorphic function in Base class" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Override the polymorphic function
    void polymorphic_function() override {
        cout << "Polymorphic function in Derived class" << endl;
    }

    // Non-polymorphic function
    void non_polymorphic_function() {
        cout << "Non-polymorphic function in Derived class" << endl;
    }
};

int main() {
    // Create a Base class pointer pointing to a Derived object
    Base* base_ptr = new Derived();

    // Attempt to call the polymorphic function
    base_ptr->polymorphic_function(); // Calls Derived class implementation

    // Attempt to call the non-polymorphic function using dynamic casting
    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
    if (derived_ptr) {
        // Dynamic casting succeeded, call the function in Derived class
        derived_ptr->non_polymorphic_function();
    } else {
        // Dynamic casting failed, object is not of Derived type
        cout << "Dynamic casting failed" << endl;
    }

    delete base_ptr; // Clean up memory

    return 0;
}



/*
It defines a base class Base with a virtual function polymorphic_function() and a non-virtual function non_polymorphic_function().
A derived class Derived overrides the polymorphic_function() and also defines a non-virtual version of non_polymorphic_function().
In main(), a Base pointer points to a Derived object. Polymorphism is showcased by calling the polymorphic_function() through the base pointer.
Dynamic casting is used to cast the Base pointer to a Derived pointer to access the non-polymorphic function specific to Derived.
This demonstrates the flexibility of polymorphism and dynamic casting in handling different types at runtime.
*/