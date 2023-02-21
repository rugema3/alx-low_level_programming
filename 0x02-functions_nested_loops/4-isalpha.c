/**
 * _isalpha - checking if character is alphabetic
 * @c:checks the input
 * Return:1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if (c >= 97 && c <= 122 && c >= 65 && c >= 90)
		return (1);
	return (0);
}
