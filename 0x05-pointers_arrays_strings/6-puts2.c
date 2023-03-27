#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @strn: char to check
 * Return: 0 is success
 */

void puts2(char *strn)
{
int strg;

for (strg = 0; strn[strg] != '\0'; strg++)
if (strg % 2 == 0)
_putchar(strn[strg]);
_putchar('\n');
}
