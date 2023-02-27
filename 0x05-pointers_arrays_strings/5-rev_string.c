#include "main.h"

/**
 * rev_string - prints a string in reverse
 * @s: string to be reversed
 * Return: 0
  */

void rev_string(char *s)
{
	int len, i, m;
	char temp;

	for (len = 0; s[len] != '\0'; len++)
		;
	i = 0;
	m = len / 2;
	while (m--)
	{
		temp = s[len - i - 1];
		s[len - i - 1] = s[i];
		s[i] = temp;
		i++;
	}
}
