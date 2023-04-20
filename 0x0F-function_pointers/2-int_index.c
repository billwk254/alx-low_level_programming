#include "function_pointers.h"
#include <stddef.h>
/**
 * int_index - Searches for an integer in an array
 * @array: The array to search
 * @size: The size of the array
 * @cmp: The comparison function to use
 *
 * Return: first element index
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i, result;

if (array == NULL || cmp == NULL || size <= 0)
return (-1);

for (i = 0; i < size; i++)
{
result = cmp(array[i]);
if (result != 0)
return (i);
}

return (-1);
}
