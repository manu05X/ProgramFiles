/*
Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.
*/

//sol->

int Solution::numSetBits(unsigned int A) {
    int c = 0;
    /*while(A)  //Simple O(log n) approach
    {
        if (A & 1)
            ++c;
        A >>= 1;
    }*/
    while(A!=0) //Brian Kernighan’s Algorithm: iterates only over set bits
    {
        A &= A-1;
        ++c;
    }
    return c;
}



/*
public class Solution {
	public int numSetBits(long a) {
	    int count = 0;
	    while (a > 0){
	        count+= a%2;
	        a = a>> 1;
	    }
	    return count;
	}
}

----------------------------------------------
int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=0;
    for(int i=0;i<32;i++){
        if((A&(1<<i))!=0){
           // cout<<(1<<i)<<endl;
            count++;
        }
    }
    return count;
}
---------------------------------

*/