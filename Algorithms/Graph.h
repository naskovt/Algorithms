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
	void BFS(int startIndex, void (*ProcessNodeFunction)(int node));
	void DFS(int startIndex, void (*ProcessNodeFunction)(int node));
	void DFS_Cycle(int startIndex, bool visitedArray[], void (*ProcessNodeFunction)(int node));

private:

	//unordered_set<int> ::iterator it;

	unordered_set<int> * _nodes_array_sets;
	int _nodesCount;

};

