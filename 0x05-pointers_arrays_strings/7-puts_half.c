#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: char to check
 * Return: 0 is success
 */

void puts_half(char *str)
{
int strg = 0, n;

while (str[strg] != '\0')
strg++;
if (strg + 1 % 2 != '0')
n = (strg - 1) / 2;
else
n = (strg / 2);
n++;

for (strg = n; str[strg] != '\0'; strg++)
_putchar(str[strg]);
_putchar('\n');
}
