#include <stdio.h>

/***
 * main: entry point
 * 
 * description:  prints all possible different combinations of two digits.
 * 
 * return: 0 always
 * 
***/
int main(void){
    int i;
    int n;

    for ( i = 0; i <= 8; i++)
    {
        for (n = 0; n <= 9 ; n++)
        {
            putchar(i + '0');
            putchar(n + '0');

            if (i != 8 || n != 9)
            {
                putchar(',');
                putchar(' ');
            }
            
        }
        
    }

    putchar('\n');

    return (0);
    
}