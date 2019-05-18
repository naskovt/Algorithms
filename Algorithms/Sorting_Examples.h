#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "QuickSort.h"
#include "MergeSort.h"
#include "StopWatch.h"
#include "SortingAlgorithm.h"

using namespace std;

void SortingTest(SortingAlgorithm * sortingAlgorithm) {

	int ARR_SIZE = 2000;

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
	//QuickSort quicksort_(arr, ARR_SIZE);
	//MergeSort mergesort_(arr, ARR_SIZE);

	stopwatch.Stop();


	for (int i = 0; i < 200; i++)
	{
		cout << " " << arr[i];
	}

	std::cout << endl << "\nElapsed time: " << stopwatch.ElapsedMilliseconds() << " ms\n";
	
	delete[] arr;
}