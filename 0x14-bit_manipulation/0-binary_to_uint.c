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
if (b == NULL)
return (0);

int len = 0;
while (b[len] != '\0')
{
if (b[len] != '0' && b[len] != '1')
return (0);
len++;
}

unsigned int num = 0;
unsigned int base = 1;
for (int i = len - 1; i >= 0; i--)
{
if (b[i] == '1')
num += base;
base *= 2;
}

return (num);
}
