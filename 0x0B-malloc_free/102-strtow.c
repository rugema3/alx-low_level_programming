#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **strtow(char *str)
{
	char **words = NULL;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	/* Check if the string contains only whitespace characters */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isspace(str[i]))
			break;
	}

	if (str[i] == '\0')
		return (NULL);

	len = strlen(str);

	/* Count the number of words in str */
	count = 0;

	for (i = 0; i < len; i++)
	{
		if (!isspace(str[i]))
		{
			count++;

			while (!isspace(str[i]) && i < len)
				i++;

			/* Skip consecutive whitespace characters */
			while (isspace(str[i]) && i < len)
				i++;
		}
	}

	/* Allocate memory for the words array */
	words = malloc((count + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);

	/* Split str into words */
	i = 0;
	k = 0;

	while (i < len)
	{
		/* Skip leading spaces */
		while (isspace(str[i]) && i < len)
			i++;

		/* Find end of current word */
		j = i;

		while (!isspace(str[j]) && j < len)
			j++;

		/* Allocate memory for the word and copy it */
		words[k] = malloc((j - i + 1) * sizeof(char));

		if (words[k] == NULL)
		{
			/* Memory allocation error, clean up and return NULL */
			while (k > 0)
			{
				k--;
				free(words[k]);
			}

			free(words);
			return (NULL);
		}

		strncpy(words[k], &str[i], j - i);
		words[k][j - i] = '\0';

		/* Move to the next word */
		k++;
		i = j;

		/* Skip consecutive whitespace characters */
		while (isspace(str[i]) && i < len)
			i++;
	}

	/* Set the last element of the array to NULL */
	words[k] = NULL;

	return (words);
}

