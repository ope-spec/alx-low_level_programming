#include <stdio.h>

/***
 * main: entry point
 * 
 * Description: prints all the numbers of base 16 in lowercase, followed by a new line.
 * 
 * Return: Always 0
 * 
***/
int main(void)
{
    int n;
    char p;

    for (n = 0; n < 10; n++)
    {
        putchar(n + '0');
    }

    for (p = 'a'; p <= 'f'; p++)
    {
        putchar(n);
    }
    
    putchar('\n');

    return (0);
    
}