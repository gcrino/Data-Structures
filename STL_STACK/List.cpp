#ifndef LIST_IMPL
#define LIST_IMPL

#include "List.h"
#include <list>

template <class Itemtype>
bool STL_List<Itemtype>:: isEmpty() const {
	if (myList.size == 0)
		return true;
	else
		return false;
}


template <class Itemtype>
int STL_List<Itemtype>:: getLength() const {
	return myList.size();
}


template <class Itemtype>
bool STL_List<Itemtype>::insert(int newPosition, const ItemType& newEntry) {
	if (newPosition > 0) {
		std::myList<int>::iterator it = myList.begin();
		for (int i = 1; i <= newPosition; i++) {
			it++;
		}
		myList.insert(it, newEntry);
		return true;
	}
	else
		return false;

}


template <class Itemtype>
bool STL_List<Itemtype>:: remove(int position) {

}


template <class Itemtype>
void STL_List<Itemtype>:: clear() {
	while (isEmpty() == false) {
		myList.pop_front();
	}
	std::cout << "list has been cleared";
}


template <class Itemtype>
ItemType STL_List<Itemtype>:: getEntry(int position) const { //list
	if (position > 0) {
		std::myList<int>::iterator it = myList.begin();
		for (int i = 1; i <= newPosition; i++) {
			it++;
		}
		return *it;
	}
}


template <class Itemtype>
void STL_List<Itemtype>:: replace(int position, const ItemType& newEntry) { ///list::assign

}













#endif