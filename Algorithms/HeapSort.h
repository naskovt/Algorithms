#pragma once
#include <algorithm>
#include "SortingAlgorithm.h"


class HeapSort : public SortingAlgorithm {

public:

	HeapSort() : SortingAlgorithm(), largest(0), l(0), r(0) {};

	HeapSort(int arr[], int size) : SortingAlgorithm(arr, size), largest(0), l(0), r(0) {

		HeapSort_Cycle();
	};

	void Sort(int arr[], int size) {

		SortingAlgorithm::Sort(arr, size);

		HeapSort_Cycle();
	}

	void PrintName() override {
		SortingAlgorithm::PrintName_Concatenated("HeapSort");
	}

	~HeapSort() = default;

private:

	void HeapSort_Cycle() {

		// Build heap (rearrange array) 
		for (int i = _size / 2 - 1; i >= 0; i--)
			BuildHeap(_arr, _size, i);

		// One by one extract an element from heap 
		for (int i = _size - 1; i >= 0; i--)
		{
			// Move current root to end 
			std::swap(_arr[0], _arr[i]);

			// call max heapify on the reduced heap 
			BuildHeap(_arr, i, 0);
		}
	}

	void BuildHeap(int arr[], int n, int i) {

		 largest = i; // Initialize largest as root 
		 l = 2 * i + 1; // left = 2*i + 1 
		 r = 2 * i + 2; // right = 2*i + 2 

		// If left child is larger than root 
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest so far 
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// If largest is not root 
		if (largest != i)
		{
			std::swap(arr[i], arr[largest]);

			// Recursively heapify the affected sub-tree 
			BuildHeap(arr, n, largest);
		}

	}

	int largest, l , r;
};