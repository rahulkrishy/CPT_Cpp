// std::array
/*
-std::array is a fixed-size array container defined in the C++ Standard Library. 
-Unlike std::vector, the size of std::array is fixed at compile time.
-Elements are stored contiguously in memory
-It provides similar functionality to built-in arrays but with additional features such as bounds checking and support for iterators.
-Arrays are accessed using zero-based indexing, just like built-in arrays.
-Good if you want to enforce that your collections should be of a given size
-Good replacement for the raw arrays, as they have their limitations, like not being able to cross assign them.
*/

#include <iostream>
#include <array>


class Item{
public : 
    Item() :m_var(0){
        std::cout << " Item default constructor called" << std::endl;
    }
    Item(int var) : m_var(var){
       // std::cout << "Item constructor called for: " << m_var << std::endl;
    }
    Item(int var1, int var2) : m_var( var1 * var2)
    {
        
    }
    
    Item(const Item& source) : m_var{source.m_var}{
        //std::cout << "Item copy constructor called for :" << m_var << std::endl;
    }
    
    int get() const{
        return m_var;
    }
private : 
    int m_var{0};
};

template <typename T>
void print_collection(const T& collection) {
    auto it = collection.begin(); // Get an iterator to the beginning of the collection
    std::cout << " Collection ["; // Print the start of the collection

    while (it != collection.end()) { // Loop until reaching the end of the collection
        std::cout << " "; // Print a space before each element

        // Check if the value type of the collection is Item
        // (std::is_same_v is a C++ template variable defined in the <type_traits> header of the C++ Standard Library. It's part of the type traits utilities and is used to determine whether two types are the same.)
        // (// T::value_type is a member type alias typically defined within container types. It represents the type of elements stored in the container T.)
        if constexpr (std::is_same_v<typename T::value_type, Item>) {
            // If the value type is Item, print it in a specific format
            std::cout << "Item [ value : " << it->get() << "]";        //here it pointer pointing to the Item object ('*it' would give us the actual Item object itself, not its value.), so item.get() is used to retrieve the value of each Item object in the collection and print it
        } else {
            // If the value type is not Item, print it directly
            std::cout << *it;
        }

        ++it; // Move to the next element in the collection
    }

    std::cout << "]" << std::endl; // Print the end of the collection
}


// Function template to print elements of raw array
template <typename T>
void print_raw_array(const T* p, std::size_t size) {
    std::cout << "data = ";
    // Iterate over the elements of the raw array and print them
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}

