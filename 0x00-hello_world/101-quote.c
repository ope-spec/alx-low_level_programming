#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    write(2, msg, sizeof(msg) - 1); // write to stderr
    return 1;
}
