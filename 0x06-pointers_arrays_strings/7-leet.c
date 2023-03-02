/**
 * leet - a function that encodes a string into 1337
 *
 * @s: string input
 *
 * Return: @s
*/

char *leet(char *s)
{
	int i, c = 0;
	int arrayl[] = {97, 101, 111, 116, 108};
	int array2[] = {65, 69, 79, 84, 76};
	int array3[] = {52, 51, 48, 55, 49};

	/*iterate values in array s*/
	while (s[c] != '\0')
	{
		/**
		 * loop through array value five times
		 * to check if the value is equal to
		 * any small letter in array array1 or
		 * upper letter in array array2 and if it
		 * is replace it with the value in array3
		*/
		for (i = 0; i < 5; i++)
		{
			if (s[c] == arrayl[i] || s[c] == array2[i])
			{
				s[c] = array3[i];
				break;
			}
		}
		c++;
	}
	return (s);
}
