#include "heap.h"

void heapSort(std::vector<int>& vec)
{
    Heap heap(vec);
    heap.buildMaxHeap();
    while (heap.getSize() != 0) {
        heap.remove();
    }
    vec = heap.getArr();
}