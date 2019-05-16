#include <iostream>
#include "Graph.h"
using namespace std;

int main() {

	Graph graph(20);

	for (size_t i = 0; i < 20; i++)
	{
		graph.AddEdge(i, (i + 1 < 20) ? i+1 : i );

	}


	graph.BFS(0);

	graph.GetEdge(5, 6);

	return 0;
}
