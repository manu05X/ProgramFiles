/*
Reverse Bits

Reverse the bits of an 32 bit unsigned integer A.


Problem Constraints
0 <= A <= 232
    


Input Format
First and only argument of input contains an integer A.


Output Format
Return a single unsigned integer denoting minimum xor value.


Example Input
Input 1:
 0
Input 2:
 3
     


Example Output
Output 1:
 0
Output 2:
 3221225472
     


Example Explanation
Explanation 1:
        00000000000000000000000000000000    =>      00000000000000000000000000000000
Explanation 2:      
        00000000000000000000000000000011    =>      11000000000000000000000000000000
     


*/

//sol->

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rev_num=0;
    for(int i;i<32;i++)
    {
        if((A & (1<<i)))
            rev_num=rev_num|1<<(31-i);
    }
    return rev_num;
}



/*
unsigned int swapBits(unsigned int x, unsigned int i, unsigned int j) {
    unsigned int lo = ((x >> i) & 1);
    unsigned int hi = ((x >> j) & 1);
    if (lo ^ hi) {
        x ^= ((1U << i) | (1U << j));
    }
    return x;
}

unsigned int Solution::reverse(unsigned int x) {
    unsigned int n = sizeof(x) * 8;
    for (unsigned int i = 0; i < n/2; i++) {
        x = swapBits(x, i, n-i-1);
    }
    return x;
}

----------------------------------------------
public class Solution {
	public long reverse(long A) {
	    long rev = 0;
	    
	    for (int i = 0; i < 32; i++) {
	        rev <<= 1;
	        if ((A & (1 << i)) != 0)
	            rev |= 1;
	    }
	    
	    return rev;
	    
	}
}
---------------------------------
class Solution:
    # @param A : unsigned integer
    # @return an unsigned integer
    def reverse(self, A):
        i = 31
        ret = 0
        while i >= 0:
            temp = ((A & 1<<i) >> i)&1
            ret = ret | temp << (31-i)
            i -= 1
        return ret
*/