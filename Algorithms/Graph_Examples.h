#pragma once
#include <iostream>
#include "Graph.h"
#include <stdlib.h>
#include <time.h> 
#include <thread> 

#include "StopWatch.h"



using namespace std;

size_t processedNodesCount = 0;



void SearchEdgeNTimes(Graph* graph, int N) {
	for (size_t i = 0; i < N; i++)
	{
		graph->GetEdge(2, 3);
	}
}

class thread_class {
public:
	void operator () (Graph* graph, int N) {

		SearchEdgeNTimes(graph, N);

	}
};

void ProcessNodeFunction(int node) {

	//cout << node << " ";
	++processedNodesCount;
}


void SingleThreaded_Execution(Graph* graph_ptr, int executeCycles) {
	thread_class th;
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
	th(graph_ptr, executeCycles);
}

void MultiThreaded_Execution(Graph* graph_ptr, int executeCycles) {
	thread th1(thread_class(), graph_ptr, executeCycles);
	thread th2(thread_class(), graph_ptr, executeCycles);
	thread th3(thread_class(), graph_ptr, executeCycles);
	thread th4(thread_class(), graph_ptr, executeCycles);
	thread th5(thread_class(), graph_ptr, executeCycles);
	thread th6(thread_class(), graph_ptr, executeCycles);
	thread th7(thread_class(), graph_ptr, executeCycles);
	thread th8(thread_class(), graph_ptr, executeCycles);
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();
	th7.join();
	th8.join();
}

void GraphsTest() {

	int graphNodesCount = 3000;
	int edgesPerNode = 2;

	Graph* graph_ptr = new Graph(graphNodesCount);


	srand(time(NULL));
	win32::Stopwatch stopwatch;



	for (size_t i = 0; i < graphNodesCount; i++)
	{
		for (size_t j = 0; j < edgesPerNode; j++)
		{
			graph_ptr->AddEdge(i, rand() % graphNodesCount);
			//graph.AddEdge(i, j);
		}
	}


	stopwatch.Start();

	//graph_ptr->BFS(graphNodesCount - 1, ProcessNodeFunction);
	graph_ptr->DFS(graphNodesCount - 1, ProcessNodeFunction);

	//int executeCycles = 100000;
	//SingleThreaded_Execution(graph_ptr, executeCycles);
	//MultiThreaded_Execution(graph_ptr, executeCycles);


	stopwatch.Stop();


	cout << endl;
	std::cout << "Elapsed time: " << stopwatch.ElapsedMilliseconds() << " ms\n";
	std::cout << "Processed nodes: " << processedNodesCount;
	delete graph_ptr;
}
