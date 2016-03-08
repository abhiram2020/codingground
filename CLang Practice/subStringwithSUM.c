// C++ program to check whether a given tic tac toe
// board is valid or not
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_TO_IDX(C) (C-'a') 

void isSubstring(char *str,int sum)
{
    if(str == NULL)
        printf("Empty String\n");
    
    int hash[26] = {0};
    int  i;
    int cur_sum;
    int start;
    int len = 0;
    
    for(i=0;i < 26;i++)
        hash[i] = i+1;
    
    start = 0;
    len = strlen(str);   
    cur_sum = hash[CHAR_TO_IDX(str[0])];
    printf("CUR_SUM = %d\n",cur_sum);
    
    
    for(i = 1; i<=len; i++)
    {
        
        if((cur_sum>sum) && (start < i-1))
        {
            cur_sum = cur_sum - hash[CHAR_TO_IDX(str[start])];
            start++;
        }
        
        if(cur_sum == sum)
        {
            printf("SUBSTRING FOUND at INDEXES %d and %d\n",start,i-1);
            return;
        }
        
        if(i < len)
        {
            cur_sum = cur_sum + hash[CHAR_TO_IDX(str[i])];
            printf("CUR_SUM_ADD = %d\n",cur_sum);
        }
    }
    printf("NO SUBSTRING of GIVEN SUM\n");
    return;
}

// Driver program
int main()
{
    char str[] = "zzza";
    isSubstring(str,100);
    return 0;
}
