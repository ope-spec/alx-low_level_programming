#include "main.h"

/**
 * main - Finds and prints the sum of the even-valued terms in the
 *        Fibonacci sequence whose values do not exceed 4,000,000.
 *
 * Return: Always 0
 */
int main(void)
{
        unsigned long int a, b, c, sum;

        a = 1;
        b = 2;
        sum = 2;
        while (b <= 4000000) {
                c = a + b;
                a = b;
                b = c;
                if (b % 2 == 0) {
                        sum += b;
                }
        }
        printf("%lu\n", sum);

        return (0);
}
