int is_divisible(int n, int i);

/**
 * is_prime_number - checks if a number is a prime number.
 * @n: the number to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
if (n < 2)
return (0);

return (is_divisible(n, 2));
}

/**
 * is_divisible - checks if a number is divisible
 * @n: the number to check.
 * @i: the number to divide n by.
 *
 * Return: 1 if n is not divisible by i, 0 otherwise.
 */
int is_divisible(int n, int i)
{
if (i >= n)
return (1);

if (n % i == 0)
return (0);

return (is_divisible(n, i + 1));
}
