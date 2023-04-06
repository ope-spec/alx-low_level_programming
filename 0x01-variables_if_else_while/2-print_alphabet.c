#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char o = 'a';

    while (o <= 'z')
    {
        putchar(o);
        o++;
    }

    putchar('\n');

    return (0);
}
