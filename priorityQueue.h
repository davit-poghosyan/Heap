#include "heap.h"
#include <initializer_list>


class PriorityQueue : Heap
{
public:
    PriorityQueue();
    PriorityQueue(std::vector<int>&);
    PriorityQueue(std::initializer_list<int>);

    void push(int);
    void pop();
    int top() const;
    int size() const;
};

PriorityQueue::PriorityQueue() : Heap() {}

PriorityQueue::PriorityQueue(std::vector<int>& vec) : Heap(vec) {}

PriorityQueue::PriorityQueue(std::initializer_list<int> list) : Heap(list) {}

void PriorityQueue::push(int val)
{
    insert(val);
}

void PriorityQueue::pop()
{
    remove();
}

int PriorityQueue::top() const 
{
    return getArr()[0];
}

int PriorityQueue::size() const
{
    return getSize();
}