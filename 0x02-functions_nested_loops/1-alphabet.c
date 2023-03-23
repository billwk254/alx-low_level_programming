#include "main.h"

/**
 * print_alphabet - write a program that prints alphabets in lower case
 *
 * Return: void
 */

void print_alphabet(void)
{
char c = 'a';
int i;

for (i = 0; i < 26; i++)
{
_putchar(c + i);
}
_putchar(10);
}
