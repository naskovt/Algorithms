#include <iostream>
#include "Graph.h"
using namespace std;

int main() {

	Graph graph(3);

	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 0);


	graph.PrintGraph();

	graph.GetEdge(2, 1);

	return 0;
}
