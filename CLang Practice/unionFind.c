#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int find(int elem,int *set_id,int *set_sz)
{
    while(elem != set_id[elem])
    {
        elem = set_id[elem];
    }
    return elem;
}

int merge(int elem1,int elem2,int *id,int *sz,int *cnt)
{
    int i = find(elem1,id,sz);
    int j = find(elem2,id,sz);
    
    if (i == j) 
        return;
		
	// make smaller root point to larger one
    if(sz[i] < sz[j])
    {
        
		id[i] = j; 
		sz[j] += sz[i]; 
	}
	else
	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
	*cnt -= 1;
}

int main()
{
    int length = 4;
    int set_id[length];
    int set_sz[length];
    int i;
    int count = length;
    
    for(i = 0; i < length; i++)
    {
	    set_id[i] = i;
	    set_sz[i] = 1;
    }

	printf("Element 2 is in SET: %d\n",find(2,set_id,set_sz));
	printf("Element 1 is in SET: %d\n",find(1,set_id,set_sz));
	merge(2,3,set_id,set_sz,&count);
	printf("Element 3 is in SET: %d ,#DISJOINT SETS: %d\n",find(3,set_id,set_sz),count);

	return 0;
}
