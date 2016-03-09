#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

long convert(char *str)
{
    if(str == NULL)
        return 0;
    
    long i   = 0;
    long sum = 0;
    long val = 0;
    char ch;
    
    for(i = 0; i < strlen(str); i++)
    {
        ch = str[i];
        val = (int)ch - 48;
        printf("VALUE of %c is %ld\n",ch,val);
        sum = (sum * 10) + val;
    }
    return sum;
}


int main()
{

    char str[] = "1234";
    long num = convert(str);
    printf("NUM: %ld\n",num);
    
    return 0;
}
