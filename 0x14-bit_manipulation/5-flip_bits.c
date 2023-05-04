#include "main.h"
#include <stdio.h>
/**
 * flip_bits - returns the number of bits to get to another number
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits we need to flip to convert n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor_result = n ^ m;
unsigned int count = 0;

while (xor_result)
{
if (xor_result & 1)
count++;

xor_result >>= 1;
}

return (count);
}
