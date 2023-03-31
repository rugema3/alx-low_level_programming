#include<stdio.h>
/**
 * main - the program prints the first 98 fibonacci numbers
 * staring with 1 and 2.
 * Return: 0 (success)
 */
int main(void)
{
	int i;
	double fibo[98] = {1, 2};
	/**
	 *  A double is used because an int would not hold large numbers.
	 *  The fibonacci series gets larger pretty quick
	 */

	printf(" %.0f, ", fibo[0]);
	/* I want the double to come with no decimal places*/
	printf(" %.0f, ", fibo[1]);
for (i = 2; i < 98; i++)
{

	fibo[i] = fibo[i - 2] + fibo[i - 1];
	/**
	 * the fibonacci series is obtained by add the obtained
	 * number from the previous number
	 */
	printf(" %.0f, ", fibo[i]);

}
printf("\n");

return (0);
}

