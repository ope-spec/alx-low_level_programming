#include <stdio.h>

/***
 * main: Entry point
 * 
 * Description: prints both lower and upper case of alphabets
 * 
 * Return: Always 0 - Success
 * 
***/
int main(void){
    char b = 'a';

    while (b <= 'z')
    {
        putchar(b);
        b++;
    }

    char c = 'A';

    while (c <= 'Z')
    {
        putchar(c);
        c++;
    }

    putchar('\n');

    return (0);

}