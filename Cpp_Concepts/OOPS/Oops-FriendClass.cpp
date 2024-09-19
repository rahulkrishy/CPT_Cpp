// Friend class . Giving access to our own member variables to external entities. External entities can be either functions or classes
#include<iostream>
using namespace std;

class Dog
{
  friend class Cat;
private:
  string m_dog_name;
  int m_dog_age;
public:
  Dog(string dog_name, int dog_age): m_dog_name(dog_name), m_dog_age(dog_age)
  {}
  void dog_info()
  {
    cout<<"Dog name: "<<m_dog_name<<"\nDog age: "<<m_dog_age;
  }
};

class Cat
{
private:
  string m_cat_name;
  int m_cat_age;
public:
  Cat(string cat_name, int cat_age): m_cat_name(cat_name), m_cat_age(cat_age)
  {}
  void cat_info()
  {
    cout<<"cat name: "<<m_cat_name<<"\ncat age: "<<m_cat_age;
  }
  // accessing class 1 from class 2
  void check_dog_info(Dog d)
  {
    cout<<"Dog name: "<<d.m_dog_name<<"\nDog age: "<<d.m_dog_age;
  }
};


int main()
{
  // class 1
  cout<<"--Dog Class--\n";
  Dog d1("Blacky",6);
  d1.dog_info();

  cout<<"\n";

  // class 2
  cout<<"--Cat Class--\n";
  Cat c1("Meow",2);
  c1.cat_info();
  cout<<"\nAccessing Dog class from Cat Class, using friend:\n";
  c1.check_dog_info(d1);                                          //we need to pass Dog class object to Cat class to access as friend class

}