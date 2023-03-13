/**
 * str_concat - Concatenates two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: If memory allocation fails, returns NULL.
 * Otherwise, returns a pointer to the concatenated string.
*/
#include<stdlib.h> /*this is where our maloc is located*/
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Determine length of input strings */
	while (*(s1 + len1))
		len1++;
	while (*(s2 + len2))
		len2++;

	/* Allocate memory to store concatenated string */
	concat_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat_str == NULL)
		return (NULL);

	/* Copy s1 to the beginning of concat_str */
	for (i = 0; i < len1; i++)
		*(concat_str + i) = *(s1 + i);

	/* Copy s2 to the end of concat_str */
	for (j = 0; j < len2; j++)
		*(concat_str + i + j) = *(s2 + j);
	*(concat_str + i + j) = '\0';

	return (concat_str);
}

