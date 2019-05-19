#include "Graph_Examples.h"
#include "Sorting_Examples.h"

#include "QuickSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"


using namespace std;

int main() {

	//GraphsTest();



	int numbersToSort = 10;

	QuickSort* sortAlgorithm1 = new QuickSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm1), numbersToSort);

	MergeSort* sortAlgorithm2 = new MergeSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm2), numbersToSort);

	//BubbleSort* sortAlgorithm3 = new BubbleSort();
	//SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm3) , numbersToSort);

	SelectionSort* sortAlgorithm4 = new SelectionSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm4), numbersToSort);

	return 0;
}
