#include <iostream>
#include "ArrayStack.h"

int main() {
	ArrayStack<int>sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);
	sta.push(5);
	sta.push(6);
	//sta.pop();

	//if stack is not empty, peek

	if (!sta.isEmpty())
		std::cout << "peeked value: " << sta.peek() << "\n";
}