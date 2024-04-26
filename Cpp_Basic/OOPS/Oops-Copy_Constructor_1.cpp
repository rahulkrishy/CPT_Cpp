/*
Copy Constructor:
A copy constructor is a special type of constructor in a class 
that is used to create a new object as a copy of an existing object of the same class.
There are three types of copy constructors:

(1)Default Copy Constructor:
Automatically provided by the compiler if no user-defined copy constructor is declared.
Performs a shallow copy, copying each member variable from the source object to the destination object.

(2)User-Defined Copy Constructor:
Explicitly defined by the programmer in the class.
Allows customization of the copy process, enabling deep copies and dynamic memory management.

(3)Move Constructor:
Introduced in C++11 to optimize performance when transferring resources from one object to another.
Performs a "move" rather than a copy, transferring ownership of resources.

+--------------------+-----------------------------+-------------------------------+----------------------------------+
| Feature            | Default Copy Constructor    | User-Defined Copy Constructor | Move Constructor                 |
|--------------------|-----------------------------|-------------------------------|----------------------------------|
| Declaration        | Provided by Compiler        | Defined by Programmer         | Defined by Programmer (C++11)    |
| Usage              | Shallow Copy                | Custom Copy Logic             | Move Resources (Efficient)       |
| Memory Management  | May lead to issues with     | Can manage dynamic memory     | Transfers ownership efficiently  |
|                    | pointers and dynamic memory | effectively                   |                                  |
| Customization      | Limited customization       | Full customization            | Efficient Resource Transfer      |
| Syntax             | Automatically generated     | Defined by the programmer     | Defined by the programmer (C++11)|
| Example            | ClassA obj1 = obj2;         | ClassB obj1(obj2);            | ClassC obj1 = std::move(obj2);   |
+--------------------+-----------------------------+-------------------------------+----------------------------------+

*/

#include <iostream>
#include <cstring>

// Class with default copy constructor
class DefaultCopyConstructor 
{
public:
    int data;

    // Default constructor implementation using initializer list
    DefaultCopyConstructor(int value) : data(value) 
    {
    }

};


// Class with user-defined copy constructor
class UserDefinedCopyConstructor 
{
private:
    char* str;

public:
    // Parameterized constructor
    UserDefinedCopyConstructor(const char* s) 
    {
      str = new char[strlen(s) + 1];
      strcpy(str, s);
    }

    // User-defined copy constructor
    UserDefinedCopyConstructor(const UserDefinedCopyConstructor& other) 
    {
      str = new char[strlen(other.str) + 1];
      strcpy(str, other.str);
    }

    // Destructor to release memory
    ~UserDefinedCopyConstructor() 
    {
      delete[] str;
    }

    // Display method
    void display() 
    {
      std::cout << "String: " << str << std::endl;
    }
};


// Class with move constructor
class MoveConstructor 
{
private:
    int* data;

public:
    // Parameterized constructor
    MoveConstructor(int value) 
    {
      data = new int(value);
    }

    // Move constructor
    MoveConstructor(MoveConstructor&& other) noexcept  //&& - represent move constructor
    {
      data = other.data;
      other.data = nullptr;           //after moving , set other to nullptr
    }

    // Destructor to release memory
    ~MoveConstructor() 
    {
      delete data;
    }

    // Display method
    void display() 
    {
      std::cout << "Data: " << *data << std::endl;
    }
};


int main() {
    // Example of Default Copy Constructor
    DefaultCopyConstructor obj1(42);
    DefaultCopyConstructor obj2 = obj1;
    std::cout << "Default Copy Constructor: " << obj2.data << std::endl;

    // Example of User-Defined Copy Constructor
    UserDefinedCopyConstructor str1("Hello");
    UserDefinedCopyConstructor str2 = str1;
    std::cout << "User-Defined Copy Constructor: ";
    str2.display();

    // Example of Move Constructor
    MoveConstructor source(10);
    MoveConstructor destination = std::move(source);
    std::cout << "Move Constructor: ";
    destination.display();

    return 0;
}


