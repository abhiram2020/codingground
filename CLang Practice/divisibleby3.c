#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int ismultipleof3(int num)
{
    if(num == 0)
        return 1;
    
    if(num == 1)
        return 0;
    
    int odd = 0;
    int even = 0;
    
    while(num != 0)
    {
        if(num & 1)
            odd+= 1;
        num = num>>1;
        
        if(num & 1)
            even+= 1;
        num = num>>1;    
    }
    
    return (ismultipleof3(abs(odd-even)));
}



int main()
{
    
    int num = 9;
    
    if(ismultipleof3(num))
        printf("Divisible by 3\n");
    else
        printf("NOT Divisible by 3\n");
        
    return 0;
}
