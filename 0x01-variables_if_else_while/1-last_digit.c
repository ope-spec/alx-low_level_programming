#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/***
 * main: Entry point
 *
 * Description:  assign a random number to the variable n each time it is executed
 *
 * Return: Always 0 - Success
 ***/
int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    int p = n % 5;

    printf("Last digit of %d is ", n);
    if (p > 5)
        printf("%d and is greater than 5\n", p);
    else if (p == 0)
        printf("%d and is 0\n", p);
    else
        printf("%d and is less than 6 and not 0\n", p);
    return (0);
}