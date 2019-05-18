#pragma once
//template <typename int>
#include <vector>
#include "SortingAlgorithm.h"


class MergeSort : public SortingAlgorithm {

public:

	MergeSort() : SortingAlgorithm(), i(0), j(0), k(0), n1(0), n2(0), L(nullptr), R(nullptr) {};

	MergeSort(int arr[], int size) : SortingAlgorithm(arr, size),
		i(0), j(0), k(0), n1(0), n2(0), L(new int[(_size / 2) + 1]), R(new int[(_size / 2) + 1]) {};

	void Sort(int arr[], int size) override {

		SortingAlgorithm::Sort(arr, size);

		L = new int[(size / 2) + 1];
		R = new int[(size / 2) + 1];


		mergeSort(0, size - 1);

	}

	~MergeSort() {
		delete[] L;
		delete[] R;
	}		   

private:

	void merge(int l, int m, int r)
	{
		i = j = k = 0;
		n1 = m - l + 1;
		n2 = r - m;

		/* create temp arrays */



		/* Copy data to temp arrays L[] and R[] */
		for (i = 0; i < n1; i++)
			L[i] = _arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = _arr[m + 1 + j];

		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // Initial index of first subarray 
		j = 0; // Initial index of second subarray 
		k = l; // Initial index of merged subarray 
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				_arr[k] = L[i];
				i++;
			}
			else
			{
				_arr[k] = R[j];
				j++;
			}
			k++;
		}

		/* Copy the remaining elements of L[], if there
		   are any */
		while (i < n1)
		{
			_arr[k] = L[i];
			i++;
			k++;
		}

		/* Copy the remaining elements of R[], if there
		   are any */
		while (j < n2)
		{
			_arr[k] = R[j];
			j++;
			k++;
		}
	}

	/* l is for left index and r is right index of the
	   sub-array of arr to be sorted */
	void mergeSort( int l, int r)
	{
		if (l < r)
		{
			// Same as (l+r)/2, but avoids overflow for 
			// large l and h 
			int m = l + (r - l) / 2;

			// Sort first and second halves 
			mergeSort( l, m);
			mergeSort( m + 1, r);

			merge( l, m, r);
		}
	}


	int* L;
	int* R;
	int i, j, k, n1, n2;
};