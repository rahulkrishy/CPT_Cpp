//Move semantics
/*
Move semantics feature introduced in C++11 that enables efficient transfer of resources (such as memory ownership) from one object to another. 
It allows the movement of resources without the need for unnecessary copying, resulting in improved performance and reduced overhead, especially for large or expensive-to-copy objects.

key concepts related to move semantics:
1) Lvalue:
An lvalue (short for "locator value") refers to an object that has a name and is addressable in memory.
Lvalues often correspond to objects that can appear on the left-hand side of an assignment operation.
Examples of lvalues include variables, constants, and objects with names.
2)Rvalue:
An rvalue refers to a temporary or unnamed object that does not have a persistent identity.
Rvalues typically represent temporary values that are generated during expressions, such as function returns or type casts.
Rvalues often correspond to objects that can appear on the right-hand side of an assignment operation.
Examples of rvalues include literal values, temporary objects, and the results of expressions.
3)Rvalue References:
Move semantics are built upon the introduction of rvalue references (&&) in C++11.
An rvalue reference is a reference that can bind to temporary objects (rvalues), typically created during expressions like function returns or type casts.
Rvalue references allow the distinction between temporary objects (which can be moved from) and named objects (which cannot be moved from).
4)Move Constructors and Move Assignment Operators:
Move semantics enable the creation of move constructors and move assignment operators.
A move constructor is a special constructor that efficiently initializes a new object by "stealing" resources from an existing object (an rvalue).
A move assignment operator is a special assignment operator that efficiently transfers resources from one object to another.
5)std::move:
The std::move function is used to cast an lvalue to an rvalue reference, allowing it to be moved from.
It is typically used to indicate to the compiler that it is safe to move resources from an object, even if it appears in an lvalue context.
*/

#include <iostream>
#include <utility> // Required for std::move
using namespace std;

class Swapper 
{
  public:
    // Empty constructor
    Swapper() {
      std::cout<<"Constructor"<<std::endl;
    }

    // Destructor
    ~Swapper() {
      std::cout<<"destructor"<<std::endl;
    }

    // Function to swap two integers using move semantics
    void swap_with_move(int& a, int& b) 
      {
        // Normal way of transferring via copies
        // int temp { a }; // invokes copy constructor
        // cout<<"first temp: "<<temp<<std::endl;
        // a = b; // invokes copy assignment
        // b = temp; // invokes copy assignment
        // cout<<"last temp: "<<temp<<std::endl;

        // Move semantics allows efficient transfer of resources
        int temp = std::move(a); // Move a into temp, invokes move constructor
        std::cout<<"first temp: "<<temp<<std::endl; // after transferring the value of a to temp using std::move, a is left in a valid but unspecified state. 
                                          // This means that its value is unspecified and can be anything, including the original value of a or even zero-initialized for fundamental types.
                                          // However, in practice, compilers typically optimize move operations for fundamental types by not modifying the original value of a.
                                          // Therefore, you may observe that a retains its original value (5) after the move operation, rather than being zero-initialized. 
                                          // This behavior is an optimization by the compiler to avoid unnecessary operations on fundamental types.
        a = std::move(b);        // Move b into a, invokes move assignment operator
        b = std::move(temp);     // Move temp into b, invokes move assignment operator
        std::cout<<"last temp: "<<temp<<std::endl;
      }
};

int main() {

    // 1) Lvalues
    int x{5};  // X,y and z are all Ivalues, they have a memory address we
    int y{10}; // can retrieve and use later on ,
    int z{20}; // as long as the variables are in scope.

    // 2) Rvalues
    z = x+y;    // the result of (xty) is stored in memory for a short time (transiently)
                // before it's assigned (copied) to z. After the assignment, the memory is discarded
                // (reclaimed by the system). (x+y) is (or evaluates to) an rvalue.
    //std:: cout << "address of (x&y) : " << &(x+y); // Can't grab the address of an rvalue.
    std::cout<< "Z: "<<z<<std::endl;

    // 3) Rvalue References(&&)
    int&& result = x+y; // Extends the lifetime of the temporary result
    cout<< "result: "<<result<<std::endl;

    cout<<"-----------------------"<<std::endl;
    // 4) std::move
    // std::move doesn't move data by itself, it just casts its parameter to an value

    int a {10};
    int b {20};

    Swapper swapper; // Create an instance of the Swapper class
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapper.swap_with_move(a, b); // Call swap_with_move method of Swapper object
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}


