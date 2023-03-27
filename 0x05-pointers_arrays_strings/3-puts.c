#include "main.h"
#include <stdio.h>
/**
 * _puts - prints string
 *
 * @str: string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
int y = 0;

while (str[y] != '\0')
{
putchar(str[y]);
y++;
}

putchar('\n');
}
