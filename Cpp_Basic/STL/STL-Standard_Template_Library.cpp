// Standard Template Library (STL)
// Documentation: https://en.cppreference.com/w/cpp

/*
The Standard Template Library (STL) is a collection of generic data structures and algorithms implemented in C++. 
It provides a set of common template classes and functions that enable programmers to write efficient, reusable, and platform-independent code for various tasks. 
The STL is part of the C++ Standard Library and is defined in the <algorithm>, <vector>, <list>, <map>, <set>, and other standard headers.
The key components of the STL include:
Containers:       These are generic classes that store collections of objects. 
                  Examples include vectors, lists, stacks, queues, maps, and sets.
Algorithms:       These are functions that perform operations on containers, such as searching, sorting, and modifying elements. 
                  Examples include std::sort, std::find, std::transform, and std::accumulate.
Iterators:        These are objects that provide a way to traverse the elements of a container sequentially. 
                  They act as pointers to elements within the container and allow algorithms to operate on containers independently of their underlying implementation.
Function objects: These are objects that behave like functions and can be passed to algorithms to customize their behavior. 
(Functors)        Functors can be implemented as classes with overloaded operator() or as lambda expressions.
*/

// Containers:
/*
Containers in the Standard Template Library (STL) are generic classes that store collections of objects. 
They provide a way to organize and manage data efficiently in C++ programs. 
some common containers in the STL:
1)Vector: Vectors are dynamic arrays that can resize themselves automatically when elements are added or removed. 
          They provide fast random access to elements and support dynamic memory allocation. Vectors are typically used when you need a resizable array-like container.
2)List:   Lists are doubly linked lists where each element (node) contains a value and pointers to the next and previous elements. 
          They provide efficient insertion and deletion operations at any position in the list. Lists are useful when you frequently need to insert or remove elements in the middle of the sequence.
3)Deque:  Deques (pronounced "deck") are double-ended queues that support insertion and deletion of elements at both ends. 
          They provide fast insertion and deletion at the beginning and end of the sequence, similar to vectors. Deques are useful when you need efficient insertion and deletion at both ends of the sequence.
4)Map:    Maps are associative containers that store key-value pairs. Each key in the map is unique, and the elements are sorted by key. 
          Maps provide fast lookup and retrieval of values based on their keys. They are commonly used for implementing associative arrays, dictionaries, and symbol tables.
5)Set:    Sets are containers that store unique elements in sorted order. They ensure that each element appears only once in the container and maintain their order based on comparison functions. 
          Sets are useful when you need to maintain a collection of unique elements and perform fast lookup operations.
*/

// Algorithms:
/*
Algorithms in the Standard Template Library (STL) are functions that perform operations on containers or sequences of elements. 
They provide a way to manipulate, search, and process data efficiently in C++ programs. 
some common algorithms in the STL:
1)Sorting:        Sorting algorithms arrange elements in a specified order, such as ascending or descending. 
                  The std::sort algorithm is commonly used to sort elements in a container, such as a vector or an array, based on a specified comparison criterion.
2)Searching:      Searching algorithms look for a specific value or pattern within a container. 
                  The std::find algorithm is used to search for a value within a range defined by iterators. 
                  It returns an iterator to the first occurrence of the value, or the end iterator if the value is not found.
3)Counting:       Counting algorithms count the occurrences of a value or satisfy a certain condition within a container. 
                  The std::count algorithm counts the number of occurrences of a specific value within a range defined by iterators.
4)Transformation: Transformation algorithms modify elements in a container according to a specified operation. 
                  The std::transform algorithm applies a unary or binary operation to each element in a range and stores the result in another container or modifies the original container in-place.
5)Accumulation:   Accumulation algorithms compute a cumulative result by applying a binary operation to the elements in a container. 
                  The std::accumulate algorithm sums up the values in a range, optionally with an initial value and a binary operation.
*/

