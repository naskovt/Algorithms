#include "Graph_Examples.h"
#include "Sorting_Examples.h"
#include "QuickSort.h"
#include "MergeSort.h"

using namespace std;

int main() {

	//GraphsTest();

	//QuickSort* sortAlgorithm = new QuickSort();
	MergeSort* sortAlgorithm = new MergeSort();
	SortingTest(dynamic_cast<SortingAlgorithm*> (sortAlgorithm));

	return 0;
}
