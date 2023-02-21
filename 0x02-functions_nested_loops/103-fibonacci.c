#include <stdio.h>

/**
 * main - Prints first 50 Fibonacci numbers, starting with 1 and 2,
 * separated by a comma followed by a space.
 *
 * Return: 0.(success)
 */
int main(void)
{
	int count = 0;
	unsigned long fib1 = 0, fib2 = 1, following = 0;

	while  (following < 4000000)
	{
		following = fib1 + fib2;
		fib1 = fib2;
		fib2 = following;
		if (following % 2 == 0)
			count + = following;
	}
	printf("%i\n", count);
	return (0);
}


