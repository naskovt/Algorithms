#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "QuickSort.h"
#include "MergeSort.h"
#include "StopWatch.h"
#include "SortingAlgorithm.h"

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

	std::cout << endl << "\nElapsed time ============================= " << stopwatch.ElapsedMilliseconds() << " ms\n";
	
	delete[] arr;
}