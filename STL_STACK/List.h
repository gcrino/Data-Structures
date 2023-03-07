#ifndef LIST
#define LIST

#include "ListInterface.h"
#include <list>

template <class Itemtype>
class STL_List : public ListInterface<Itemtype> {
	std::list<Itemtype>myList;
	


public:
	STL_List();
	bool isEmpty() const = 0;
	int getLength() const = 0;
	bool insert(int newPosition, const ItemType& newEntry) = 0;
	bool remove(int position) = 0;
	void clear() = 0;
	ItemType getEntry(int position) const = 0;
	void replace(int position, const ItemType& newEntry) = 0;
	~STL_List();
};





#endif