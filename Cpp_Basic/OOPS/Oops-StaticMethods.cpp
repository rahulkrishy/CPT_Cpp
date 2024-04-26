// Static methods (member function)
/*
Static member functions belong to the class rather than an instance of the class.
They are called using the class name, not an object of the class.
They can access only static members (variables or functions) of the class.
They cannot access non-static members directly as they don't have access to any specific instance.
*/


#include<iostream>
using namespace std;

class Dog {
private:
    string m_dog_name;
    int m_dog_age;
    static int m_obj_count; // Static member variable to count the number of objects created

public:
    // Constructor Implementation: Initializer list Initialization
    Dog(string dog_name, int dog_age) : m_dog_name(dog_name), m_dog_age(dog_age) {
        ++m_obj_count; // Increment the class object count when a new object is created
    }

    void dog_info() {
        cout << "\nDog name: " << m_dog_name << "\nDog age: " << m_dog_age;
    }

    ~Dog() {
        --m_obj_count; // Decrement the class object count when an object is destroyed
    }

    // Static member function to access the static member variable
    static int getObjCount() {
        // Static member function can only access static member variables or other static member functions
        // It cannot access non-static member variables or functions directly
        return m_obj_count;
    }

    // Another static member function
    static void displayInfo() {
        cout << "\nThis is a static member function!";
    }
};

// Initialize the static member variable outside the class
int Dog::m_obj_count {0};

int main() {
    cout << "\nObject count: " << Dog::getObjCount() << "\n";  // Accessing static member function
    Dog d1{"Blacky", 5};
    d1.dog_info();

    Dog::displayInfo(); // Accessing another static member function

    Dog d2{"rosey", 2};
    d2.dog_info();
    cout << "\nObject count: " << Dog::getObjCount() << "\n";

    return 0;
}
