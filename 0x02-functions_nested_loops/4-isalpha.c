/**
 * _isalpha - checking if character is alphabetic
 * @c:checks the input
 * Return:1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	char lower, upper;
	int count = 0;

	for (lower = 'a'; lower <= 'z'; lower++)
	{
		for (upper = 'A'; upper <= 'Z'; upper++)
		{
			If(c == lower || c == upper)
				count = 1;
		}
	}
	return (count);
}
