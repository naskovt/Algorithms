#pragma once

#include <algorithm>
#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {

public:

	QuickSort() : SortingAlgorithm(), p_index(0), pivot(0) {};

	QuickSort(int arr[], int size) : SortingAlgorithm(arr, size), p_index(0), pivot(0) {

		QuickSort_cycle(0, _size - 1);
	}

	void Sort(int arr[], int size) override {

		SortingAlgorithm::Sort(arr, size);

		QuickSort_cycle(0, _size - 1);
	}


	void PrintName() override {
		SortingAlgorithm::PrintName_Concatenated("QuickSort");
	}

	~QuickSort() = default;

private:

	void QuickSort_cycle(int begin, int end) {

		if (begin < end)
		{
			int partitionIndex = this->GetPartitionIndex(begin, end);

			QuickSort_cycle(begin, partitionIndex - 1);
			QuickSort_cycle(partitionIndex + 1, end);
		}
		return;
	}

	int GetPartitionIndex(int begin, int end) {

		pivot = _arr[end];
		p_index = begin;

		for (int i = begin; i < end ; i++)
		{
			if (_arr[i] <= pivot)
			{
				swap(_arr[i], _arr[p_index]);
				p_index++;
			}
		}

		swap(_arr[end], _arr[p_index]);
		return p_index;
	}

	int p_index;
	int pivot;
};