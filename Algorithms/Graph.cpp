#include "Graph.h"



Graph::Graph(int nodesCount) : _nodesCount(nodesCount) {

	this->_nodes_v = new vector<int>[nodesCount];

}

void Graph::AddEdge(int u, int v) {

	this->_nodes_v[u].push_back(v);
	this->_nodes_v[v].push_back(u);
}

void Graph::PrintGraph() {


	for (size_t i = 0; i < _nodesCount; i++)
	{
		std::cout << "\n Info for node " << i << " : ";

		for (auto edgeEnd : this->_nodes_v[i])
		{
			std::cout << " -> " << edgeEnd;
		}

		//for (size_t j = 0; j < this->_nodes_v[i].size(); j++)
		//{
		//	std::cout << " -> " << this->_nodes_v[i][j];
		//}
	}


}