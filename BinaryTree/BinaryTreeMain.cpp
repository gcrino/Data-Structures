#include <iostream>
#include "BinaryNode.h"

bool isEmpty(BinaryNode<int>*);
void printTree(BinaryNode<int>*);
BinaryNode<int>* add(BinaryNode<int>*, int);

int main() {
	
	BinaryNode<int>* root = nullptr;

	//BinaryNode<int>* root = new BinaryNode<int>(12, new BinaryNode<int>(5), new BinaryNode<int>(15));


	root = add(root, 10);
	root = add(root, 5);
	root = add(root, 15);
	
	
	printTree(root);




}

bool isEmpty(BinaryNode<int> * rt) {
	return rt == nullptr;		//return false if tree is empty
}

void printTree(BinaryNode<int>* rt) {
	
	if (!isEmpty(rt)) {
		printTree(rt->getLeftChildPtr());
		std::cout << rt->getValue() << " ";
		printTree(rt->getRightChildPtr());
	}

}

BinaryNode<int>* add(BinaryNode<int>* rt, int newEntry) {
	BinaryNode<int>* curr = rt;

	if (isEmpty(rt)) {
		//if tree is empty, update root
		rt = new BinaryNode<int>(newEntry);
		return rt;
	}
	else {
		//if tree has nodes

		//if newEntry is > curr's value
		if (newEntry >= curr->getValue()) {
			if (curr->getRightChildPtr() == nullptr) {
				//rightChildPtr is vacant, add new node
				curr->setRightChildPtr(new BinaryNode<int>(newEntry));
			}
			else {
				//already a node at right 
				add(curr->getRightChildPtr(), newEntry);	//recursive call
			}
		}

		//if newEntry is < curr's value
		else if (newEntry < curr->getValue()) {
			if (curr->getLeftChildPtr() == nullptr) {
				//leftChildPtr is vacant, add new node
				curr->setLeftChildPtr(new BinaryNode<int>(newEntry));
			}
			else {
				//already a node at left 
				add(curr->getLeftChildPtr(), newEntry);	//recursive call
			}
		}
		return rt;
	}
}