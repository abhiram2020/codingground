#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

bool areConsecutive(int arr[], int n)
{
    int  i = 0;
    int min = INT_MAX;
    for (i - 0; i < n ; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    
    for(i = 0; i < n; i ++)
    {
        // IF Difference between any 2 Elements
        // is greater than size of array, its not Consecutive
        if((arr[i] - min) > n)
            return false;
        
        if(arr[abs(arr[i]) - min] < 0)
            return false;
        
        arr[abs(arr[i]) - min] = -arr[abs(arr[i]) - min];
    }
    
    for(i = 0; i < n; i ++)
    {
        arr[i] = abs(arr[i]);
    }
    return true;
}


/* Driver program to test above functions */
int main()
{
	int arr1[]= {76,78,76,77,73,74,76};
	int arr2[]= {76,78,75,77,73,74};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	if(areConsecutive(arr1, n) == true)
		printf(" Array elements are consecutive \n");
	else
		printf(" Array elements are not consecutive \n");
		
    n = sizeof(arr2)/sizeof(arr2[0]);
    if(areConsecutive(arr2, n) == true)
		printf(" Array elements are consecutive \n");
	else
		printf(" Array elements are not consecutive \n");

	getchar();
	return 0;
}
