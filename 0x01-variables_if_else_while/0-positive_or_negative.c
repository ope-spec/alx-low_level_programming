#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
* main: Entry point
*
* Description: Assign a random number to variable n each time the code is executed
*
* Return: Always 0 (Success)
*/
int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    printf("The number is %d\n", n);

    if (n > 0)
        printf("%s\n", "is positive");
    else if (n == 0)
        printf("%s\n", "is zero");
    else
        printf("%s\n", "is negative");
    
    return (0);
}