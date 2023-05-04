#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to be printed in binary.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
int shift = sizeof(n) * 8 - 1;
int flag = 0;

while (shift >= 0)
{
unsigned long int bit = n >> shift;

if (bit & 1)
{
flag = 1;
_putchar('1');
}
else if (flag)
_putchar('0');

--shift;
}

if (!flag)
_putchar('0');
}
