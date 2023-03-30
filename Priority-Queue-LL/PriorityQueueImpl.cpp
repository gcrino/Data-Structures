#include <iostream>
#include "Node (1).h"
#include "PriorityQueue.h"

template<class itemType>
LL_PriorityQueue<itemType>::LL_PriorityQueue() {
	root = NULL;
	std::cout << "Queue has been created \n";
}


template<class itemType>
bool LL_PriorityQueue<itemType>::isEmpty() const {
	if (root == NULL)
		return true;
	else
		return false;

}

template<class itemType>
bool LL_PriorityQueue<itemType>::enqueue(const itemType& newEntry) {
	Node<itemType>* current = root;

	if (!isEmpty()) {

		//prio less than root
		//add as first node
		if (newEntry < current->getNodeValue()) {
			Node<itemType>* temp = new Node<itemType>(newEntry, root);
			root = temp;

			return true;
		}

		//prio higher than root
		//add at appropraite position
		else {
			while (current->getNextNode() != NULL) {
				//if newEntry is greater than the current value AND less than the next value
				if (newEntry >= current->getNodeValue() && newEntry <= current->getNextNode()->getNodeValue()) {
					Node<itemType>* temp = new Node<itemType>(newEntry, current->getNextNode());
					current->setNextNode(temp);
					return true;
				}
				else {
					current = current->getNextNode();
				}
			}
			//last node
			Node<itemType>* temp = new Node<itemType>(newEntry);
			current->setNextNode(temp);
			current = current->getNextNode();
			lastnode = current;
			return true;
			
		}
	}
}

template<class itemType>
bool LL_PriorityQueue<itemType>::dequeue() {
	if (!isEmpty() && root->getNextNode != NULL) {
		root = root->getNextNode();
		return true;
	}
	else
		return false;
}


template<class itemType>
itemType LL_PriorityQueue<itemType>::peek() const {

	return root->getNodeValue();
}

