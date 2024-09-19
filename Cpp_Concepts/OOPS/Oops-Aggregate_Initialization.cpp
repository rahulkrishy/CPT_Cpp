// (1) Aggregate Initialization // (2) Designated Initializers // (3) Uniform Initialization For Aggregates

#include <iostream>
#include <string>

// (1) Aggregate Initialization
struct Point
{
    double x;
    double y;
};

void print_point(const Point& p){
    std::cout << "Point [ x : " << p.x << " , y : " << p.y << "]" << std::endl;
}

// (2) Designated Initializers
struct Component
{
    double x;
    double y;
    double z;
};

void print_component(const Component& c){
    std::cout << "Component [ x : " << c.x << ", y: " << c.y << " ,z : " << c.z << "] " << std::endl;
}

// (3) Uniform Initialization For Aggregates
class PointClass {
public:
    PointClass(double x, double y) : m_x{x}, m_y{y} {
        std::cout << "PointClass constructor called" << std::endl;
    }
private:
    double m_x;
    double m_y;
};

struct Person
{
    std::string m_name;
    unsigned int m_age;
};

int main(){
    // Part 1: Aggregate Initialization
    Point p1{10,20};
    print_point(p1);

    int scores[] {44,62,67,82,98,43,2,5,67};

    // Part 2: Designated Initializers
    Component c1{.x = 5.7,.y = 8.2,.z = 5.2};
    Component c2{.x =6.2,.z =8.4};
    Component c3{.y = 6.2,.z = 5.9};
    // Component c4 {.z =5.9 , .x=10.4 , .y =6.89}; // Compiler error

    print_component(c1);
    print_component(c2);
    print_component(c3);

    // Part 3: Uniform Initialization For Aggregates
    PointClass p2{10.9, 39.3}; // Uniform initialization : () or {}

    // Struct
        // {}
    // Person person1 {"Daniel",35}; // Correct
    // Person person1 {"Daniel",35.5}; // Error: "{}" intialization not supports narrowing conversion

        // ()
    Person p3("John",41.7);

    // int students[] {1, 2, 3, 4.7, 5, 6, 7}; // Error: "4.7" is double type, narrowing conversion not supported in "{}" intialization 
    int students[] (1, 2, 3, 4.7, 5, 6, 7); // "()" initialization supports narrowing conversion

    return 0;
}
