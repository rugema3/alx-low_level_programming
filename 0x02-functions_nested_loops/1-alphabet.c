
/**
 * print_alphabet - this function prints alphabets in lowercase using _putchar.
 *
 * Return: 0 (Success)
 */

void print_alphabet(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		_putchar(ch);
		ch++;
	}
	_putchar('\n');
	return (0);
}
