// Smart Pointers - for better memory management
/*
Smart pointers in C++ are objects that manage the memory of dynamically allocated objects, 
providing automated memory management and helping to avoid memory leaks. (Manually releasing memory yourself through the delete operator for raw pointers is a pain in the neck.)
Memory is automatically released when the pointer goes out of scope.
There are three main types of smart pointers:

1. std::unique_ptr:
Manages the memory of a single dynamically allocated object.
Ensures that the object it points to is deleted when the std::unique_ptr goes out of scope.

2. std::shared_ptr:
Manages the memory of a dynamically allocated object.
Allows multiple std::shared_ptr instances to share ownership of the same object.
Keeps track of the number of shared_ptr instances pointing to the same object.

3. std::weak_ptr:
Similar to std::shared_ptr but doesn't affect the reference count.
Used to break circular references between std::shared_ptr instances.
Non owning pointers that don't implement the -> or * operator. 
You can't use them directly to read or modify data.
*/

#include <iostream>
#include <memory>

// 1. std::unique_ptr:

class Dog {
public:
    // Constructor
    Dog(const std::string& name) : m_name(name) {
        std::cout << "Dog " << m_name << " created." << std::endl;
    }

    // Member function
    void print_info() const {
        std::cout << "Dog " << m_name << std::endl;
    }

    // Destructor
    ~Dog() {
        std::cout << "Dog " << m_name << " destroyed." << std::endl;
    }

private:
    std::string m_name;
};

void example_unique_pointers() {
    // Creating a unique pointer using make_unique
    std::unique_ptr<Dog> dog1 = std::make_unique<Dog>("Buddy");
    dog1->print_info();

    // Transferring ownership to another unique pointer
    std::unique_ptr<Dog> dog2 = std::move(dog1);
    if (!dog1) {
        std::cout << "dog1 is nullptr (ownership moved)." << std::endl;
    }

    // Accessing the managed object
    if (dog2) {
        dog2->print_info();
    }

    // Resetting a unique pointer (releasing memory)
    dog2.reset();
    std::cout << "dog2 reset. Is it nullptr? " << (dog2 == nullptr) << std::endl;

    // Creating a unique pointer using a raw pointer
    Dog* rawDog = new Dog("Max");
    std::unique_ptr<Dog> dog3(rawDog);

    // Accessing the managed object through unique_ptr
    if (dog3) {
        dog3->print_info();
    }

    // Releasing memory using unique_ptr destructor
}


int main() {
    // 1. Creating a Unique Pointer
    std::unique_ptr<Dog> up_dog1 = std::make_unique<Dog>("Buddy");

    // 2. Accessing Member Functions
    up_dog1->print_info();

    // 3. Creating Raw Pointer from Unique Pointer
    Dog* raw_dog1 = up_dog1.get();
    raw_dog1->print_info();

    // 4. Release Ownership
    std::unique_ptr<Dog> up_dog2 = std::make_unique<Dog>("Charlie");
    Dog* released_dog = up_dog2.release(); // Release ownership
    delete released_dog; // Manually delete to avoid memory leak

    // 5. Using make_unique Syntax
    auto up_dog3 = std::make_unique<Dog>("Max");
    up_dog3->print_info();

    // 6. Copying and Assignment (Not Allowed)
    // std::unique_ptr<Dog> up_dog4 = up_dog3; // Error

    // 7. Moving Unique Pointers
    std::unique_ptr<Dog> up_dog5 = std::make_unique<Dog>("Rocky");
    std::unique_ptr<Dog> up_dog6 = std::move(up_dog5); // Move ownership
    up_dog6->print_info();

    // 8. Resetting Unique Pointer
    std::unique_ptr<Dog> up_dog7 = std::make_unique<Dog>("Lola");
    up_dog7.reset(); // Release memory and set pointer to nullptr

    // 9. Checking Validity
    if (up_dog7) {
        std::cout << "up_dog7 points somewhere valid." << std::endl;
    } else {
        std::cout << "up_dog7 points to nullptr." << std::endl;
    }

    // 10. Unique Pointers As Function Parameters And ReturnTypes
    example_unique_pointers();
    std::cout << "End of program." << std::endl;


    return 0;
}
