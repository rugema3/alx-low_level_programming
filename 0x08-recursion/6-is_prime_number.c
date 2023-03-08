/**
 * is_prime_number - a function that returns 1 if the input integer
 * is a prime number, otherwise return 0.
 * @n: integer
 * Return: 1 if the number is prime, 0 is not prime
 *
 */
#include<stdio.h>
int is_prime_number(int n)
{
	i= n / 2;
	if(i==1){
    return 1;
  }else{
    if(num%i==0) {
      return 0;
    } else {
      i = i-1;
      is_prime_number(num);
    }
  }
