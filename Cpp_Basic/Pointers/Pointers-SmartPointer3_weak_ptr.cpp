/*
3. std::weak_ptr:
Similar to std::shared_ptr but doesn't affect the reference count.
Used to break circular references between std::shared_ptr instances.
Non owning pointers that don't implement the -> or * operator. 
You can't use them directly to read or modify data.
*/

#include <iostream>
#include <memory>

int main() {
    // Creating a shared pointer
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);

    // Creating a weak pointer from the shared pointer
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Accessing the value through the weak pointer
    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Value: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Object has been deleted" << std::endl;
    }

    // Weak pointer does not affect reference count
    std::cout << "Reference count: " << sharedPtr.use_count() << std::endl;

    return 0;
}
