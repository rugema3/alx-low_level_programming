/**
 * print_alphabet - the function prints lower case alphabet
 *
 * return: 0 (Success)
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