// Iterators: 
/*
Iterators in the Standard Template Library (STL) are objects that provide a way to traverse the elements of a container sequentially. 
They act as pointers to elements within the container and allow you to access, modify, and iterate over the elements in a flexible and efficient manner. 
some common iterators in the STL:
1)Input         : Input iterators are used to read elements from a container sequentially. 
  Iterator        They support operations like dereferencing (*) to access the current element and incrementing (++) to move to the next element. 
                  Input iterators are typically used in algorithms that only need to read elements from a container, such as std::find or std::count.
2)Output        : Output iterators are used to write elements to a container sequentially. 
  Iterator        They support operations like dereferencing (*) to assign a value to the current element and incrementing (++) to move to the next element. 
                  Output iterators are commonly used in algorithms that need to write elements to a container, such as std::copy or std::fill.
3)Forward       : Forward iterators are similar to input iterators but offer additional capabilities. 
  Iterator        They support both reading and writing elements from and to a container. 
                  Forward iterators can be used in algorithms that require sequential access to elements, such as std::list or std::forward_list.
4)Bidirectional : Bidirectional iterators extend the capabilities of forward iterators by adding the ability to move backward through the elements of a container. 
  Iterator        They support decrementing (--) in addition to incrementing (++).
                  Bidirectional iterators are commonly used in algorithms that need to traverse containers in both directions, such as std::list or std::deque.
5)Random Access : Random access iterators provide the most powerful capabilities among iterators. 
  Iterator        They support random access to elements within a container using arithmetic operations like addition (+) and subtraction (-). 
                  Random access iterators allow efficient access to any element within the container and are commonly used in algorithms that require random access, such as std::vector or std::array.
6)Contiguous    : A contiguous iterator is an iterator type that can traverse elements of a container stored in contiguous memory locations. 
  iterator        It allows for efficient sequential access to elements, as elements are stored adjacently in memory. 
                  This makes it suitable for operations like pointer arithmetic and bulk memory operations.


Iterator types are hierarchical: a forward iterators is also an input iterator, a bidirectional iterator is also a forward iterator, a random access iterator is also a bidirectional iterator.
An algorithm that works for forward iterators, should also work with bidirectional iterators. Similarly, an algorithm that works with bidirectional iterators, should also work with random access iterators.

Input Iterator         - std::find()   
Output Iterator        - std::copy()   
Forward Iterator       - std::fill(), std::replace  
Bidirectional Iterator - std:reverse() 
Random Access Iterator - Std::sort()  

*/
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Topics:
/*
//Containers:
Documents: https://en.cppreference.com/w/cpp/container

-Containers store elements in different ways.
-The stl offers different containers for use in different scenarios to fit your particular use case in the best way possible.
-Some containers are good for some things and really bad at some other things.
-Choosing the right container for the job is a very strong skill.
-If you don't know beforehand which container to choose, std:: vector is a good starting point.
STL Containers :

• Sequence containers - elements stored in a sequence
  - std::deque
  - std::forward_list
  - std::list
  - std::véctor - very fast lookup by index with []
  - std::array

• Associative containers - elements stored as key,value
  - std::set - very fast searches for elements
  - std::map
  - std::multiset & std::multimap
  - std::unordered_set & std::unordered_map

• Container adaptors - specializations of sequence container
  - std::stack
  - std::queue
  - std::priority_queue

//Container adaptors
-Container adaptors are components provided by the C++ Standard Library that wrap around existing container types and provide a different interface or behavior. 
-They allow programmers to use existing containers in a modified or specialized way without altering the underlying container itself. 
-They are not containers themselves They merely modify the interface provided by low level sequence containers like vector list and deque 
 to provide the interfaces needed to make our container work like a stack, work like a queue or priority queue.
There are three main container adaptors in C++:
1)std::stack:
Implements a stack data structure, which follows the Last In, First Out (LIFO) principle.
It is built on top of an underlying container (by default, std::deque).
Supports push, pop, top, and empty operations.
2)std::queue:
Implements a queue data structure, which follows the First In, First Out (FIFO) principle.
It is built on top of an underlying container (by default, std::deque).
Supports push, pop, front, back, and empty operations.
3)std::priority_queue:
Implements a priority queue data structure, where elements are dequeued based on priority.
It is built on top of an underlying container (by default, std::vector).
Supports push, pop, top, and empty operations.
The elements are ordered according to a comparison function or operator.
*/

/*
// Algorithms:
In modern C++, STL algorithms are typically categorized into two main types: legacy and range-based algorithms.

1)Legacy algorithms: 
These are the traditional algorithms provided by the C++ Standard Library. 
They typically operate on iterators and follow the conventional algorithm naming convention, such as std::find, std::sort, std::transform, etc. 
Legacy algorithms are designed to work with iterators and are inherited from the early days of C++.

2)Range-based algorithms: 
These algorithms are introduced in C++11 and later versions. They are more modern and are designed to work with range-based syntax, which simplifies code and improves readability. 
Range-based algorithms take advantage of the range-based for loop and other features introduced in modern C++. Examples include std::ranges::find, std::ranges::sort, std::ranges::transform, etc.

Range-based algorithms offer several advantages over legacy algorithms:
They often provide more concise and expressive syntax, leading to cleaner code.
They are more composable and work well with other range-based utilities introduced in C++11, such as range adaptors and views.
They are part of the C++20 standard and beyond, providing access to new features and improvements introduced in later versions of the language.

*/

/*
Iterators: 
1)Input iterators :
  - Used to read stuff from containers
  - single pass from begining to end.
  - Some perators :
      * operator ++
      * operator * (read)
      * operator -> (read)
      * operator==
      * operator!=
2)Output iterators
  - Used to write stuff into containers
  - single pass from beginning to end
  - Some operators :
      * operator ++
      * operator * (write)
      * operator -> (write)
      * operator==
      * operator!=
3)Forward iterators
  - Combination of input and output iterators
  - Can't read backwards though, only forward
  - multipass
  - Some perators :
      * operator ++
      * operator * (read,write)
      * operator -> (read,write)
      * operator==
      * operator!=
4)Bidirectional iterators
  - Like input iterators, used to read stuff. But can read forward and backwards
  - Single pass
  - Some operators :
      * operator ++
      * operator --
      * operator * (read)
      * operator -> (read)
      * operator==
      * operator!=
5)Random access iterators
  - Can read/write randomly from/to any index in the container
  - multipass
  - Some peroperator 1
      * operator ++
      * operator * (read,write)
      * operator -> (read,write)
      * operator==
      * operator!=
6)contiguous iterator
  - represents a random access iterator over a sequence of elements where each element is stored contiguously, in exactly the same way as an array.
    Which means that it is possible, given a pointer to an value_type from an iterator, to perform pointer arithmetic on that pointer,

*/