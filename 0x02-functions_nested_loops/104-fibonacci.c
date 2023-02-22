/**
 *
 *
 */

#include<stdio.h>
int fibonacci(n)
{
	    if(n==1)
		        {
				        return 1;
					        
					    }
	    if(n==2){
		    return 1;
	    }
	    return fibonacci(n-1) + fibonacci(n-2);

}
int main()
{
	for(int i=1; i<=98;i++)
	{
		printf( fibonacci (i));

	}
}
