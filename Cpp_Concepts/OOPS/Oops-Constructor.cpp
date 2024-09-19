// Constructor
// Member wise Initialization: Constructor sets member variables inside the constructor body.
// Advantage: Allows additional logic or computation while initializing member variables.

// Initializer list Initialization: Constructor uses initializer list to directly initialize member variables.
// Advantage: More efficient, avoids the need for an extra assignment, potentially improving performance.


/*
Constructor:
- Can be overloaded
- allocate memory from object
- execute when the class comes to scope
- Name should be name of the class
- can have many constructor

Destructor:
- Cannot be overloaded
- delete memory from object
- execute when the class goes out of scope
- Name should be name of the class with tilde symbol
- can have only one destructor

*/
#include<iostream>
using namespace std;

class Dog
{
private:
    string m_dog_name;
    int m_dog_age;

public:
    Dog() = default;    // default constructor
    // Constructor Implementation: Member wise Initialization
    // Dog(string dog_name, int dog_age)
    // {
    //   m_dog_name = dog_name;
    //   m_dog_age = dog_age;
    // }

    // Constructor Implementation: Initializer list Initialization
    Dog(string dog_name, int dog_age) : m_dog_name(dog_name), m_dog_age(dog_age)
    {
    }

    void dog_info()
    {
        cout << "Dog name: " << m_dog_name << "\nDog age: " << m_dog_age;
    }
};

int main()
{
    Dog d1{"Blacky", 5};
    d1.dog_info();

    return 0;
}
