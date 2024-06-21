// projections
/*
Projections in C++20 enable algorithms to work on specific element properties or components within a range. 
They're utilized for extracting or manipulating attributes during operations such as sorting, searching, or data transformation. 
A projection, essentially a function object, extracts or transforms a specific value from each range or container element.
It is commonly used in algorithms that perform operations on ranges, such as std::transform and std::sort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Define a Person class with name and age attributes
class Person {
private:
    std::string name;
    int age;
    
public:
    // Constructor
    Person() = default;
    Person(const std::string& n, int a) : name(n), age(a) {}
    
    // Getter for name attribute
    std::string getName() const {
        return name;
    }
    
    // Getter for age attribute
    int getAge() const {
        return age;
    }
};

// Comparison function to compare two Person objects by age
bool compareByAge(const Person& p1, const Person& p2) {
    return p1.getAge() < p2.getAge(); //ascending order wise age
    // return p1.getAge() > p2.getAge(); //decending order wise age

}

// Comparison function to compare two Person objects by name
bool compareByName(const Person& p1, const Person& p2) {
    return p1.getName() < p2.getName();
}

int main() {
    // Create a vector of Person objects
    std::vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"David", 20}, {"Charlie", 35}};

    // Print the collection
    std::cout << "\nCollection:" << std::endl;
    std::cout<< "Age - Name"<<std::endl;
    for(const auto& person : people) {
        std::cout << person.getAge() << "  - " << person.getName() << std::endl;
    }

    std::cout<<"-------------------"<<std::endl;
    
    // Sort the collection using std::ranges::sort with projection

    std::ranges::sort(people, compareByAge);
    
    // Print the sorted collection by age
    std::cout << "\nSorted Collection by Age:" << std::endl;
    std::cout<< "Age - Name"<<std::endl;
    for(const auto& person : people) {
        std::cout << person.getAge() << "  - " << person.getName() << std::endl;
    }

    std::cout<<"-------------------"<<std::endl;

    // Sort the collection using std::ranges::sort with projection

    std::ranges::sort(people, compareByName);
    
    // Print the sorted collection by name
    std::cout << "\nSorted Collection by Name:" << std::endl;
    std::cout<< "Age - Name"<<std::endl;
    for(const auto& person : people) {
        std::cout << person.getAge() << "  - " << person.getName() << std::endl;
    }

    std::cout<<"-------------------"<<std::endl;

    //Projections with for_each
    std::cout << std::endl;
    std::cout << "Projections with for_each : " << std::endl;
    
	  auto print = [](const auto& n) { std::cout << " " << n; };
	  using pair = std::pair<int, std::string>; 
    std::vector<pair> pairs{{1,"one"}, {2,"two"}, {3,"tree"}};
 
    std::cout << "project the pair::first: ";
    std::ranges::for_each(pairs, print, [](const pair& p) { return p.first; });
    std::cout << std::endl;

    std::cout << "project the pair::first: ";
    std::ranges::for_each(pairs, print, &pair::first);
    std::cout << std::endl;

    std::cout << "project the pair::second: ";
    std::ranges::for_each(pairs, print, [](const pair& p) { return p.second; });
    std::cout << std::endl;
    
    return 0;
}



/*
projections are used in conjunction with std::ranges::sort to specify a transformation of the elements being sorted. 
Projections allow us to sort a collection of complex objects by a specific attribute or key, rather than the objects themselves.

projections are used in the code:
// std::ranges::sort(people, [](const Person& p1, const Person& p2) { return p1.age < p2.age; });

In this line, the lambda function passed to std::ranges::sort serves as a projection. 
It extracts the age attribute from each Person object and compares them using the < operator. 
This lambda function effectively transforms each Person object into its age value, enabling the sort algorithm to order the people vector based on age.

Projections are advantageous because they decouple the comparison logic from the sorting algorithm itself. 
Instead of modifying the objects or defining complex comparison functions, we can provide a simple projection that extracts the relevant attribute for comparison. 
This simplifies the sorting process and makes the code more readable and maintainable.

*/
