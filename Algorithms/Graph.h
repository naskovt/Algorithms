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
	~Graph();

	void AddEdge(int source, int dest);
	void PrintGraph();
	void GetEdge(int source, int dest);
	void BFS(int s, void (*ProcessNode)(int node));

private:

	unordered_set<int> * _nodes_array_sets;
	int _nodesCount;

};