// Function template to print elements of std::array
template <typename T, size_t Size>
void print_array(const std::array<T, Size>& arr) {
    // Iterate over the elements of the array and print them
    for (size_t i{}; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



int main(){

   //Code1 : Collection creation and element access
    std::cout << std::endl;
    std::cout << "Collection creation and element access : " << std::endl;

    std::array<int,10> numbers{1,2,3,4,5,6,7,8,9,10};
    //If you put in less than 10, the rest is auto filled with 0 (default constructed value)
    //If you put in more than 10, you get a compiler error. Can't go over that
    
    std::cout << " numbers : " ;
    print_collection(numbers);

    // size
    std::cout << "Size: " << numbers.size() << std::endl; // Output: Size: 10

    // Iterating over elements
    std::cout << "Elements:";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    
    std::cout << " Element at index 3 : " << numbers.at(3) << std::endl; // Bound checks
    std::cout << " Element at index 3 : " << numbers[3] << std::endl; // No bound checks
    
    //Bound check : at() throws an out of range exception when you try to access
    // beyond the legal bounds of the array
    try{
    std::cout << " Element at index 20 (at()) : "
                << numbers.at(20) << std::endl;// Throws out of range expception
    }
    catch(std::exception& ex){
        std::cout << " Access failed. Reason : " << ex.what() << std::endl;
    }
    
    //Bound check : [] does no bound check. If you access beyond the legal bounds
    // you get undefined behavior
    std::cout << "Element at index 20 ([]) : "
                << numbers[20] << std::endl;// Undefined behavior : Junk, Crash, anything can happen here
     
    //Get the front element
    std::cout << " numbers front : " << numbers.front() << std::endl;
    //Get the back element 
    std::cout << " numbers back : " << numbers.back() << std::endl;
    
    //Front and back return references, we can even use them to modify data. Right ? 
    numbers.front() = 22;
    numbers.back()  = 33;
    
    std::cout << " numbers front : "  << numbers.front() << std::endl;
    std::cout << " numbers back : " << numbers.back() << std::endl;
    
    //The data method
    int raw_array[] {4,5,6,7,8,9};
    std::cout << " Showing raw array data : " << std::endl;
    print_raw_array(raw_array,6);
    
    std::cout << " Showing numbers.data as a raw array : " << std::endl;
    print_raw_array(numbers.data(),numbers.size());

    // Creating and initializing std::array objects
    std::array<int, 3> int_array1;  // Will contain junk by default
    std::array<int, 3> int_array2{1, 2};  // Will contain 1, 2, 0
    std::array<int, 3> int_array3{};  // Will contain 0, 0, 0
    std::array int_array4{1, 2};  // Compiler will deduce std::array<int, 2>

    // Printing the contents of std::array objects
    std::cout << "int_array1 : ";
    print_array(int_array1);

    std::cout << "int_array2 : ";
    print_array(int_array2);

    std::cout << "int_array3 : ";
    print_array(int_array3);

    std::cout << "int_array4 : ";
    print_array(int_array4);
    
    
    std::cout << "-----------------------" << std::endl;
    
    
    //Code2 : Iterators
    std::cout << std::endl;
    std::cout << "Iterators : " << std::endl;

    auto it = numbers.begin();
    
    std::cout << " std::array(with iterators) : [ ";
    while(it!=numbers.end()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << " ]" << std::endl;
    
    //Reverse traversal with rbegin and rend
    auto it_reverse = numbers.rbegin(); // non const iterator
    
    std::cout << " std::array(Reverse traversal with iterators) : [ ";
    while(it_reverse!=numbers.rend()){
        std::cout << " " << *it_reverse ;
        ++it_reverse; // Increments towards the first element of the array.
    }
    std::cout << " ]" << std::endl;    
    
    std::cout << "-----------------------" << std::endl;
    
    
    //Code3 : Capacity
    std::cout << std::endl;
    std::cout << "capacity : " << std::endl;
    std::cout << " numbers size : " << numbers.size() << std::endl;
    std::cout << " numbers max_size : " << numbers.max_size() << std::endl;
    std::cout << std::boolalpha; // Force output of bool as true or false instead of 1 or 0
    std::cout << " numbers is empty : " << numbers.empty() << std::endl;
    //std::cout << "numbers capacity : " << numbers.capacity() << std::endl;//No capacity method
    
    std::cout << "-----------------------" << std::endl;
    
    
    //Code4 : Operations
    //Filling
    std::cout << "filling : " << std::endl;
    std::cout << " numbers : " ;
    print_collection(numbers);
    numbers.fill(1000);
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    
    
   
    //Swapping : arrays must be of same size and contain the same type. 
    //otherwise they'll be different types and you can't cross assign different types.
    std::cout << std::endl;
    std::cout << "Swapping : " << std::endl;
    std::array<int,10> other_numbers {5,5,5,5,5,5,5,5,5,5};
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    //swap
    numbers.swap(other_numbers);
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    
    
    //Code5 : Can assign arrays to each other
    std::cout << std::endl;
    std::cout << "Assigning arrays to each other :" << std::endl;
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    numbers = other_numbers; // Calls the copy assignment operator of std::array
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    //This isn't possible with raw arrays.
    /*
    int int_arr1[] {1,2,3};
    int int_arr2[] {4,5,6};
    int_arr2 = int_arr1; // Compiler error : invalid array assignment
    */
    
    
    //Code6 : std::arrays for custom objects
    std::cout << std::endl;
    std::cout << "Storing custom objects in std::array : " << std::endl;
    
    std::array<Item,5> items = {};
    std::cout << " default initialized items : " << std::endl;
    
    std::cout << " items : " ;
    print_collection(items);
    
    items.fill(Item(5));
    
    std::cout << " items : " ;
    print_collection(items);
    
  
  
    return 0;
}