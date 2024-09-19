// Static member variables
/*
Regular member variables: are associated with objects. They belong to class objects.
Ststic member variables: Member variables not tied to any object of the class. They live in the context of object blueprints. 
The are created even before a single class object has been created.
*/

#include<iostream>
using namespace std;

class Dog
{
private:
    string m_dog_name;
    int m_dog_age;

public:

    static int m_obj_count; //it should be always public to access itself in the blueprint of the class(if private, then using after object declared only can access it with member function only)
    // (You can't declare a non const static member variable and in-class initialize it, the only way to do is using inline)
    // inline static int m_obj_count {0};
    // static inline const double PI {3.1415926535897932384626433832795}; //C++17 static const(to avoid copies for each ojects, it align with the blueprint of the class)

    // Constructor Implementation: Initializer list Initialization
    Dog(string dog_name, int dog_age) : m_dog_name(dog_name), m_dog_age(dog_age)
    {
        ++m_obj_count; //increment the class object count
    }

    void dog_info()
    {
        cout << "\nDog name: " << m_dog_name << "\nDog age: " << m_dog_age;
    }

    ~Dog()
    {
        --m_obj_count;
    }
};

// Initialize the static member variable(if we initialize inside, we will get error; only way is to initialize outside the class)
int Dog::m_obj_count {0};

int main()
{
    cout<<"\nObject count: "<<Dog::m_obj_count<<"\n";  // "Dog::m_obj_count" have a direct access(by using class), before the object is initialized
    Dog d1{"Blacky", 5};
    d1.dog_info();
    // cout<<"\nObject count: "<<Dog::m_obj_count<<"\n";

    Dog d2{"rosey", 2};
    d2.dog_info();
    cout<<"\nObject count: "<<Dog::m_obj_count<<"\n";

    return 0;
}