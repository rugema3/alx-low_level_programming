/**
 * _strdup - Returns a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: Pointer to the string to duplicate.
 *
 * Return: If str is NULL or if memory allocation fails, returns NULL.
 * Otherwise, returns a pointer to the new string.
 */
#include<stdlib.h>
char *_strdup(char *str)
{
	char *new_str;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Determine length of input string */
	while (*(str + len))
		len++;

	/* Allocate memory to store a copy of the input string */
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);

	/* Copy the input string to the newly allocated memory */
	for (i = 0; i <= len; i++)
		*(new_str + i) = *(str + i);

	return (new_str);
}

