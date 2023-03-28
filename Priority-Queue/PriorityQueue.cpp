#ifndef PRIORITY_QUEUE_IMPL
#define PRIORITY_QUEUE_IMPL

#include "PriorityQueue.h"
#include <iostream>

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
	if (size == 0) {
		return true;
	}
	else
		return false;
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
	//queue new entry, sorted
	if (!isEmpty()) {
		for (int i = 0; i < size; i++)					//go through array
			if (Array[i] < newEntry) {		//element < newEntry
				size++;								
				for (int j = i; j<=size; j++) {			//moving elements 
					Array[j] = Array[j + 1];
				}
				Array[i] = newEntry;
			}
	}
	else
		Array[0] = newEntry;


}

template<class ItemType>
bool PriorityQueue<ItemType>::dequeue() {
	if (!isEmpty()) {
		size--;
		std::cout << "Item was dequeued...\n";
		return true;
	}
		return false;	
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() const {
	if (isEmpty()) {
		return Array[size - 1];
	}
}
template<class ItemType>
void  PriorityQueue<ItemType>::printPriorityQueue() {
	std::cout << "Printing...\n";
	for (int i = 0; i < size; i++) {
		std::cout << Array[i] << " ";
	}
}

#endif 


