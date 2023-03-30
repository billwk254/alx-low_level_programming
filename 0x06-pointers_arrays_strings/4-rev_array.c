#include "main.h"

/**
 * reverse_array - a function that reverses an array of integers
 * @a: pointer to the address of the array to be reversed
 * @n: the number of elements of the array
 */
void reverse_array(int *a, int n)
{
int i, j, temp;

j = n - 1;

for (i = 0; i < n / 2; i++)
{
temp = a[i];
a[i] = a[j];
a[j--] = temp;
}
}
