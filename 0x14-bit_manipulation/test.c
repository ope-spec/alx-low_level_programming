#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 *
 * @b: a pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1, or if b is NULL.
 **/
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    int length = 0;

    if (b == NULL)
    {
        return 0;
    }
    while (b[length] != '\0')
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        if (b[i] != '0' && b[i] != '1'){
            return 0;
        }

        result <<= 1;
        if (b[i] == '1')
        {
            result += 1;
        }
    }

    return result;
}
