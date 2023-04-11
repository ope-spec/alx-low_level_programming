#include "main.h"

/**
 * main - Computes and prints the j of all the multiples of 3 or 5 below 1024
 *
 * Return: Always 0
 */
int main(void)
{
        int j = 0;

        for (int i = 0; i < 1024; i++) {
                if (i % 3 == 0 || i % 5 == 0) {
                        j += i;
                }
        }

        printf("%d\n", j);

        return (0);
}
