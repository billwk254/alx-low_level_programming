#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array using Binary Search.
 * @array: Pointer to the first element of the sorted array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */

int binary_search(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);

int left = 0;
int right = size - 1;

while (left <= right)
{
int mid = left + (right - left) / 2;

printf("Searching in array: ");
for (int i = left; i <= right; i++)
{
printf("%d", array[i]);
if (i < right)
printf(", ");
}
printf("\n");

if (array[mid] == value)
return (mid);
else if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}

return (-1);
}

