#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include <iostream>

template<class ItemType>
class PriorityQueue : public PriorityQueueInterface<ItemType> 
{
    int size;
    ItemType Array[size];

public:
   
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peek() const;
    void printPriorityQueue();
}; 




#endif 
