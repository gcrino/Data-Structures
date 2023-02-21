#define MAX 10
#include <iostream>
#include "StackInterface.h"


template <class ItemType>
class ArrayStack : public StackInterface<ItemType> {
private: 
	ItemType stack[MAX];
	int TOS;
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const;
};

#include "ArrayStack.cpp"
#endif