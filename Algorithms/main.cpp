#include <iostream>
#include "Graph.h"
using namespace std;

int main() {

	Graph graph(5);

	graph.AddEdge(0, 1);
	graph.AddEdge(0, 4);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 3);
	graph.AddEdge(1, 4);
	graph.AddEdge(2, 3);
	graph.AddEdge(3, 4);

	graph.PrintGraph();

	return 0;
}
