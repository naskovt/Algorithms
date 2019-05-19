#pragma once

#include <algorithm>
#include "SortingAlgorithm.h"

	class SelectionSort : public SortingAlgorithm {

	public:

		SelectionSort() : SortingAlgorithm(){};

		SelectionSort(int arr[], int size) : SortingAlgorithm(arr, size) {
			SelectionSort_Safe();
		}

		void Sort(int arr[], int size) override {

			SortingAlgorithm::Sort(arr, size);

			SelectionSort_Safe();
		}

		void PrintName() override {
			SortingAlgorithm::PrintName_Concatenated("SelectionSort");
		}

		~SelectionSort() = default;

	private:

		void SelectionSort_Safe() {
			if (this->_size < 3)
			{
				std::cout << " less than 3 numbers provided, you kidding me? ";
			}
			else
			{
				SelectionSort_cycle();
			}
		}

		void SelectionSort_cycle() {

			int lowestNumberIndex = 0;

			for (int beginIndex = 0; beginIndex < _size - 1 ; beginIndex++)
			{
				lowestNumberIndex = beginIndex;

				for (int i = beginIndex + 1; i < _size; i++)
				{
					if (_arr[lowestNumberIndex] > _arr[i])
					{
						lowestNumberIndex = i;
					}
				}

				std::swap(_arr[lowestNumberIndex] , _arr[beginIndex]);
			}


		}

};
