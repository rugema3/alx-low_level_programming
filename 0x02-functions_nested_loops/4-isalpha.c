/**
 * _isalpha - checking if character is alphabetic
 * @c:checks the input
 * Return:1 if c is a letter, 0 otherwise
 */
#include <ctype.h>
int _isalpha(int c)
{
	if (isalpha(c))
		return (1);
	return (0);
}
