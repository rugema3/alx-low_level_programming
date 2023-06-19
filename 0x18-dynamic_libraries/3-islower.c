#include"main.h"
/**
 * _islower - checking if lowercase
 *
 * @c: - function input
 *
 * Return:  1(lowercase) , otherwise 0
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);

}
