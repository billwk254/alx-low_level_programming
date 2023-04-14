#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
 * mul - multiplies two numbers
 * @num1: the first number
 * @num2: the second number
 *
 * Return: the product of num1 and num2
 */
int mul(char *num1, char *num2)
{
int len1 = 0, len2 = 0, i, j, k, carry = 0, n1, n2, sum = 0;
int *res;

while (num1[len1])
len1++;
while (num2[len2])
len2++;
res = calloc(len1 + len2, sizeof(int));
if (!res)
return (1);
for (i = len1 - 1; i >= 0; i--)
{
n1 = num1[i] - '0';
carry = 0;
k = len2 + i;
for (j = len2 - 1; j >= 0; j--)
{
n2 = num2[j] - '0';
sum = n1 *n2 + carry + res[k];
carry = sum / 10;
res[k] = sum % 10;
k--;
}
if (carry > 0)
res[k] += carry;
}

i = 0;
while (res[i] == 0 && i < len1 + len2 - 1)
i++;
for (; i < len1 + len2; i++)
printf("%d", res[i]);
printf("\n");

free(res);
return (0);
}

/**
 * main - entry point
 * @argc: the argument count
 * @argv: the argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
int i, j;

if (argc != 3)
{
printf("Error\n");
return (98);
}
for (i = 1; i < argc; i++)
{
for (j = 0; argv[i][j]; j++)
{
if (!_isdigit(argv[i][j]))
{
printf("Error\n");
return (98);
}
}
}

return (mul(argv[1], argv[2]));
}
