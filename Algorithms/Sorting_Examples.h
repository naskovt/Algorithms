#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "QuickSort.h"
#include "MergeSort.h"
#include "StopWatch.h"
#include "SortingAlgorithm.h"
#include "SearchingAlgorithms.h"


using namespace std;


void SortingTest(SortingAlgorithm * sortingAlgorithm, int numbersToSort) {

	int ARR_SIZE = numbersToSort;

	int* arr = new int[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = ARR_SIZE - i;
		//arr[i] = rand() % ARR_SIZE;
	}

	srand(time(NULL));

	win32::Stopwatch stopwatch;

	stopwatch.Start();

	sortingAlgorithm->Sort(arr, ARR_SIZE);
 
	stopwatch.Stop();

	sortingAlgorithm->PrintName();

	if (ARR_SIZE > 5)
	{
		// visualize first N numbers 
		for (int i = 0; i < 5; i++)
		{
			cout << " " << arr[i];
		}

		cout << " ...";

		// visualize last N numbers 
		for (int i = ARR_SIZE - 5; i < ARR_SIZE; i++)
		{
			cout << " " << arr[i];
		}
	}

	std::cout << "\nSorting Elapsed time ============================= " << stopwatch.ElapsedMilliseconds() << " ms\n";
	std::cout << endl;


	////////////////// SEARCHING ALGORITHMS
	srand(time(NULL));
	stopwatch.Reset();
	stopwatch.Start();

	int serachFor = 1;
	//int searchResult = linearSearch(arr, ARR_SIZE, serachFor);
	//int searchResult = binarySearch(arr, 0, ARR_SIZE - 1, serachFor);
	int searchResult = interpolationSearch(arr, ARR_SIZE, serachFor);
	
	stopwatch.Stop();
	std::cout << "\nSearching for: " << serachFor << "------Found in Index => " << searchResult;
	std::cout << "------Elapsed time: " << stopwatch.ElapsedMilliseconds() << " ms\n";
	std::cout << endl;


	delete[] arr;

};