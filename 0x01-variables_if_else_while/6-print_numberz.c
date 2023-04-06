#include <stdio.h>

/***
 * main: Entry point
 * 
 * Description: prints all single digit numbers of base 10 starting from 0, followed by a new line.
 * 
 * Return: Always 0
 * 
***/
int main(void)
{
    i = 0;

    for (i = 0; i <= 9; i++)
    {
        printf("%d", i);
    }

    putchar('\n');
    
    return (0);
}