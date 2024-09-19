// Oops - Encapsulation
/*
-Encapsulation is one of the fundamental principles of object-oriented programming (OOP). 
-It refers to the bundling of data (attributes) and methods (functions) that operate on the data into a single unit called a class. 
-Encapsulation allows for the hiding of the internal state of an object and restricting access to it from outside the class. 
-This helps in achieving data abstraction and information hiding, which are essential for building robust and maintainable software systems.
*/

#include <iostream>
#include <string>

class Car {
private:
    std::string model;
    int year;
    double price;

public:
    // Constructor to initialize the object
    Car(const std::string& m, int y, double p) : model(m), year(y), price(p) {}

    // Getter methods to access private data members
    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    // Setter methods to modify private data members
    void setModel(const std::string& m) {
        model = m;
    }

    void setYear(int y) {
        year = y;
    }

    void setPrice(double p) {
        price = p;
    }
};

int main() {
    // Create an object of the Car class
    Car myCar("Toyota Camry", 2022, 25000.0);

    // Accessing data members using getter methods
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;
    std::cout << "Price: $" << myCar.getPrice() << std::endl;

    // Modifying data members using setter methods
    myCar.setModel("Honda Civic");
    myCar.setYear(2020);
    myCar.setPrice(20000.0);

    std::cout << "\nModified Details:" << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;
    std::cout << "Price: $" << myCar.getPrice() << std::endl;

    return 0;
}


/*
The Car class encapsulates the data members (model, year, and price) and provides public methods (getModel(), getYear(), getPrice(), setModel(), setYear(), setPrice()) to access and modify these attributes.
The data members are declared as private, preventing direct access from outside the class. They can only be accessed or modified using the public member functions.
The main() function demonstrates how to create an object of the Car class, access its attributes, and modify them using the provided getter and setter methods.
Encapsulation helps in achieving data hiding, abstraction, and modularity, making the code easier to understand, maintain, and extend.
*/
