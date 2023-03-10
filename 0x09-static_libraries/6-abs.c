#include"main.h"

/**
 * _abs - printing the absolute value of a number
 * description: the function will return the absolute value of a number
 * @n: the number whose absolute value is to be found.
 * Return: n returns the value of n as positive all the time
 */
int _abs(int n)
{
	if (n < 0)
		n = (-1) * n;
	return (n);
}

