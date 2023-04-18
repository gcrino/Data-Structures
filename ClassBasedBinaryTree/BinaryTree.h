#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include "BinaryNode.h"

class BinaryTree {
	BinaryNode<int>* root;
	bool _add(BinaryNode<int>*, int);
public:
	BinaryTree() : root(nullptr) {}
	BinaryTree(int newEntry) : root(new BinaryNode<int>(newEntry)) {}
	
	BinaryNode<int>* getRoot() const;
	bool isEmpty(BinaryNode<int>* );	//passes root to look at subtrees
	bool add(int);
	void printTree(BinaryNode<int>*);

};
//write class implementation here

BinaryNode<int>* BinaryTree::getRoot() const {
	return root;
}


bool BinaryTree::isEmpty(BinaryNode<int>* rt) {
	return rt == nullptr;
}

bool BinaryTree::_add(BinaryNode<int>* rt, int newEntry) {	//helper function
	if (isEmpty(rt)==true) {
		rt = new BinaryNode<int>(newEntry);
		return true;
	}
	//if new entry is less than value, go left
		//call empty/recursive call, looking for subtrees
	//else 
		//go right, do the same on right side

	else 
		if (newEntry < rt->getValue()) {
			if (rt->getLeftChildPtr() == nullptr) {
				rt->setLeftChildPtr(new BinaryNode<int>(newEntry));
			}
			else {
				_add(rt->getLeftChildPtr(), newEntry);
			}
		}
		if (newEntry >= rt->getValue()) {
			if (rt->getRightChildPtr() == nullptr) {
				rt->setRightChildPtr(new BinaryNode<int>(newEntry));
			}
			else {
				_add(rt->getRightChildPtr(), newEntry);
			}
		}

		return true;

}


bool BinaryTree::add(int newEntry) {
	_add(getRoot(), newEntry);
}

void BinaryTree::printTree(BinaryNode<int>* rt) {
	if (rt != nullptr) {
		printTree(rt->getLeftChildPtr());
		std::cout << rt->getValue() << " ";
		printTree(rt->getRightChildPtr());
	}
}



#endif