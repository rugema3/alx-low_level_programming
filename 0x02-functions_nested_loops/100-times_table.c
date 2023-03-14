#include <stdio.h>

/*
 * print_times_table(n) prints the times table up to n.
 * If n is negative or greater than 15, nothing is printed.
 *
 * @n: integer n times
 */
void print_times_table(int n)
{
	int i, j, product;

	if (n < 0 || n > 15)
	{
		return;
	}
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			product = i * j;
			if (j == 0)
			{
				printf(" %d  ", product);
			}
			else
			{
				printf(",%2d  ", product);
			}
		}
		printf("\n");
	}
}
