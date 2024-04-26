// Oops - Abstraction
/*
-Abstraction is a fundamental principle of object-oriented programming (OOP) 
 that allows us to model real-world entities as classes with relevant attributes and behaviors, while hiding the complex implementation details. 
-It focuses on what an object does rather than how it does it. 
-Abstraction helps in reducing the complexity of the system by providing a simplified view of the objects.
*/

#include <iostream>
#include <string>

// Abstract class representing a shape
class Shape {
public:
    // Pure virtual function to calculate area (abstract method)
    virtual double calculateArea() const = 0;
};

// Concrete subclass representing a rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implementation of the calculateArea() method
    double calculateArea() const override {
        return length * width;
    }
};

// Concrete subclass representing a circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Implementation of the calculateArea() method
    double calculateArea() const override {
        return 3.14159 * radius * radius; // Assuming pi is approximately 3.14159
    }
};

int main() {
    // Create objects of different shapes
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);

    // Calculate and display the area of each shape
    std::cout << "Area of the rectangle: " << rectangle.calculateArea() << std::endl;
    std::cout << "Area of the circle: " << circle.calculateArea() << std::endl;

    return 0;
}


/*
In this example:

The Shape class is an abstract class that defines an interface for shapes. 
It contains a pure virtual function calculateArea(), which acts as an abstract method. 
This method is meant to be overridden by concrete subclasses to provide specific implementations for calculating the area of different shapes.
The Rectangle and Circle classes are concrete subclasses of Shape that provide implementations for the calculateArea() method. 
Each class represents a specific shape and implements the area calculation logic accordingly.
The main() function demonstrates how to create objects of different shapes (Rectangle and Circle) and call their calculateArea() methods polymorphically through the base class pointer.
Abstraction allows us to work with objects at a higher level of conceptualization, focusing on what they do (i.e., their behavior) rather than how they do it (i.e., their implementation details). 
This simplifies the usage of objects and promotes code reusability and maintainability.
The example above does demonstrate polymorphism as well, along with abstraction. 
Polymorphism is another key concept in object-oriented programming (OOP), 
and it allows objects of different classes to be treated as objects of a common base class.
*/