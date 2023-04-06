/**
 * check_sqrt - checks if the square of a given number is equal to n.
 * @n: the number to find the square root of.
 * @i: the current number to check.
 *
 * Return: the square root of n if found, -1 otherwise.
 */
int check_sqrt(int n, int i)
{
if (i * i == n)
return (i);
if (i * i > n)
return (-1);
return (check_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the number to find the square root of.
 *
 * Return: the square root of n if found, -1 otherwise.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (check_sqrt(n, 0));
}
