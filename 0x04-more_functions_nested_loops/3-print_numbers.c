/**
 * prrint_numbers - The function prints numbers from 0-9'
 * return: 0 (success)
 *
 */
void print_numbers(void);
{
	int a = 0;

	while (a < 10)
	{
		_putchar(a);
		a++;
	}
	_putchar('\n');

	return (0);

}
