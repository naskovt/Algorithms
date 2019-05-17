#include <iostream>
#include "Graph.h"
using namespace std;



void ProcessNode(int node) {
	cout << node << " ";
}

int main() {

	int graphNodesCount = 200;

	Graph graph(graphNodesCount);

	for (size_t i = 0; i < graphNodesCount; i++)
	{
		graph.AddEdge(i, (i + 1 < graphNodesCount) ? i+1 : i );

	}


	graph.BFS(100, ProcessNode);

	cout << endl;

	graph.GetEdge(150, 151);
	graph.GetEdge(150, 152);

	return 0;
}
