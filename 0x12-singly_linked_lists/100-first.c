#include<stdio.h>

/**
 * print_message - prints a message before the main function is executed.
 * the print_message function is marked with the constructor attribute,
 * which tells the compiler to execute this function before main is called.
 */
void __attribute__((constructor)) print_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

