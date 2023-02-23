#include<stdio.h>
/**
 * main - finding the largest prime factor
 *
 * Return: 0 (success)
 *
 */
int main(void)
{
	long num = 612852475143;
	long quotient = 2;
	long largest_prime_factor = 0;

	while (num != 1)
	{
		if (num % quotient == 0)
		{
			num = num / quotient;
			largest_prime_factor = quotient;
		}
		quotient += 1;
	}
	printf("ld\n", larget_prime_factor);
	return (0);
}
