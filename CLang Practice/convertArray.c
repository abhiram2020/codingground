
#include <iostream>
#include <string.h>
using namespace std;
void swapper(int *a,int *b)
{
    int temp;
    temp = *a,
    *a = *b;
    *b = temp;
}
int get_idx(int cur,int num)
{
    return (((cur%3)*num) +(cur/3));
}

void convertarray(int arr[],int len)
{
    int num = len/3;
    int swap;
    
    for(int i = 0; i < len; i++)
    {
        swap = get_idx(i,num);
        while(swap < i)
            swap = get_idx(swap,num);
        swapper(&arr[swap],&arr[i]);
    }
    
    for(int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
}
// Driver program to test above functions
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    convertarray(arr,len);
    return 0;
}
