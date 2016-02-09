#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define max(a,b) (a>b)?a:b

void arrayaddition(int a[],int m,int b[],int n,int *result,int r_len)
{
    int i;
    int j;

    i = m-1;
    j = n-1;
    int carry = 0;
    int remainder = 0;
    int sum = 0;
    int k = r_len-1;
    while(i >= 0 && j >= 0)
    {
        sum = a[i] + b[j] + carry;
        carry = sum/10; //Gets the Carryover Number > 10
        remainder = sum % 10; //Gets the Remainder
        result[k] = remainder;
        i--;
        j--;
        k--;
    }
    
    while (i >= 0)
    {
        sum = a[i] + carry;
        carry = sum/10; //Gets the Carryover Number > 10
        remainder = sum % 10; //Gets the Remainder
        result[k] = remainder;
        i--;
        k--;
    }
    while (j >= 0)
    {
        sum = b[j] + carry;
        carry = sum/10; //Gets the Carryover Number > 10
        remainder = sum % 10; //Gets the Remainder
        result[k] = remainder;
        j--;
        k--;
    }
    
    return;
    
}


int main()
{
    
    int a[7] = {9,9,9,9,9,9,9};
    int b[6] = {1,6,8,2,6,7};
    int i = 0;
   
    int c_len = max(7,6);
    int result[c_len];
    memset(&c_len,0,c_len);
    
    arrayaddition(a,7,b,6,result,c_len);
    
    for(i = 0; i < c_len; i++)
    {
        printf("%d",result[i]);
    }
    
    return 0;
}
