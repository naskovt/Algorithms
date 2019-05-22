#pragma once

int linearSearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not 
	// present in array 
	return -1;
}

// If x is present in arr[0..n-1], then returns 
// index of it, else returns -1. 
int interpolationSearch(int arr[], int n, int x)
{
	// Find indexes of two corners 
	int lo = 0, hi = (n - 1);

	// Since array is sorted, an element present 
	// in array must be in range defined by corner 
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x) return lo;
			return -1;
		}
		// Probing the position with keeping 
		// uniform distribution in mind. 
		int pos = lo + (((double)(hi - lo) /
			(arr[hi] - arr[lo])) * (x - arr[lo]));

		// Condition of target found 
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in upper part 
		if (arr[pos] < x)
			lo = pos + 1;

		// If x is smaller, x is in the lower part 
		else
			hi = pos - 1;
	}
	return -1;
}