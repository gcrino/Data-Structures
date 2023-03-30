#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include "PriorityQueueInterface.h"
#include "Node (1).h"
#include <iostream>


template <class itemType>
class LL_PriorityQueue : public PriorityQueueInterface<itemType> {
	Node<itemType>* root;
	Node<itemType>* lastnode;
	

public: 
	LL_PriorityQueue();
	bool isEmpty() const = 0;
	bool enqueue(const itemType& newEntry) = 0;
	bool dequeue() = 0;
	itemType peek() const = 0;


};

#include "PriorityQueueImpl.cpp"


#endif
