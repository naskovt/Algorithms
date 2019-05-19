#pragma once

#include <algorithm>
#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm {

public:

	BubbleSort() : SortingAlgorithm(), _index(0), _isCycleSwapping(false){};

	BubbleSort(int arr[], int size) : SortingAlgorithm(arr, size), _index(0), _isCycleSwapping(false) {
		BubbleSorting_Safe();
	}

	void Sort(int arr[], int size) override {

		SortingAlgorithm::Sort(arr, size);

		BubbleSorting_Safe();
	}

	void PrintName() override {
		SortingAlgorithm::PrintName_Concatenated("BubbleSort");
	}

	~BubbleSort() = default;

private:

	void BubbleSorting_Safe() {
		if (this->_size < 3)
		{
			std::cout << " less than 3 numbers provided, you kidding me? ";
		}
		else
		{
			BubbleSort_cycle();
		}
	}

	void BubbleSort_cycle() {

		//_isCycleSwapping = false;
		for (int cycles = 0; cycles < _size; cycles++)
		{

			for (_index = 1; _index < _size - cycles ; ++_index)
			{
				if (_arr[_index - 1] > _arr[_index])
				{
					std::swap(_arr[_index - 1], _arr[_index]);
					_isCycleSwapping = true;
				}
			}

		}

	}

	bool _isCycleSwapping;
	int _index;
};