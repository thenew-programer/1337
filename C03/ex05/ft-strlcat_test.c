#include <stdio.h>
#include <string.h>
#include "ft_strlcat.h"

int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    unsigned int r, size = 64;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
}
