#include "main.h"

/**
 * print_number - a function that prints an integer
 * @n: integer n to print
 */

void print_number(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}

if (n / 1000)
{
_putchar(((n / 100) / 10) / 10 + '0');
}

if (n / 100)
{
_putchar((n / 100) / 10 + '0');
}

if (n / 10)
_putchar(n / 10 + '0');

_putchar(n % 10 + '0');
}
