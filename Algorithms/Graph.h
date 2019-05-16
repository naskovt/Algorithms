#pragma once

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Graph
{

public:
	Graph() = delete;
	Graph(int nodesCount);
	~Graph() = default;

	void AddEdge(int source, int dest);
	void PrintGraph();
	void GetEdge(int source, int dest);
private:

	unordered_set<int> * _nodes_set;
	int _nodesCount;

};

