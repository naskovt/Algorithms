#include "Graph_Examples.h"
#include "Sorting_Examples.h"

#include "QuickSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"


using namespace std;


int main() {

	//GraphsTest();


	int numbersToSort = 100000;

	//QuickSort* sortAlgorithm1 = new QuickSort();
	//SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm1), numbersToSort);

	MergeSort* sortAlgorithm2 = new MergeSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm2), numbersToSort);

	//InsertionSort* sortAlgorithm3 = new InsertionSort();
	//SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm3), numbersToSort);

	//SelectionSort* sortAlgorithm4 = new SelectionSort();
	//SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm4), numbersToSort);

	//HeapSort* sortAlgorithm5 = new HeapSort();
	//SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm5), numbersToSort);

	return 0;
}
