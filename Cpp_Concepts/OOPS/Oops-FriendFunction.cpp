// Friend Function - External tunctions with access to private mempers or a class
/*
• The friend function is first declared and alive somewhere
• The implementation can live in any translation unit. Just be sure that it will be found at link stage
• The declaration has to show up before you call the function
• The class determines who is its friend ( through friend declaration)
• The friend declaration can appear in public or private section of the class, either works the same
• We can have multiple friend functions in the same class
• Friend functions can be overloaded
• We have to use the object_name.member_var_name syntax in the friend function
• "Friend functions are not member functions", its just a external thing have a access to our own things, they have access the member function by object name and dot operator
• Friend functions don't have access to the this pointer
*/

#include <iostream>

class Dog{
    friend void debug_dog_info(const Dog& d);  //friend function declartion(it can br in public or private)
    friend void debug_dog_info();
public : 
    Dog(const std::string& name, int age) 
        : m_name{name},m_age{age}
    {

    }

private : 
    std::string m_name;
    int m_age;
};

void debug_dog_info(const Dog& d){
    std::cout << "Dog [ name : " << d.m_name << ", age : " << d.m_age << "]" << std::endl;
}

void debug_dog_info(){
    Dog dog1("Milou",3);
    dog1.m_name = "Fluffy";
    std::cout << "Dog [ name : " << dog1.m_name << ", age : " << dog1.m_age << "]" << std::endl;

}

int main(){
    Dog dog1("Fluffy",4);
    //debug_dog_info(dog1);

    debug_dog_info();
   
    return 0;
}