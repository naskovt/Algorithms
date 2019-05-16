#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Graph
{

public:
	Graph() = delete;
	Graph(int nodesCount);
	~Graph() = default;

	void AddEdge(int u, int v);
	void PrintGraph();
private:

	vector<int> * _nodes_v;
	int _nodesCount;

};

