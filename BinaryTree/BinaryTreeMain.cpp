#include <iostream>
#include "BinaryNode.h"

bool isEmpty(BinaryNode<int>*);
void printTree(BinaryNode<int>*);
BinaryNode<int>* add(BinaryNode<int>*, int);
bool contains(BinaryNode<int>*, int);
bool Xcontains(BinaryNode<int>*, int);

void printLeaves(BinaryNode<int>*);
int getTreeHeight(BinaryNode<int>*);
BinaryNode<int>* getInOrderSuccessor(BinaryNode<int>*);
BinaryNode<int>* remove(BinaryNode<int>*, int);

void printSingleChild(BinaryNode<int>*);

int main() {

BinaryNode<int>* root = nullptr;
int height = 0;

//BinaryNode<int>* root = new BinaryNode<int>(12, new BinaryNode<int>(5), new BinaryNode<int>(15));


root = add(root, 10);
root = add(root, 5);
root = add(root, 15);
root = add(root, 25);



printTree(root);
std::cout << "\n";
///	///	///	///	///
contains(root, 15);
std::cout << "\n";
Xcontains(root, 15);
std::cout << "\n";
///	///	///	///	///

printLeaves(root);
std::cout << "\n";
///	///	///	///	///

getInOrderSuccessor(root);
std::cout << "\n";
///	///	///	///	///

std::cout << "Height of tree is: " << getTreeHeight(root ) << "\n";


//remove(root, 10);
std::cout << "\n";

printTree(root);
std::cout << "\n";

printSingleChild(root);



}

// ******	function defs	****** // 

bool isEmpty(BinaryNode<int>* rt) {
	return rt == nullptr;		//return false if tree is empty
}


//prints tree
void printTree(BinaryNode<int>* rt) {

	if (!isEmpty(rt)) {
		printTree(rt->getLeftChildPtr());
		std::cout << rt->getValue() << " ";
		printTree(rt->getRightChildPtr());
	}

}


//add entry
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


//searches for a certain value in tree
bool contains(BinaryNode<int>* rt, int target) {

	BinaryNode<int>* curr = rt;

	if (!isEmpty(rt)) {
		if (curr->getValue() == target) {
			return true;
		}
		else if (target < curr->getValue()) {
			return contains(curr->getLeftChildPtr(), target);
		}
		else if (target > curr->getValue()) {
			return contains(curr->getRightChildPtr(), target);
		}
	}
	return false;
}

bool Xcontains(BinaryNode<int>* rt, int val) {
	if (rt == nullptr) {
		return false;
	}
	std::cout << "in: " << rt->getValue() << " ";
	if (rt->getValue() == val) {
		return true;
	}
	//if node exists in left or right sub-tree, return true
	return Xcontains(rt->getLeftChildPtr(), val) || Xcontains(rt->getRightChildPtr(), val);

}





//prints nodes that both sides are nullptr
void printLeaves(BinaryNode<int>* rt) {
	if (!isEmpty(rt)) {
		printLeaves(rt->getLeftChildPtr());
		if (rt->getLeftChildPtr() == nullptr && rt->getRightChildPtr() == nullptr) {
			std::cout << rt->getValue() << " ";
		}
		printLeaves(rt->getRightChildPtr());
	}
}



int getTreeHeight(BinaryNode<int>* curr) {
	if (curr != nullptr) {
		int lHeight = getTreeHeight(curr->getLeftChildPtr());
		int rHeight = getTreeHeight(curr->getRightChildPtr());

		if (lHeight > rHeight)
			return lHeight + 1;
		else
			return rHeight + 1;
	}
	else
		return 0;

}




// find the successor and returns the address of the successor node
BinaryNode<int>* getInOrderSuccessor(BinaryNode<int>* curr) {
	std::cout << "Inside getInOrderSuccessor() starting --> " << curr->getValue() << endl;
	while (curr->getLeftChildPtr() != nullptr) {
		std::cout << curr->getValue() << " ";
		curr = curr->getLeftChildPtr();
	}
	std::cout << endl << "Successor: " << curr->getValue() << endl;
	return curr;
}



BinaryNode<int>* remove(BinaryNode<int>* curr, int removeVal) {
	std::cout << "\nat: " << curr->getValue() << "";

	if (!isEmpty(curr)) {
		if (contains(curr, removeVal)) {
			if (removeVal < curr->getValue()) {
				std::cout << "\n" << removeVal << " is less than " << curr->getValue() << endl;
				curr->setLeftChildPtr(remove(curr->getLeftChildPtr(), removeVal));
			}
			//if removeVal is greater
			else if (removeVal > curr->getValue()) {
				std::cout << "\n" << removeVal << " is greater than " << curr->getValue() << endl;
				curr->setRightChildPtr(remove(curr->getRightChildPtr(), removeVal));
			}

			//if curr is == to val
			else {
				std::cout << "\nRemoving: " << curr->getValue();
				//if curr has right child only OR no child
				if (curr->getLeftChildPtr() == nullptr){
				//hold right ptr
				BinaryNode<int>* temp = curr->getRightChildPtr();
				delete(curr);
				return temp;
				}
				// if curr has left child only or no child
				else if (curr->getRightChildPtr() == nullptr) {
					//hold left ptr
					BinaryNode<int>* temp = curr->getLeftChildPtr();
					delete(curr);
					return temp;
				}
				//if both have left and right children
				//find in order successor (smallest val in right subtree)
				BinaryNode<int>* temp2 = getInOrderSuccessor(curr->getRightChildPtr());
				curr->setValue(temp2->getValue());
				curr->setRightChildPtr(remove(curr->getRightChildPtr(), temp2->getValue()));
			}
		}
	}
	else {
		std::cout << "Tree is empty!";
	}
	return curr;
}


void printSingleChild(BinaryNode<int>* rt) {
	if (!isEmpty(rt)) {

		printSingleChild(rt->getLeftChildPtr());
		//if either combination is (==null && !=null) OR (!=null && ==null)
		if (((rt->getLeftChildPtr() == nullptr) && (rt->getRightChildPtr() != nullptr)) || ((rt->getLeftChildPtr() != nullptr) && (rt->getRightChildPtr() == nullptr))) {
			std::cout << rt->getValue() << " ";
		}
		printSingleChild(rt->getRightChildPtr());


		
	}
}
