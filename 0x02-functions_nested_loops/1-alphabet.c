#include "main.h"

/**
* print_alphabet - prints the alphabet, in lowercase, followed by a new line.
*/
void print_alphabet(void)
{
char a_to_z = 'a';
while (a_to_z <= 'z')
{
_putchar(a_to_z);
a_to_z++;
}
_putchar('\n');
}
