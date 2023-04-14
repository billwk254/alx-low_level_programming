#include <stdlib.h>
#include <stddef.h>
/**
 * array_range - Creates an array of integers
 * @min: The minimum value
 * @max: The maximum value
 *
 * Return: The pointer to the newly created array
 */
int *array_range(int min, int max)
{
int *arr;
int i, size;

if (min > max)
return (NULL);

size = max - min + 1;
arr = malloc(sizeof(int) * size);
if (arr == NULL)
return (NULL);

for (i = 0; i < size; i++)
arr[i] = min++;

return (arr);
}
