#include"main.h"
/**
 * check_sqrt - evaluate the _sqrt_recursion function
 * @i: integer
 * @n:integer
 * Return: check_sqrt
 */
int check_sqrt(int i, int n)
{
	if (n == 0 || n == 1)
		return (n);
	else if (i * i < n)
		return (check_sqrt(i + 1, n));
	else if (i * i == n)
		return (i);
	return (-1);
	return (-1);
}
/**
 * _sqrt_recursion - a function returning the square root of a number
 * @n: integer
 * Return: square root of a number
 *
 */
int _sqrt_recursion(int n)
{
	int i = 0;

	if (i < 0)
		return (-1);
	return (check_sqrt(i, n));
}


