#include <stdio.h>

/***
 * main: Entry point
 * 
 * Description: prints the lowercase alphabet in reverse, followed by a new line.
 * 
 * Return: Always 0
 * 
***/
int main(void)
{
    char i = 'a';

    while (i >= 'a')
    {
        putchar(i);
        i--;
    }

    putchar('\n');

    return (0);
    
}