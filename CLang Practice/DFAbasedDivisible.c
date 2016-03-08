#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void isdivisibleUtil(int num, int *state,int table[][2])
{
    if(num != 0)
    {
        isdivisibleUtil((num>>1),state,table);
        *state = table[*state][num&1];
    }
}

int isDivisible(int num,int k)
{
    int (*table)[2] = (int (*)[2])malloc(k * sizeof(*table));
    int i = 0;
    
    int trans0 = 0;
    int trans1 = 0;
    int state  = 0;
    
    for(i = 0; i < k;i++)
    {
        trans0 = (i<<1);
        table[i][0] = (trans0 < k) ?trans0:(trans0 - k);
        
        trans1 = (i<<1)+1;
        table[i][1] = (trans1 < k) ?trans1:(trans1 - k);
    }
    
    printf("PREPROCESSED TABLE\n");
    printf("STATE\t 0 \t 1 \t\n");
    printf("-----\t---\t---\t\n");
    for(i = 0; i < k;i++)
    {
        printf("%d\t%d\t%d\t\n",i,table[i][0],table[i][1]);
    }
    printf("\n");
    
    isdivisibleUtil(num,&state,table);
    return state;
}





int main()
{
    int num = 7;
    int k = 15;
    
    int remainder = isDivisible(num,k);
    
    if(remainder)
        printf("Not DIvisible Remainder: %d\n",remainder);
    else
        printf("Divisible\n");
        
    return 0;
}
