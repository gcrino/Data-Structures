#ifndef _GRAPH
#define _GRAPH


#include <vector>
#include "edge.h"
#include <iostream>

typedef std::pair<int, int> Pair;

class Graph {

	std::vector<std::vector<Pair>> adjList;

public:

	Graph(std::vector<Edge<int>> const& edges, int N) { 
		adjList.resize(N); 
		for (Edge<int> edge : edges) {
			int src = edge.getSrc();
			int dst = edge.getDst();
			int weight = edge.getWeight();

			//insert at end
			adjList[src].push_back(std::make_pair(dst, weight));
		}
	}

	void printGraph(int N) {
		for (int i = 0; i < N; i++) {
			for (Pair v : adjList[i]) {
				std::cout << i << "-->" << v.first << "(w/ weight of: " << v.second << ")";
				std::cout << "\n";
			}
		}
	}
	
};




#endif