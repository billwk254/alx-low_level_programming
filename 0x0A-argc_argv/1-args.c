#include "main.h"
#include <stdio.h>

/**
 * main - Prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: Array of pointers
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char __attribute__((__unused__)) *argv[])
{
int i, count = 0;

for (i = 0; i < argc; i++)
count++;

printf("%d\n", count);

return (0);
}
