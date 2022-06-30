// CPP Program to find magic index.
#include <bits/stdc++.h>
using namespace std;

int magicIndex(int* arr, int start, int end)
{
	// If No Magic Index return -1;
	if (start > end)
		return -1;

	int midIndex = (start + end) / 2;
	int midValue = arr[midIndex];

	// Magic Index Found, return it.
	if (midIndex == midValue)
		return midIndex;

	// Search on Left side
	int left = magicIndex(arr, start, min(midValue,
									midIndex - 1));

	// If Found on left side, return.
	if (left >= 0)
		return left;

	// Return ans from right side.
	return magicIndex(arr, max(midValue, midIndex + 1),
												end);
}

// Driver program
int main()
{
	int arr[] = { -10, -5, 2, 2, 2, 3, 4, 7,
								9, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = magicIndex(arr, 0, n - 1);
	if (index == -1)
		cout << "No Magic Index";
	else
		cout << "Magic Index is : " << index;
	return 0;
}
