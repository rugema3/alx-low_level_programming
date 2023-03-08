/**
 * factorial - a function that returns the factorial of a given number.
 * @n:a number whose factorial is to be determined
 * Return: -1 if n is less than 0, 1 if n is 0, n factorial
 *
 */
#include<stdio.h>
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
