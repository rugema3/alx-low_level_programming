/**
 * _memset - function that fills memory with a constant byte
 *
 * @s: pointer
 * @b: constant
 * @n: n bytes (maximum)
 *
 * Return: Always 0 (Success)
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; n > 0; i++, n--)
	{
		s[i] = b;
	}

	return (s);
}
