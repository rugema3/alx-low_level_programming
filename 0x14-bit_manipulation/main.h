#ifndef BINARY_TO_UINT_H
#define BINARY_TO_UINT_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

unsigned int binary_to_uint(const char *binary_string);
void print_binary(unsigned long int num);
int _putchar(char c);
int get_bit(unsigned long int num, unsigned int index);
int set_bit(unsigned long int *num, unsigned int i);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int num1, unsigned long int num2);

#endif /* BINARY_TO_UINT_H */

