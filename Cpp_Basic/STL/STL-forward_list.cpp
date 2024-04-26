// std::forward_list
/*
-std::forward_list is a container in the C++ Standard Library that implements a singly linked list in memory. (item1 --> item --> item --› item)
-Unlike std::list, which is a doubly linked list, std::forward_list stores its elements in a linear sequence and provides constant time insertion and deletion of elements at the beginning of the list.
-It does not support bidirectional iteration, each node only has a pointer to the next element.
-Elements may be stored non contiguously in memory. It is said that the memory locality of forward_list is very poor.
-Poor memory locality makes things hard for the CPU optimizations when your list is being traversed.
-forward_list doesn't provide random access operators like [].
-forward_list only has forward iterators and doesn't have reverse iterators.
-The reason is because we only have pointers to the next element and not the previous element, so we can really move forward and not backwards.
-To access a given item in the list, you have to perform a linear search from the beginning.
-Once you are at the correct location in the list however, inserting and removing is very fast. It's just a matter of rewiring the pointers.
-Because of their downsides :
• lack of operator[] and other random access operators
• lack of memory locality
forward lists should be avoided. std::vector will almost always be a better fit.

// Don't forget that internally everything is going to be stored non-continuously.
// And the way this container is going to work is through a bunch of pointers that go from one elements to another in a forward way in our list.
*/

#include <iostream>
#include <forward_list>
#include <algorithm> // Include the algorithm library for std::find

template <typename T>
void print_collection(const T& collection){
    
    auto it = collection.begin();
    
    std::cout << " Collection [";
    while(it != collection.end()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "]" << std::endl;
}



int main(){

    std::forward_list<int> numbers = {100,2,3,4,5};
    print_collection(numbers);
    
    //Code1 : Element access
    std::cout << " front element : " << numbers.front() << std::endl;


    //Modifiers
    
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "modifiers : " << std::endl;
    
    //Clear
    std::cout << std::endl;
    std::cout << "clear :" << std::endl;
    print_collection(numbers);
    
    numbers.clear();
    
    print_collection(numbers);
    std::cout << std::boolalpha;


    //Insert after
    std::cout << std::endl;
    std::cout << "insert_after : " << std::endl;
    numbers = {11,12,13,14,15}; 
    
    print_collection(numbers);
    auto it_insert = numbers.before_begin(); //Points before the first element
    
    numbers.insert_after(it_insert,333); //so its insert in first element
    
    print_collection(numbers);


    //Emplace after : create in place after an iterator
    std::cout << std::endl;
    std::cout << "emplace_after : " << std::endl;
    
    print_collection(numbers);
    
    it_insert = numbers.before_begin();
    
    numbers.emplace_after(it_insert,444);
    
    print_collection(numbers);


    //Erase_after
    std::cout << std::endl;
    std::cout << "erase_after : " << std::endl;
    
    print_collection(numbers);
    
    auto it_erase = std::find(numbers.begin(),numbers.end(),13);
    
    if(it_erase!= numbers.end()){
        std::cout << " Found 13 !" << std::endl;
    }else{
        std::cout << " Couldn't find 13 !" << std::endl;
    }

    //Erase the 14
    // now 'it_erase' is points to 13, so 'erase_after' will erase next 14
    numbers.erase_after(it_erase);
    
    print_collection(numbers);


    //pop_front
    std::cout << std::endl;
    std::cout << "pop_front : " << std::endl;
    
    print_collection(numbers);
    
    numbers.pop_front();
    
    print_collection(numbers);


    //resize : up or down
    std::cout << std::endl;
    std::cout << "resize : " << std::endl;
    
    print_collection(numbers);
    
    numbers.resize(10);
    
    print_collection(numbers);
    
    numbers.resize(3); // When you resize down, the elements are lost for good.
                        // if you resize up again,you won't get them back.
    
    print_collection(numbers);
    
    numbers.resize(10);
    
    print_collection(numbers);


   
    //swap
    std::cout << std::endl;
    std::cout << "swap : " << std::endl;
    
    std::forward_list<int> other_numbers {200,400,600};
    
    std::cout << " numbers : ";
    print_collection(numbers);
    
    std::cout << " other_numbers :";
    print_collection(other_numbers);
    
    
    numbers.swap(other_numbers);
    
    std::cout << " numbers : ";
    print_collection(numbers);
    
    std::cout << " other_numbers :";
    print_collection(other_numbers);

    //Other operations
    std::cout << std::endl;
    std::cout << "merge : " << std::endl;
    
    std::forward_list<int> numbers1 {1,5,6};
    std::forward_list<int> numbers2 {9,2,4};
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);

    //merge
    numbers1.merge(numbers2); //after merge number2 will be empty
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);


    //splice_after : moving a range of elements from one container to another
    std::cout << std::endl;
    std::cout << "splice_after : " << std::endl;
    
    numbers1 = {1,5,6,8,3};
    numbers2 = {9,2,4,7,13,11,17};
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);

    numbers1.splice_after(numbers1.before_begin(),numbers2,numbers2.before_begin(),numbers2.cend());
    
    std::cout << " numbers1 : " ;
    print_collection(numbers1);
    
    std::cout << " numbers2 : ";
    print_collection(numbers2);

    //Remove
    std::cout << std::endl;
    std::cout << "remove : " << std::endl;
    
    numbers = { 1,100,2,3,10,1,11,-1,12 };
    
    print_collection(numbers);
 
    numbers.remove(1); // remove both elements equal to 1, (it look for value, not index) 
    numbers.remove(100); //remove value 100

    print_collection(numbers);

    //Remove predicate
    numbers.remove_if([](int n){ return n > 10; }); //remove all the elements if > than 10
    
    print_collection(numbers);


    //reverse
    std::cout << std::endl;
    std::cout << "reverse : " << std::endl;
    
    numbers = { 1,100,2,3,10,1,11,-1,12 };
    
    print_collection(numbers);
    
    numbers.reverse();
    
    print_collection(numbers);


    //Unique : Removes only contiguous duplicates (Note: to reomove all non contiguous duplicates,first use sort and the use unique)
    //Removes duplicated 100 and 11, but doesn't remove 1
    std::cout << std::endl;
    std::cout << "unique : " << std::endl;
    
    numbers = { 1,100,100,2,3,10,1,11,11,-1,12,10,1 };
    
    print_collection(numbers);
    
    numbers.unique();
    
    print_collection(numbers);


    //Sort
    std::cout << std::endl;
    std::cout << "sort : " << std::endl;
    
    print_collection(numbers);
    
    numbers.sort();
    
    print_collection(numbers);

    //If we want to remove all duplicates, we can first sort and then
    //remove duplicates.
    
    numbers.unique();
    
    print_collection(numbers);
   
    return 0;
}