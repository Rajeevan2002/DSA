/*
* Approach : The idea is to compare x with the last element
* in arr[]. If the element is found at the last position,
* return it. Else recur searchElement() for remaining array and
* element x.
*/


#include <iostream>

using namespace std;

// Recursive function to search for x in arr[]
int searchElement(int arr[], int size, int x) {
	
	size--;
	
	// Base case (Element not present in the array)
	if (size < 0) {
		return -1;
	}
	// Base case (Element found, return its position)
	if (arr[size] == x) {
		return size;
	}

	// Recursive case
	return searchElement(arr, size, x);

}


// Driver code
int main() {
	int arr[] = {17, 15, 11, 8, 13, 19};
	int size = sizeof(arr) / sizeof(arr[0]);
	int x = 11;
	int idx = searchElement(arr, size, x);
	if (idx != -1)
		cout << "Element " << x << " is present at index " <<idx;
	else
		cout << "Element " << x << " is not present in the array";
	return 0;
}

// Code contributed by farzams101
