#include "main.h"

/**
 * swap_int - swap integers
 *
 * @a: first integer to be swapped
 * @b: second integer to be swapped
 *
 * Return: 0 (Success)
 */
void swap_int(int *a, int *b)
{
int x = *a;
int y = *b;

*a = y;
*b = x;
}
