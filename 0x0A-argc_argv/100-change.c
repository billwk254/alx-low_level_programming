#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 success, 1 error
 */
int main(int argc, char *argv[])
{
int cents, coins = 0;

if (argc != 2)
{
printf("Error\n");
return (1);
}

cents = atoi(argv[1]);

if (cents < 0)
{
printf("0\n");
return (0);
}

while (cents > 0)
{
if (cents >= 25)
{
coins++;
cents -= 25;
}
else if (cents >= 10)
{
coins++;
cents -= 10;
}
else if (cents >= 5)
{
coins++;
cents -= 5;
}
else if (cents >= 2)
{
coins++;
cents -= 2;
}
else
{
coins++;
cents -= 1;
}
}

printf("%d\n", coins);

return (0);
}
