/**
 * string_nconcat - Concatenates two strings.
 *
 * @s1: The first string to concatenate.
 * @s2: The second string to concatenate.
 * @n: The number of bytes of s2 to concatenate.
 *
 * Return: A pointer to the concatenated string, or NULL if the function fails.
 */
#include<stdlib.h>
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int s1_len = 0, s2_len = 0, i, j;

	/* Check if strings are NULL */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	/* Calculate lengths of strings */
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	/* Allocate memory for concatenated string */
	if (n >= s2_len)
		n = s2_len;
	concat = malloc(sizeof(char) * (s1_len + n + 1));
	if (concat == NULL)
		return (NULL);
	/* Copy strings to concatenated string */
	for (i = 0; i < s1_len; i++)
		concat[i] = s1[i];
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return (concat);
}
