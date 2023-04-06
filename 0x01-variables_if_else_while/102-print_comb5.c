#include <stdio.h>

/***
 * main: entry point
 *
 * description: prints all possible combinations of two two-digit numbers.
 *
 * return: 0 always
 *
 ***/
int main(void)
{
    int i;
    int j;

    for (i = 0; i <= 99; i++)
    {
        for (j = 0; i <= 99; j++)
        {
            if (i != j)
            {
                putchar(i / 10 + '0');
                putchar(i % 10 + '0');
                putchar(' ');
                putchar(j / 10 + '0');
                putchar(j % 10 + '0');

                if (i != 98 || j != 99)
                {
                    putchar(',');
                    putchar(' ');
                }
            }
        }
    }

    putchar('\n');

    return (0);
}
