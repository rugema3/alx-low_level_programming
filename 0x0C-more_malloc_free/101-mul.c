#include<stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - computes the length of a string
 * @s: the string to measure
 * Return: the length of s
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 * Return: the integer value of s
 */
int _atoi(const char *s)
{
	int sign = 1;
	int result = 0;
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign = -1;
		else if (_isdigit(s[i]))
			result = result * 10 + (s[i] - '0');
		else
			return (0);
	}
	return (sign * result);
}
/**
 * main - entry point
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	if (!_isdigit(*argv[1]) || !_isdigit(*argv[2]))
	{
		printf("Error\n");
		return (98);
	}
	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);
	result = num1 * num2;
	printf("%d\n", result);
	return (0);
}

