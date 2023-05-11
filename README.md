PriorityQueue

The PriorityQueue is a C++ implementation of a priority queue based on a linked list. It allows elements to be stored and retrieved based on their priority. The priority is determined using a user-defined comparison function.

Motivation

The exercise's goal is to learn how to implement template classes, functors and fucntion in cpp.

Features

    Insert elements into the priority queue while maintaining their order based on priority.
    Retrieve the element with the highest priority from the priority queue.
    Exception handling for empty priority queue.

Customizing Priority Comparison

By default, the priority comparison is performed using the MyComparator struct, which subtracts the second element from the first element. However, you can customize the comparison logic by providing your own comparison function or functor. Simply modify the MyComparator struct or provide your own comparison struct and pass it as a template argument to the PriorityQueue class.

Error Handling

If the priority queue is empty and you try to retrieve an element using poll, a std::runtime_error exception will be thrown. Make sure to handle this exception appropriately in your code.