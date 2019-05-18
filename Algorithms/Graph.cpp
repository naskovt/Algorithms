#include "Graph.h"
#include <queue>



Graph::Graph(int nodesCount) : _nodesCount(nodesCount) {

	this->_nodes_array_sets = new unordered_set<int>[nodesCount];

}

Graph::~Graph()  {
	delete[] this->_nodes_array_sets;
}

void Graph::AddEdge(int source, int dest) {

	this->_nodes_array_sets[source].insert(dest);
	this->_nodes_array_sets[dest].insert(source);
}

void Graph::GetEdge(int source, int dest) {

	//cout << "\n";

	unordered_set<int>::iterator it = this->_nodes_array_sets[source].find(dest);
	if (it != _nodes_array_sets[source].end())
	{
		//cout << "\nFound edge: " << source << " -> " << *it;
	}
	else
	{
		//cout << "No such edge: " << source << " -> " << dest;
	}

	//cout << "\n";


}

void Graph::PrintGraph() {


	for (size_t i = 0; i < _nodesCount; i++)
	{
		std::cout << "\n Info for node " << i << " : ";

		for (auto edgeDest : this->_nodes_array_sets[i])
		{
			std::cout << " -> " << edgeDest;
		}

	}


}


void Graph::BFS(int startingNode, void (*ProcessNodeFunction)(int node) ) {

	// create queue
	queue<int> * nodes_queue = new queue<int>();

	//create visited bool[]
	bool* visitedArray = new bool[this->_nodesCount];
	// init array with false
	for (int i = 0; i < this->_nodesCount; i++)
	{
		visitedArray[i] = false;
	}


	void (*VisitNode)(int node, bool* visitedArray, queue<int> * nodes_queue) =
					[](int node, bool* visitedArray, queue<int> * nodes_queue)
	{
		visitedArray[node] = true;
		nodes_queue->push(node);
	};

	//visit starting node
	VisitNode(startingNode, visitedArray, nodes_queue);


	int nodeToProcess = 0;
	// while queue not empty cycle through nodes
	while (!nodes_queue->empty())
	{
		// get next node from queue to process
		nodeToProcess = nodes_queue->front();

		ProcessNodeFunction(nodeToProcess);

		// remove it after processing
		nodes_queue->pop();

		for (int adjacentNode : this->_nodes_array_sets[nodeToProcess])
		{
			if (!visitedArray[adjacentNode])
			{
				VisitNode(adjacentNode, visitedArray, nodes_queue);
			}
		}
	}

	delete nodes_queue;
	delete[] visitedArray;

	return;
}



void Graph::DFS_Cycle(int nodeToProcess, bool visitedArray[], void (*ProcessNodeFunction)(int node)) {

	visitedArray[nodeToProcess] = true;
	ProcessNodeFunction(nodeToProcess);

	for (int adjacentNode : this->_nodes_array_sets[nodeToProcess])
	{
		if (!visitedArray[adjacentNode])
		{
			this->DFS_Cycle(adjacentNode, visitedArray, ProcessNodeFunction);
		}
	}

}

void Graph::DFS(int startIndex, void (*ProcessNodeFunction)(int node) ) {

	//create bool[] visited nodes
	bool* visitedArray = new bool[this->_nodesCount];
	// init array with false
	for (int i = 0; i < this->_nodesCount; i++)
	{
		visitedArray[i] = false;
	}

	this->DFS_Cycle(startIndex, visitedArray, ProcessNodeFunction);

}
