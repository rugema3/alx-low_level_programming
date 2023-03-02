/**
 * reverse_array - a function that reverses the
 *                content of an array of integers
 *
 * @a: pointer to int array
 * @n: is the number of elements to swap
 *
 * Return: nothing
*/

void reverse_array(int *a, int n)
{
	int tmp, index;

	for (index = n - 1; index >= n / 2; index--)
	{
		tmp = a[n - 1 - index];
		a[n - 1 - index] = a[index];
		a[index] = tmp;
	}
}
