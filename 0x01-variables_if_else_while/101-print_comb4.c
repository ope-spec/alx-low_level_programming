#include <stdio.h>

/***
 * main: entry point
 * 
 * description: prints all possible different combinations of three digits.
 * 
 * return: 0 always
 * 
***/
int main(void){
    int i;
    int j;
    int k;

    for ( i = 0; i <= 7; i++)
    {
        for ( j = 0; j <= 8; j++)
        {
            for ( k = 0; k <= 9; k++)
            {
                putchar(i + '0');
                putchar(j + '0');
                putchar(k + '0');

                if (i != 7 || j != 8 || k != 9)
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