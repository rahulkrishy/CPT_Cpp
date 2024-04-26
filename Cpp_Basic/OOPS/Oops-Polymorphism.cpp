/*
Polymorphism is a fundamental concept in object-oriented programming (OOP) is design principle, that allows objects of different classes to be treated as objects of a common superclass. 
Managing derived objects in memory though base pointers or references and getting the right method called on the base pointer or reference.
It enables flexibility and extensibility in software design by allowing different classes to be used interchangeably through a common interface.

Types of Polymorphism:
1) Compile-time Polymorphism (Static Binding or Early Binding): 
Occurs when the decision about which function to call is made at compile time. 
It is achieved through function overloading and operator overloading.

2)Run-time Polymorphism (Dynamic Binding or Late Binding): 
Occurs when the decision about which function to call is made at runtime. 
It is achieved through function overriding and virtual functions.

Virtual Functions:
A virtual function is a member function declared within a base class that is expected to be overridden in a derived class.
When a function is declared as virtual in a base class, it indicates to the compiler that the function may be overridden in derived classes.
Virtual functions allow a program to call methods that don't necessarily exist at compile time but are resolved at runtime based on the actual object being referred to.
Virtual functions are declared using the virtual keyword.

Function Overriding:
Function overriding occurs when a function in a derived class has the same name, return type, and parameters as a function in its base class.
The function in the derived class overrides the function in the base class, providing a specific implementation for that function in the derived class.
Function overriding enables polymorphism, allowing objects of different derived classes to be treated as objects of the base class when accessed through a pointer or reference to the base class.
Overridden functions must have the same signature (name, return type, and parameters) as the base class function, and they are typically preceded by the override keyword to improve code readability and maintainability.
*/

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 1) Compile-time Polymorphism (Static Binding or Early Binding):

/*
#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int result1 = add(5, 3);        // Calls the first add function
    int result2 = add(2, 4, 6);      // Calls the second add function
    
    cout << "Result 1: " << result1 << endl;   // Output: Result 1: 8
    cout << "Result 2: " << result2 << endl;   // Output: Result 2: 12
    
    return 0;
}
*/

/*
Static binding is bad when you are managing lot of related object in cpp program.
In this example, the add function is overloaded to accept different numbers of arguments. 
The decision about which version of the add function to call is made at compile time based on the number and types of arguments passed to it. 
This is an example of static binding because the binding between the function call and the function definition is determined at compile time.
*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 2)Run-time Polymorphism (Dynamic Binding or Late Binding): 

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function to calculate area
    virtual double area()       //virtual is keyword enables dynamic binding, without virtual it's static binding (also with base pointer/reference)
    {
        cout<<"Shape::area()"<<endl;
        return 0; //function return type of double so return 0.
    }
    // virtual double area() = 0; //Pure virtual function , Once you set up at least one pure virtual function in your class the class is automatically going abstract class, then this class won't be able to create a object for this class
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // constructor
    Circle(double r) : radius(r) {}

    // Override the area function
    virtual double area() override {
        cout<<"Circle::area()"<<endl;
        return 3.14 * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the area function
    virtual double area() override                      //one override function will hide all other overloading function
    {
        cout<<"Rectangle::area()"<<endl;
        return length * width;
    }
};

// base pointer function
void draw_shape1(Shape * s){
    s->area();
}

// base reference function
void draw_shape2(Shape& s){
    s.area();
}

int main() {
    // Creating object of Shape
    Shape form;

    // Creating objects of Circle and Rectangle
    Circle circle(5);
    Rectangle rectangle(4, 6);

    // (1) Base Pointer type
    // /*
    // Pointer to the base class
    Shape* shape;

    // Assigning address of shape object to base class pointer(same Shape)
    shape = &form;
    cout << "Shape: " << shape->area() << endl; // Calls Shape's area() function

    // Assigning address of Circle object to base class pointer
    shape = &circle;
    cout << "Area of Circle: " << shape->area() << endl; // Calls Circle's area() function

    // Assigning address of Rectangle object to base class pointer
    shape = &rectangle;
    cout << "Area of Rectangle: " << shape->area() << endl; // Calls Rectangle's area() function
    // */

    // (2) Base Reference type (also works)
    /*
    Shape& shape = circle;
    cout << "Area of Circle: " << shape.area() << endl; // Calls Circle's area() function
    */

    // (3) Base Function type
    /*
    draw_shape1(&circle); // Calls Circle's area() function via base pointer funtion
    draw_shape2(circle); // Calls Circle's area() function via base reference funtion
    */

    // (4) Shapes stored in collections type
    /*
    Shape* shape_collection[]{&form,&circle,&rectangle};
	for(Shape* s_ptr : shape_collection){
        cout<<s_ptr->area()<<endl;
    }
    */

    // Comparing Object size
    // /*
     std::cout << "sizeof(form) : " << sizeof(form) << std::endl; // dynamic : 8
     std::cout << "sizeof(Circle) : " << sizeof(Circle) << std::endl; // dynamic : 16
     std::cout << "sizeof(rectangle) : " << sizeof(rectangle) << std::endl; // dynamic : 24
    // */

    return 0;
}

/*
In this example, the Shape class has a virtual function area(). The derived classes Circle and Rectangle override this function. 
When a base class pointer (Shape*) is used to access the area() function, the actual function called depends on the type of object pointed to at runtime. 
This is an example of dynamic binding because the binding between the function call and the function definition is determined at runtime based on the object's dynamic type.

// Constructor and destructor call order :
• Base Constructor
• Derived Constructor
      //Use constructed object
• Derived Destructor
• Base destructor
Calling a virtual function from a constructor or destructor won't give you polymorphic results,you will get static binding results.
Never call virtual functions from constructors or destructors.

// Pure virtual function and abstract class:
If a class has at least one pure virtual function, it becomes an abstract class
You can't create objects of an abstract class, if you do that, you'll get a hard compiler error
You can't call the pure virtual functions from the constructor of the abstract class

// override
override keyword is used to explicitly indicate that a member function in a derived class is intended to override a virtual function in the base class. 
This helps catch errors at compile time if the function signature doesn't match the base class function it's supposed to override.

// Comparing Object size
objects often have larger sizes due to the inclusion of virtual function tables (vtables) and additional pointers for dynamic dispatch, enabling runtime binding. 
This overhead ensures proper function invocation at runtime, impacting object size compared to non-polymorphic objects.
However, the benefits of runtime polymorphism often outweigh this drawback, as it enables flexibility and extensibility in object-oriented designs.

// typeid
typeid is an operator in C++ used to determine the type of an expression. 
It returns a type_info object representing the data type of the expression, static/dynamic type.

*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------







