/**
 * count_words - Count the number of words in a string.
 * @str: Pointer to the input string.
 *
 * Return: The number of words in the string.
 */
#include<stdlib.h>
int count_words(char *str)
{
	int count = 0, i;
	/* Skip leading spaces */
	while (*str && *str == ' ')
        str++;

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) != ' ' && (*(str + i + 1) == ' ' || *(str + i + 1) == '\0'))
			count++;
	}

	return (count);
}

/**
 * strtow - Split a string into words.
 * @str: Pointer to the input string.
 *
 * Return: If memory allocation fails or str is NULL or empty, returns NULL.
 * Otherwise, returns a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, word_count = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; i < word_count; i++)
	{
		while (*(str + j) == ' ')
			j++;

		len = 0;
		while (*(str + j + len) != ' ' && *(str + j + len) != '\0')
			len++;

		*(words + i) = malloc(sizeof(char) * (len + 1));
		if (*(words + i) == NULL)
		{
			for (k = 0; k < i; k++)
				free(*(words + k));
			free(words);
			return (NULL);
		}

		for (k = 0; k < len; k++)
			*(*(words + i) + k) = *(str + j + k);
		*(*(words + i) + k) = '\0';

		j += len;
	}

	*(words + i) = NULL;

	return (words);
}

