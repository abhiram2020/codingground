#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CHARS_MAX 256

void smallestSubArray(char *str1,char *str2)
{
    int hasFound[CHARS_MAX] = {0};
    int needToBeFound[CHARS_MAX] = {0};
    
    int s1 = strlen(str1);
    int s2 = strlen(str2);
    
    int begin = 0;
    int end = 0;
    int count = 0;
    int left = 0;
    int right = 0;
    int minWindow = INT_MAX;
    int i = 0;
    
    //Fill the NeedToBeFound with 
    //the Count of Chars of STR2
    for (i = 0; i < s2; i++)
    {
        needToBeFound[str2[i]]++;
    }
    
    for (end = 0; end < s1; end++)
    {
        //IF CHAR is Not part of STR1, IGNORE
        if(needToBeFound[str1[end]] == 0)
            continue;
        
        hasFound[str1[end]]++;
        //If the CHAR count is same or less than MASK string
        //Increase the count
        if(hasFound[str1[end]] <= needToBeFound[str1[end]])
        {
            count++;
            
        }
        //IF THE WINDOW SIZE is satisfied    
        if(count == s2)
        {
            
            while((needToBeFound[str1[begin]] == 0) ||
                  (hasFound[str1[begin]] > needToBeFound[str1[begin]]))
            {
                if((hasFound[str1[begin]] > needToBeFound[str1[begin]]))
                    hasFound[str1[begin]]--;
                
                begin++;
            }
            if((minWindow) > (end - begin + 1))
            {
                left = begin;
                right = end;
                minWindow = (end - begin + 1);
            }
        }
    }
    printf("%d %d\n",left,right);
    return;
}

int main()
{
    char str1[] = "acbbaca";
    char str2[] = "aba";
    

    smallestSubArray(str1,str2);

    return 0;
    
}
