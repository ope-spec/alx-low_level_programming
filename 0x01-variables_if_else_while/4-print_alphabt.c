#include <stdio.h>

/***
 * main: Entry point
 * 
 * Description: prints all the alphabet except letter q and e
 * 
 * Return: Always 0 - Success
***/
int main(void){
    char l = 'a';

    while (l <= 'z')
    {
        if (l != 'q' && l != 'e')
        {
            putchar(l);
            l++;
        }
        
    }

    putchar('\n');

    return (0);
    
}