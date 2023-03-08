/**
 * _pow_recursion- A function that returns the value of x raised to power y.
 * @x: a number whose power is to be determined
 * @y: the power that a number will be raised to
 * Return: the number x raised to power y
 */

#include<stdio.h>
int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	if (y < 0)
		return (-1);
	return (x *  _pow_recursion(x, y - 1));
}
