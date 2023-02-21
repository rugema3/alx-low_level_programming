#include <stdio.h>

/**
 * main - Prints first 50 Fibonacci numbers, starting with 1 and 2,
 * separated by a comma followed by a space.
 *
 * Return: 0.(success)
 */
int main(void)
{
	int count;
	unsigned long fib1 = 0, fib2 = 1, sum;

		sum = fib1 + fib2;
		float total;

		while (1)
		{
			sum = fib1 + fib2;

			if (sum > 4000000)
				break;
			if ((sum %)2 == 0)
				total + = sum;

			fib1 = fib2;
			fib2 = sum;
		}
		printf("%.0f\n", total);

					return (0);
}
