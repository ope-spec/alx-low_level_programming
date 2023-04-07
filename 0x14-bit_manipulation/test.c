#include "main.h"

/**
 * to replace: ^\s+
 * 
 *
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to the binary number
 *
 * Return: the converted number, or 0 if b is NULL or contains chars other than 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
        unsigned int num = 0;
        int i = 0;

        if (b == NULL)
                return (0);

        while (b[i] != '\0')
        {
                if (b[i] == '0' || b[i] == '1')
                {
                        num = num << 1;
                        if (b[i] == '1')
                                num = num ^ 1;
                        i++;
                }
                else
                {
                        return (0);
                }
        }

        return (num);
}
