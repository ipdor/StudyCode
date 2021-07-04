#include <stdio.h>
#include <ctype.h>
int main()
{
    int ch= getchar();
    while(ch!=EOF)
    {
        putchar(toupper(ch));
        ch=getchar();
    }
    return 0;
}
