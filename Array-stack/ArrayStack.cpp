#ifndef STACK_IMPL
#define STACK_IMPL

#define MAX 10
#include <iostream>
#include "ArrayStack.h"

template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : TOS(-1) {
	for (int i = o; i < MAX; i++) {
		stack[i] = 0;
	}
	std::cout << "Stack created...";
}

template <class ItemType>
ArrayStack<ItemType>::bool isEmpty() const {
	if (stack[0] == -1) {
		return false
	}
}

template <class ItemType>
ArrayStack<ItemType>::bool push(const ItemType& newEntry) {
	if (TOS < MAX - 1) {
		stack[++TOS] = newEntry;
		return true;
	}
	return false;
}

template <class ItemType>
ArrayStack<ItemType>::bool pop() {

}

template <class ItemType>
ArrayStack<ItemType>::ItemType peek() const {

}
#endif