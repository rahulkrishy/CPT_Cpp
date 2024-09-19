// Custom Termination Handler in Exception Handling

// Concepts:
// - Custom termination handler function: A function that is called when the program is about to terminate unexpectedly.
// - std::set_terminate: Function used to set a custom termination handler function.
// - std::terminate: Function called when an uncaught exception is thrown or some other terminating condition arises.

#include <iostream>
#include <exception>
#include <chrono>
#include <thread>

// Custom termination function
void our_terminate_function() {
    // Displaying a message indicating that the custom terminate function is called
    std::cout << "Our custom terminate function called" << std::endl;
    std::cout << "Program will terminate in 10s ..." << std::endl;

    // Delaying the program termination by 10 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    // Forcing program termination
    std::abort();
}

int main() {
    // Setting the custom termination function
    std::set_terminate(&our_terminate_function);

    // Throwing an uncaught exception
    throw 1;
   
    return 0;
}

// The code will arise runtime error stating at std::abort(), enter ctrl+c to end task