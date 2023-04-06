#include <stdio.h>

/***
 * main: Entry point
 * 
 * Description: prints all single digit numbers of base 10 starting from 0, followed by a new line.
 * 
 * Return: Always 0 - success
 * 
***/
int main(void)
{
    int n;

    for ( n = 0; n <= 9; n++)
    {
        printf("%d", n);
    }

    putchar('\n');

    return (0);
    
}