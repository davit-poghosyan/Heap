#include <iostream>
#include <vector>
#include <initializer_list>

class Heap
{
    private:
        int m_size;
        std::vector<int> arr;
    public:
        Heap();
        Heap(std::initializer_list<int>);
        Heap(std::vector<int>);
        virtual ~Heap() = default;

        std::vector<int> getArr() const;
        int getSize() const;

        int left(int);
        int right(int);
        int parent(int);

        void heapifyDown(int);
        void heapifyUp(int);
        void buildMaxHeap();



        void insert(int);
        void remove();
        void increaseKey(int pos, int newVal);

};

Heap::Heap() : m_size{} {}

Heap::Heap(std::initializer_list<int> list) 
{
    for (auto it : list) {
        arr.push_back(it);
    }
    m_size = list.size();
}

Heap::Heap(std::vector<int> vec) 
{
    arr = vec;
    m_size = arr.size();
}


std::vector<int> Heap::getArr() const
{
    return arr;
}

int Heap::getSize() const
{
    return m_size;
}


int Heap::left(int i) 
{
    return (i*2) + 1;
}

int Heap::right(int i)
{
    return (i*2) + 2;
}

int Heap::parent(int i)
{
    return (i - 1) / 2;
}

void Heap::heapifyDown(int i) 
{
    int left = this->left(i);
    int right = this->right(i);
    int largest = i;

    if (left < m_size && arr[left] > arr[i]) {
        largest = left;
    }

    if (right < m_size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[largest], arr[i]);
        heapifyDown(largest);
    }
}

void Heap::heapifyUp(int i) 
{
    int parent = this->parent(i);
    int largest = parent;
    if (parent >= 0 && arr[parent] < arr[i]) {
        largest = i;
        std::swap(arr[largest], arr[parent]);
    }

    if (largest != parent) {
        heapifyUp(parent);
    }
}

void Heap::buildMaxHeap() 
{
    for (int i = arr.size()/2 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void Heap::insert(int val) 
{
    arr.push_back(val);
    ++m_size;
    heapifyUp(m_size - 1);    
}


void Heap::remove()
{
    if (m_size < 1) {
        std::cout << "the heap is empty\n";
        //exit(0);
        return;
    }
    std::swap(arr[0], arr[m_size - 1]);
    --m_size;

    heapifyDown(0);
}


void Heap::increaseKey(int pos, int newVal)
{
    if (arr[pos] > newVal) {
        std::cout << "new val is smaller than present val\n";
        return;
    }
    arr[pos] = newVal;
    int i = pos;

    while (i != 0  && arr[parent(i) < arr[i]]) {
        std::swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}