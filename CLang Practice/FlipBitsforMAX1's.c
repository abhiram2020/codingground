#include <stdio.h>
#include <stdlib.h>

void flipbits(int a[], int length)
{
    int maxDiff = 0;
	
	int flipStartIndex = 0;
	int flipEndIndex = 0;
	
	int onesToFlip = 0;
	int totalNumberOfOnes = 0;

	int currentDiff = 0;
	int currentStart = 0;
	int currentOnesToFlip = 0;

	for (int i = 0; i < length; i++) 
	{
	    if (a[i] == 0) 
	    {
			currentDiff -= 1;
	    } 
	    else 
	    {
			currentDiff += 1;
			currentOnesToFlip++;
			totalNumberOfOnes++;
	    }
	    if (currentDiff < maxDiff) 
	    {
			maxDiff = currentDiff;
			flipStartIndex = currentStart;
			flipEndIndex = i;
			onesToFlip = currentOnesToFlip;
	    } 
	    else if (currentDiff > 0) 
	    {
			currentDiff = 0;
			currentStart = i + 1;
			currentOnesToFlip = 0;
	    }
	}
	printf("INDEXES %d %d\n",flipStartIndex,flipEndIndex);
	printf("ONES to FLIP: %d\nZEROS to FLIP: %d", 
	        onesToFlip,totalNumberOfOnes-onesToFlip);
}


int main()
{
    int a[] = {0,1,1,0,1,0,0,1};
    int sz = 8;
    flipbits(a,sz);
    return 0;
}
