/* Class:
// Class are the mechanism to able to build our own types
// Classes have functions (methods) that let them do things
// Class methods have access to the member variables, regardless of whether they are public or private
// Private members of classes (variables and functions) aren't accessible from the outside of the class definition
// class members are private by default
*/

/* class constructor:
// A special kind of method that is called when an instance of a class is created.
// No return type
// Same name as the class
// Can have parameters. Can also have an empty parameter list
// Usually used to initialize member variables of a class
*/
 

#include<iostream>
using namespace std;

// Class definition
class students
{
  // Access Specifier
  public:

    // Data members/member variables/Properties
    string studentName {"krish"};

  private:
    int rollNo {003};

  public:
    // member function/Methods/Behaviours

    // Class constructor
      students(){
          cout<<"Welcome students!\n"<<endl;
      }

    // Member function declared inside the class
    void printName()
    {
      cout<<"Student Name: "<<studentName<<endl;
    }

    // Member function declared outside the class
    void printId();
};

// Definition of member function outside the class
void students::printId()
{
  cout<<"Students RollNo: "<<rollNo;
}


// Main function
int main()
{
  // Creating an object of the students class
  students stu1;

  // Calling member functions using the object
  stu1.printName();
  stu1.printId();

  // Accessing Public member variables/data members
  cout<<"\nOutside class: Student_Name: "<<stu1.studentName<<endl;
  // cout<<"\nOutside class: rollno: "<<stu1.rollNo<<endl;         //private inaccessiable 

  cout<<"\n\nAfter Modifiaction: \n";

  // modifying values to data members
  stu1.studentName = "AuraMan";
  // stu1.rollNo = 007;                // can't modifiable, bcoz private access modifiers

  // Calling member functions using the object after modification
  stu1.printName();
  stu1.printId();
  
  return 0;
}
