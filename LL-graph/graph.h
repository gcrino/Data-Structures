#ifndef _GRAPH
#define _GRAPH



#include <iostream>
#include <vector>
#include "edge.h"
#include "Node.h"

//typedef std::pair<int, int> Pair;


template<class ItemType>

class Graph {

	std::vector<Node<int>*> adjListV;

public:

	Graph(std::vector<Edge<int>> const& edges, int N) { 
		int src = 0;
		int dst = 0;
		bool nodeExists = false;

		for (Edge<int> edge : edges) {
			src = edge.getSrc();
			dst = edge.getDst();
			std::cout << "adding source at: " << src << "dest: " << dst << std::endl;

			//check if node exists
			if (!adjListV.empty()) {					//if list is not empty
				for (Node* node : adjListV) {			//for each node in list
					if (src == node->getNodeValue()) {	//if source is equal to the nodes value
						nodeExists = true;				//return true (NODE EXISTS!)
						break;							
					}
				}
			}
			
			std::cout << src << (nodeExists ? "Exists" : " does not exist") << std::endl;

			//adding new destination
			if (nodeExists) {
				Node* curr = adjListV.at(src - 1);
				//get to end of list
				while (curr->getNextNodePtr() != nullptr) {
					curr = curr->getNextNode();
				}
				//add node
				curr->setNextNode(new Node(dst);
				std::cout << " --> " << dst << " added." << std::endl;
					
			}
			//adding new soure
			else {
				//add soure
				adjListV.push_back(new Node(src));
				//add destination
				Node* curr = adjListV.at(src - 1);
				curr->setNextNode(new Node(dst));
				std::cout << "new node and destination added.";
			}
		}
	}

	void printGraph(int N) {
		for (int i = 0; i < N; i++) {
			for (Pair v : adjListV[i]) {
				std::cout << i << "-->" << v.first << "(w/ weight of: " << v.second << ")";
				std::cout << "\n";
			}
		}
	}
	
};




#endif