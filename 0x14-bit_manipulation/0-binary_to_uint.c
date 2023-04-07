#include "main.h"

/***
 * binary_to_uint - converts a binary number to an unsigned int.
 *
 * @b: a pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1, or if b is NULL.
 ***/
unsigned int binary_to_uint(const char *b)
{
    unsigned int r = 0;
    int len = 0, i;

    if (b == NULL)
        return (0);

    while (b[len] != '\0')
    {
       len++;
    }

    for (i = 0; i < len; i++)
    {
        if (b[i] != '0' && b[i] != '1')
            return (0);

        r <<= 1;
        if (b[i] == '1')
            r += 1;
    }

    return (r);
}


