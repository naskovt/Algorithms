#pragma once


#include <iostream>
#include <string>

class SortingAlgorithm
{
public:

	SortingAlgorithm() = default;
	SortingAlgorithm(int arr[], int size);

	virtual void Sort(int arr[], int size);

	virtual void PrintName() = 0;

	virtual ~SortingAlgorithm();

protected:
	int* _arr;
	int _size;

	virtual void PrintName_Concatenated(std::string);
};

