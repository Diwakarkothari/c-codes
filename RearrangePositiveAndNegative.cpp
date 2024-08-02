// C++ program to rearrange
// array in alternating
// positive & negative items
// with O(1) extra space
#include <bits/stdc++.h>
using namespace std;

// Function to rearrange positive and negative
// integers in alternate fashion. The below
// solution doesn't maintain original order of
// elements
void rearrange(int arr[], int n)
{
	int i = 0, j = n-1;

	// shift all negative values to the end
	while (i < j) {
		while (i <= n - 1 and arr[i] > 0)
			i += 1;
		while (j >= 0 and arr[j] < 0)
			j -= 1;
		if (i < j )
			swap(arr[i], arr[j]);
	}

	// i has index of leftmost
	// negative element
	if (i == 0 || i == n)
		return;

	// start with first positive
	// element at index 0

	// Rearrange array in alternating
	// positive &
	// negative items
	int k = 0;
	while (k < n && i < n ) {
		// swap next positive
		// element at even position
		// from next negative element.
		swap(arr[k], arr[i]);
		i = i + 1;
		k = k + 2;
	}
}

// Utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 2, 3, -4, -1, 6, -9 };
    // original output   -4 2 -1 3 -9 6  
    // my output   -1 3 -4 2 -9 6   

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
