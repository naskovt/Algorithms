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


void Graph::BFS(int s)
{
	// Mark all the vertices as not visited 
	bool* visited = new bool[this->_nodesCount];

	for (int i = 0; i < this->_nodesCount; i++)
		visited[i] = false;

	// Create a queue for BFS 
	list<int> queue;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 
	unordered_set<int>::iterator it;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (it = this->_nodes_set[s].begin(); it != this->_nodes_set[s].end(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}