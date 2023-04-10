/**
 * get_endianness - Checks the endianness of the system.
 *
 * This function checks the endianness of the system by using a union to
 * access the same memory location as both an unsigned int and an array of
 * unsigned char. It sets the value of the unsigned int member to 1 and
 * checks the value of the first byte (index 0) of the unsigned char array
 * to determine the endianness. If the first byte is 1, it indicates little
 * endian, and the function returns 1. Otherwise, if the first byte is not
 * 1, it indicates big endian, and the function returns 0.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
    union {
        unsigned int i;
        unsigned char c[sizeof(unsigned int)];
    } u;

    u.i = 1; /* Set the value of the unsigned int member to 1 */

    /* Check the value of the first byte (index 0) of the unsigned char array to determine the endianness */
    if (u.c[0] == 1)
    {
        /* If the first byte is 1, it means the system is little endian */
        return 1; /* Return 1 for little endian */
    }
    else
    {
        /* Otherwise, the system is big endian */
        return 0; /* Return 0 for big endian */
    }
}

