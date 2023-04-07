#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int i;
    int length, j;

    if (!b)
        return (0);

    i = 0;

    length = 0;
    while (b[length] != '\0')
    {
        length++;
    }

    for (j = 1; length > 0; length--, j *= 2)
    {
        if (b[length - 1] != '0' && b[length - 1] != '1')
        {
            return (0);
        }

        if (b[length - 1] == '1')
        {
            i += j;
        }
    }

    return (i);
}
