/**
 * check_num - checking the number
 * @num:integer
 * @i:iterator
 * Return:1 or 0
 */
int check_num(int num, int i)
{
	if (i == num - 1)
		return (1);
	else if (num % i == 0)
		return (0);
	if (num % i != 0)
		return (check_num(num, i + 1));
	return (0);
}

/**
 * is_prime_number - a function that returns 1 if the input integer
 * is a prime number, otherwise return 0.
 * @n: integer
 * Return: 1 if the number is prime, 0 is not prime
 *
 */
int is_prime_number(int n)
{
	int i = 2;

	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	return (check_num(n, i));
}
