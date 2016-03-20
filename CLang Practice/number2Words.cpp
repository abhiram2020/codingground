#include<cstdio>
#include<string>
#include<iostream>
#include<cmath>
 
using namespace std;
 
string unitsMap[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tensMap[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
 
string NumberToWords(int number)
{
    if (number == 0)
        return "zero";
 
    if (number < 0)
        return "minus " + NumberToWords(abs(number));
 
    string words = "";
 
    if ((number / 1000000000) > 0)
    {
        words += NumberToWords(number / 1000000000) + " billion ";
        number %= 1000000000;
    }
 
    if ((number / 1000000) > 0)
    {
        words += NumberToWords(number / 1000000) + " million ";
        number %= 1000000;
    }
 
    if ((number / 1000) > 0)
    {
        words += NumberToWords(number / 1000) + " thousand ";
        number %= 1000;
    }
 
    if ((number / 100) > 0)
    {
        words += NumberToWords(number / 100) + " hundred ";
        number %= 100;
    }
 
    if (number > 0)
    {
        if (number < 20)
            words += unitsMap[number];
        else
        {
            words += tensMap[number / 10];
            if ((number % 10) > 0)
                words += "-" + unitsMap[number % 10];
        }
    }
 
    return words;
}
 
int main() 
{
	cout << NumberToWords(0)<<endl;
	cout << NumberToWords(1)<<endl;
	cout <<NumberToWords(16)<<endl;
	cout << NumberToWords(100)<<endl;
	cout << NumberToWords(118)<<endl;
	cout<<NumberToWords(200)<<endl;
	cout<<NumberToWords(219)<<endl;
	cout<<NumberToWords(800)<<endl;
	cout<<NumberToWords(801)<<endl;
	cout<<NumberToWords(1316)<<endl;
	cout<<NumberToWords(1000000)<<endl;
	cout<<NumberToWords(2000000)<<endl;
	cout<<NumberToWords(3000200)<<endl;
	cout<<NumberToWords(700000)<<endl;
	cout<<NumberToWords(9000000)<<endl;
	cout<<NumberToWords(9001000)<<endl;
	cout<<NumberToWords(123456789)<<endl;
	cout<<NumberToWords(2147483647)<<endl;
	return 0;
}
