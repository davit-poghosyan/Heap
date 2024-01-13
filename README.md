# Heap

This repository contains a C++ implementation of a Heap data structure, along with a HeapSort algorithm and a PriorityQueue class built on top of the Heap.
Contents:

    heap.h: Header file containing the declaration and implementation of the Heap class. The Heap class provides functionalities like insertion, removal, heapification, and building a max heap.

    heapSort.h: Header file containing the heapSort function, which utilizes the Heap class to perform in-place heap sort on a vector of integers.

    priorityQueue.h: Header file containing the declaration and implementation of the PriorityQueue class, which is derived from the Heap class. The PriorityQueue class serves as a priority queue, allowing elements with higher priority values to be accessed first.

## Usage:

 Heap Class: The Heap class can be used to create a generic heap and perform operations such as insertion, removal, and heap sort.

    

    Heap myHeap;  // Create an empty heap
    myHeap.insert(10);
    myHeap.insert(5);
    myHeap.remove();

HeapSort Function: The heapSort function can be used to sort a vector of integers using the heap sort algorithm.



    std::vector<int> myVector = {4, 2, 8, 1, 6};
    heapSort(myVector);

PriorityQueue Class: The PriorityQueue class is a subclass of the Heap class and provides a convenient way to use a heap as a priority queue.


    
    PriorityQueue myPriorityQueue;
    myPriorityQueue.push(15);
    myPriorityQueue.push(8);
    myPriorityQueue.pop();
    int highestPriority = myPriorityQueue.top();
