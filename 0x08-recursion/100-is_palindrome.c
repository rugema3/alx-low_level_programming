#include"main.h"
/**
 * _strlen_recursion - length of a string
 * @s: pointer to a string parameter
 * Return: 1 or 0
 */
int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen_recursion(++s));
}
/**
 * _empty - empty string
 * @s: pointer to a string
 * @1: position
 * Return: 1 or 0
 *
 */
int _empty(char *s, int l)
{
	if (l < 1)
		return (1);
	if (*s == *(s + l))
		return (_empty(s + 1, l - 2));
	return (0);
}
/**
 * is_palindrome - palindrome
 * @s: pointer to a string
 * Return:
 */
int is_palindrome(char *s)
{
	int length = _strlen_recursion(s);
	return (_empty(s, length - 1));
}
