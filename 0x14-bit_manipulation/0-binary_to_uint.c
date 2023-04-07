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
unsigned int i = 0;
int j, k;

if (b == NULL)
{
return (0);
}

for (j = 0; b[j] != '\0'; j++)
{
if (b[j] != '0' && b[j] != '1')
{
return (0);
}
}

for (j = 0, k = 1; b[j] != '\0'; j++, k *= 2)
{
if (b[j] == '1')
{
i += k;
}
}

return (i);
}
