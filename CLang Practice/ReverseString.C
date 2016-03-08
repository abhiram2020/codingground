#include <stdio.h>

//Reverse a word
void ReverseWord(char* word, int n){
	char tmp;
	int  i =0;
	for(i = 0; i< n/2; ++i)
	{
		tmp = word[i];
		word[i] = word[n-i-1];
		word[n-i-1] = tmp;
	}
}

void ReverseString(char* str, int n)
{
	//Reverse the whole string first
	ReverseWord(str,n);
	
	int i = 0;
	int j = 0;
	for(j = 0; j < n+1; j++)
	{
		if(str[j] == ' ' || str[j] == '\0')
		{
			ReverseWord(str+i, j-i);
			while(str[++j] == ' '); // Skip continous white spaces
			i = j;
		}
	}
}


int main()
{
	char str[30] = "This is a sentence";

	ReverseString(str,18);

	printf("%s",str);

	return 0;
}
