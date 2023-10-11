#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_search - Search for a value in an array using Linear Search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if not found.
 */
int linear_search(int *array, size_t size, int value)
{

if (array == NULL)
return (-1);

size_t i = 0;
for (size_t i = 0; i < size; i++)
{
printf("Value checked array[%lu] = [%d]\n", i, array[i]);
if (array[i] == value)
return (i);
}

return (-1);
}
