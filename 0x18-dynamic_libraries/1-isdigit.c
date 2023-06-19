/**
 * _isdigit - checking if character is a digit
 * @c:checks the input
 * Return:1 if c is a digit, 0 otherwise
 */
#include<ctype.h>

int _isdigit(int c)
{
	if (isdigit(c))
		return (1);
	return (0);
}
