#include "main.h"

/**
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

int main(void)
{
unsigned int n;

n = binary_to_uint("1");
printf("%u\n", n);
n = binary_to_uint("101");
printf("%u\n", n);
n = binary_to_uint("1e01");
printf("%u\n", n);
n = binary_to_uint("1100010");
printf("%u\n", n);
n = binary_to_uint("0000000000000000000110010010");
printf("%u\n", n);
return (0);
}
