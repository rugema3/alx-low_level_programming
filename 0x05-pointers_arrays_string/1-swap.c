/**
 * swap_int - swapping pointers
 * @a: integer to be swaped
 * @b: integer to be swaped
 */
#include"main.h"


void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
