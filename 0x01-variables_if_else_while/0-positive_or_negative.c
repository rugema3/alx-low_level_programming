#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* main - the main function is where the program starts */
/* Return : 0 (sucess) */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{ printf("%d if the number is greater than 0: is positive \n", n)
				}
				else if (n == 0)
					{
					printf("%d if the number is 0: is zero \n", n)
					}
	else
		printf("%d if the number is negative: negative \n", n)
	return (0);
}
