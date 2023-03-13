/**
 * argstostr - Concatenates all arguments of a program.
 * @ac: The number of arguments.
 * @av: An array of pointers to the arguments.
 *
 * Return: If memory allocation fails or ac is 0 or av is NULL, returns NULL.
 * Otherwise, returns a pointer to a newly allocated string that contains all
 * the arguments concatenated, separated by newlines.
 */
#include<stdlib.h>
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, len = 0, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (*(*(av + i) + len))
			len++;
		total_len += len + 1;
	}

	str = malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (NULL);

	for (i = 0, k = 0; i < ac; i++)
	{
		len = 0;
		while (*(*(av + i) + len))
			len++;

		for (j = 0; j <= len; j++, k++)
		{
			if (j == len)
				*(str + k) = '\n';
			else
				*(str + k) = *(*(av + i) + j);
		}
	}

	return (str);
}

