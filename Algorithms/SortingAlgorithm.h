#pragma once


#include <iostream>

class SortingAlgorithm
{
public:

	SortingAlgorithm() = default;
	SortingAlgorithm(int arr[], int size);

	virtual void Sort(int arr[], int size);

	virtual ~SortingAlgorithm();

protected:
	int* _arr;
	int _size;
};

