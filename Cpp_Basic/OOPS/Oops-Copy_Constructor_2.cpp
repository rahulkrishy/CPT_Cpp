#include <iostream>

class Person {
private:
    std::string last_name{};
    std::string first_name{};
    int* age{};

public:
    // Constructors
    Person() = default;
    Person(const std::string& last_name_param, const std::string& first_name_param, int age_param);
    Person(const std::string& last_name_parm, const std::string& first_name_param);
    Person(const std::string& last_name);

    // Copy Constructor
    // Person(const Person source_p); // Error: BAD: Potential for an endless chain of copy constructor calls

    // Memberwise copy
    // Person(const Person& source_p); //same as a default copy constructor

      // User-defined copy constructor( it Don't blindly copy the pointer)
    Person(const Person& source_p);

    // Destructor
    ~Person();

    // Setters
    void set_first_name(const std::string& first_name) { this->first_name = first_name; }
    void set_last_name(const std::string& last_name) { this->last_name = last_name; }
    void set_age(int age) { *(this->age) = age; } // Remember to dereference

    // Getters
    const std::string& get_first_name() const { return first_name; }
    const std::string& get_last_name() const { return last_name; }
    int* get_age() const { return age; };

    // Utilities
    void print_info() {
        std::cout << "Person object at : " << this
                  << " [ Last_name : " << last_name
                  << ", First_name :  " << first_name
                  << " ,age : " << *age
                  << " , age address : " << age
                  << " ]" << std::endl;
    }
};

// Destructor
Person::~Person() {
    delete age; // Make sure that you are not leaking memory
}

// Constructor with only last_name
Person::Person(const std::string& last_name) : Person(last_name, "") {}

// Constructor with last_name and first_name
Person::Person(const std::string& last_name_param, const std::string& first_name_param)
    : Person(last_name_param, first_name_param, 0) {}

// Full constructor with last_name, first_name, and age
Person::Person(const std::string& last_name_param, const std::string& first_name_param, int age_param)
    : last_name(last_name_param),
      first_name(first_name_param),
      age(new int(age_param)) {}


/*
Person::Person(const Person source_p)  // Error!
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_last_name()),
        age(source_p.get_age())

{

}
*/


//Memberwise copy :  // work same as a default copy constructor     
/*
Person::Person(const Person& source_p) 
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_first_name()),
        age(source_p.get_age())

{
    std::cout << "Copy constructor called" << std::endl;

}
*/

// Copy Constructor (Don't blindly copy pointer member variables)
Person::Person(const Person& source_p)
    : last_name(source_p.get_last_name()),
      first_name(source_p.get_first_name()),
      age(new int(*(source_p.get_age())))        // it create a dynamic memory allocation to make a new copy
{
    std::cout << "Copy constructor called" << std::endl;
}

int main() {
    // Create a Person object
    Person p1("John", "Snow", 25);
    p1.print_info();

    // Create a copy of the Person object using the copy constructor
    Person p2(p1);
    p2.print_info();

    std::cout << "-------" << std::endl;

    // Modify the original Person object
    p1.set_age(30);
    p1.print_info();

    // Check if the copy reflects the changes
    p2.print_info();

    return 0;
}
