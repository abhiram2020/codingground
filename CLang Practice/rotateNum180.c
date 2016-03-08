#include <stdio.h>
#include <stdlib.h>

int rotateNum(int num)
{
    int r = 0;
    int q = 0;
    int result = 0;
    
    q = num;
    while(q > 0)
    {
        //Get the last Digit
        r = q%10;
        
        //Remove the Last Digit from Input
        q = q/10;
        
        if(r != 0 && r != 1 && r != 6 && r != 8 && r != 9)
            return 0;
        
        //Change the Digit for 180 Degree Rotation
        if(r == 9)
            r = 6;
        else if(r == 6)
            r = 9;
        
        //Form the Rotated Number
        result = r + (result * 10);
    }
    return result;
}

int main()
{
    int num = 69;
    int result = rotateNum(num);
    if(result && result == num)
        printf("R0TATED Number is same as INPUT\n");
    else
         printf("RATATED Number is NoT same as INPUT\n");
         
    return 0;
}
