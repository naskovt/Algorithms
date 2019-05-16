#include "Graph.h"



Graph::Graph(int nodesCount) : _nodesCount(nodesCount) {

	this->_nodes_set = new unordered_set<int>[nodesCount];

}

void Graph::AddEdge(int source, int dest) {

	this->_nodes_set[source].insert(dest);
	this->_nodes_set[dest].insert(source);
}

void Graph::GetEdge(int source, int dest) {

	cout << "\n";

	unordered_set<int>::iterator it = this->_nodes_set[source].find(dest);
	if (it != _nodes_set[source].end())
	{
		cout << "Found edge: " << source << " -> " << *it;
	}
	else
	{
		cout << "No such edge: " << dest;
	}

	cout << "\n";


}

void Graph::PrintGraph() {


	for (size_t i = 0; i < _nodesCount; i++)
	{
		std::cout << "\n Info for node " << i << " : ";

		for (auto edgeDest : this->_nodes_set[i])
		{
			std::cout << " -> " << edgeDest;
		}

	}


}