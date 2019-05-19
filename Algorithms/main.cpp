#include "Graph_Examples.h"
#include "Sorting_Examples.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"

using namespace std;

int main() {

	//GraphsTest();



	int numbersToSort = 20000;

	QuickSort* sortAlgorithm1 = new QuickSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm1), numbersToSort);

	MergeSort* sortAlgorithm2 = new MergeSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm2), numbersToSort);

	BubbleSort* sortAlgorithm3 = new BubbleSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm3) , numbersToSort);

	return 0;
}
