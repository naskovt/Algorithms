#pragma once
#include <algorithm>
#include "SortingAlgorithm.h"


class InsertionSort : public SortingAlgorithm {

public:

	InsertionSort() : SortingAlgorithm() {};

	InsertionSort(int arr[], int size) : SortingAlgorithm(arr, size) {

		InsertionSort_Cycle();
	};

	void Sort(int arr[], int size) {

		SortingAlgorithm::Sort(arr, size);

		InsertionSort_Cycle();
	}

	void PrintName() override {
		SortingAlgorithm::PrintName_Concatenated("InsertionSort");
	}

	~InsertionSort() = default;

private:

	void InsertionSort_Cycle() {

		int i, key, j;
		for (i = 1; i < _size; i++)
		{
			key = _arr[i];
			j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && _arr[j] > key)
			{
				_arr[j + 1] = _arr[j];
				j = j - 1;
			}
			_arr[j + 1] = key;
		}
	}


};