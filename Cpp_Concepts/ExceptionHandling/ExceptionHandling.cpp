// Exception Handling 
#include <iostream>
#include <stdexcept>
#include <vector>

int safeDivide(int a, int b) {
    // Check for division by zero
    if (b == 0) {
        // Throw a logic_error if division by zero is detected
        throw std::logic_error("Cannot divide by zero!");
    }

    return a / b;
}

int main() {
    // (1) Try Catch Method
    try {
        int result = safeDivide(10,0); //function call

        // Output the result if division is successful
        std::cout << "Result of division: " << result << std::endl;

    } catch (const std::logic_error& ex) {
        // Catch block for std::logic_error (e.g., division by zero)
        std::cerr << "Error: " << ex.what() << std::endl;

    } catch (...) //Ellipsis catch all block - Catch-all block for unexpected errors ,it should be the last catch block
    {
        std::cerr << "An unexpected error occurred!" << std::endl;
    }

//    // (2) nothrow Method
//    //std::nothrow
//     for(size_t i{0} ; i < 100 ; ++i){
   
//         int * data = new(std::nothrow) int[1000000000];

//         if(data!=nullptr){
//             std::cout << "Data allocated" << std::endl;
//         }else{
//             std::cout << "Data allocation failed" << std::endl; //print large times but code don't crash
//         }
       
//     }

    std::cout<< "----------------------"<<std::endl;
    
    std::vector<int> numbers = {1,2,3,4,5};

    std::cout << "numbers[3] : " << numbers[3] << std::endl; // No bound check 
    std::cout << "numbers.at(3) : " << numbers.at(3) << std::endl; // Bound check 

    std::cout << "numbers[6] : " << numbers[6] << std::endl; // No bound check (if its out of bound,this will give unknown value or sometimes crash)
    //std::cout << "numbers.at(6) : " << numbers.at(6) << std::endl; // Error: Bound check (if its out of bound,this will 'throws expception', efficient for exception handling)


    std::cout << "Program ended" << std::endl;

    return 0;
}
