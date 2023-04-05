#include <stdio.h>

/*
 * Main: Entry point
 *
 * Description: Prints out the sizes of all character types with a new line
 *
 * Return: Always 0
 */
int main(void)
{
    printf("The size of char is %lu bytes\n", sizeof(char));
    printf("The size of int is %ld byte(s)\n", sizeof(int));
    printf("Size of a long int: %ld byte(s)\n", sizeof(long int));
    printf("Size of a long long int: %ld byte(s)\n", sizeof(long long int));
    printf("Size of a float: %ld byte(s)\n", sizeof(float));
    printf("Size of a double: %ld byte(s)\n", sizeof(double));
    printf("Size of a long double: %ld byte(s)\n", sizeof(long double));

    return 0;
}