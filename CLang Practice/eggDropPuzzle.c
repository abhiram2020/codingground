#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int max(int a, int b) 
{ 
    return (a > b)? a: b; 
    
}

int eggdrop(int eggs, int floors)
{
    int i,j;
    int res,min = INT_MIN;
    
    //If The No of Floors is 0, return 0
    //If the No of Floors is 1, return 1
    if(floors == 0 || floors == 1)
        return floors;
        
    //IF only one egg is left, return the floor
    if(eggs == 1)
        return floors;
        
    
    for(j = 1; j<=floors; j++)
    {
            res = max(eggdrop(eggs-1,j-1),eggdrop(eggs,floors-j));
            if(res < min)
                min = res;
    }
    
    return min+1;
}

int eggdropdp(int n,int k)
{
    int eggdrop[n+1][k+1];
    int x,i,j,res;
    
    for(i = 1;i<=n;i++)
    {
        eggdrop[i][0] = 0;
        eggdrop[i][1] = 1;
    }
    
    for(j = 1; j<=k;j++)
        eggdrop[1][j] = j;
        
    
    for(i = 2; i<=n;i++)
    {
        for(j = 2; j<=k;j++)
        {
            eggdrop[i][j] = INT_MAX;
            for(x=1;x<=j;x++)
            {
                res = 1+max(eggdrop[i-1][x-1],eggdrop[i][j-x]);
                if(res < eggdrop[i][j])
                    eggdrop[i][j] = res;
            }
        }
    }
    
    return eggdrop[n][k];
}


int main()
{
    
    int eggs = 2;
    int floors = 10; 
    
    printf("Minimum number of Trails: %d\n",eggdropdp(eggs,floors));
    
    return 0;
}
