/*
*	Name: Aryan Puthran
*	Date: 10/16/2023
*	Course: CPT_S 121
*	Assignment: Binary Search
*
*	Description: This program will search through an array and find a
*		specified element. Binary searches keep spliting a sorted array
*		into 2 pieces until the target is found.
*/

// Include required libraries
#include <stdio.h>

// List function prototypes
int binarySearch(int values[], int target, int valuesLength);

int main()
{
	// Declare required variables - can be edited
	int values[10] = { -31, -2, 0, 13, 42, 59, 67, 99, 111, 162 };
	int target = 1;

	// Declare required variables - do not edit (is overwritten)
	int valuesLength = -1, result = -1;

	// Call binarySearch() and find valuesLength using memory
	valuesLength = sizeof(values) / sizeof(values[0]);
	result = binarySearch(values, target, valuesLength);

	// Print details
	printf("Searching array for %d...\n", target);
	printf("%d is at the index %d.", target, result);

	// Return a code, "success"
	return 0;
}

/*
*	Description: Cuts an array and finds a target number.
*	Date: 10/16/2023
*
*	Preconditions: values[] is sorted in ascending order.
*	Postconditions: Returns -1 if element isn't present, returns
*		the index otherwise.
*/
int binarySearch(int values[], int target, int valuesLength)
{
	// Declare required variables
	int leftBound = 0, rightBound = valuesLength - 1, middle = rightBound / 2, result = -1;

	// Search the array by cutting it and searching, repeatedly
	while (leftBound <= rightBound)
	{
		// Update middle value
		middle = (leftBound + rightBound) / 2;

		// Checks if the target is found or lower/higher 
		if (target == values[middle])
		{
			// Returns index if found
			return middle;
		}
		else if (target < values[middle])
		{
			// Cuts off right half
			rightBound = middle - 1;
		}
		else
		{
			// Cuts off left half
			leftBound = middle + 1;
		}
	}

	// Returns the result if not found
	return -1;
}