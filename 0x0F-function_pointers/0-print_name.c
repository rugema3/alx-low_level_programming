/**
 * print_name - prints a name using the provided function
 * @name: a pointer to the name to print
 * @f: a function that takes a char pointer
 * as an argument and returns void
 *
 * This function calls the provided function
 * pointer with the given name as an argument.
 */
#include <stddef.h>
void print_name(char *name, void (*f)(char *))
{
	/**
	 * The implementation checks if name and f are not null before calling f
	 * with name as its argument.
	 */
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}

