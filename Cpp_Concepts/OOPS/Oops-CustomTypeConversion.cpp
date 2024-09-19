/*
Custom Conversion Function:
The operator double() function serves as a custom conversion from the Temperature class to a double. 
It converts the temperature from Celsius to Fahrenheit.
Explicit Keyword: The explicit keyword is used for the custom conversion function to prevent implicit conversions. 
It ensures that the conversion is only performed when explicitly requested.
*/

#include <iostream>

class Temperature {
public:
    // Constructor to initialize temperature in Celsius
    Temperature(double celsius) : celsius(celsius) {}

    // Custom conversion to Fahrenheit
    explicit operator double() const {
        std::cout << "Custom conversion from Celsius to Fahrenheit" << std::endl;
        return celsius * 9 / 5 + 32;
    }

    // Getter function for Celsius temperature
    double get_celsius() const {
        return celsius;
    }

private:
    double celsius; // Temperature in Celsius
};

int main() {
    // Creating a Temperature object with 25 degrees Celsius
    Temperature tempCelsius(25);

    // Using the custom conversion to implicitly convert to Fahrenheit
    double tempFahrenheit = static_cast<double>(tempCelsius);

    // Accessing the original Celsius value using the getter function
    std::cout << "Temperature in Celsius: " << tempCelsius.get_celsius() << "°C" << std::endl;

    // Implicitly converted temperature in Fahrenheit
    std::cout << "Temperature in Fahrenheit: " << tempFahrenheit << "°F" << std::endl;

    return 0;
}
