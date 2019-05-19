#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(int arr[], int size) : _arr(arr), _size(size)
{
}

void SortingAlgorithm::Sort(int arr[], int size) {
	this->_arr = arr;
	this->_size = size;
}

void SortingAlgorithm::PrintName_Concatenated(std::string algorithmName)
{
	std::cout << "\n Algorithm - " << algorithmName << " executing:" << std::endl;
}

SortingAlgorithm::~SortingAlgorithm()
{
}
