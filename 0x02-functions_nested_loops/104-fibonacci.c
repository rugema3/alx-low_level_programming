/**
 * main - the program prints the first 98 numbers
 * starting with 1 and 2
 * Return: 0 ( success)
 */
#include<stdio.h>
int main(void)
{
	unsigned int fib1 = 1, i, fib2 = 2;

	printf("%d\n%d\n", fib1, fib2);
	for (i = 2; i < 98; i++)
	{
		unsigned int fib = fib1 + fib2;

		fib1 = fib2;
		fib2 = fib;
		printf("%d\n", fib);
	}
	return (0);
}
