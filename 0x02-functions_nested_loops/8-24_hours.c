/**
 * jack_bauer - this function prints time from
 * 00:00 to 23:59
 *
 */
#include<stdio.h>

void jack_bauer(void)
{
	int hours = 0;
	int minutes = 0;

	while (hours <= 23)
	{
		while (minutes <= 59)
		{
			printf("%02d:%02d\n", hours, minutes);
			minutes++;
		}
		hours++;
		minutes = 0;
	}
}
