/*
Divide Integers

Divide two integers without using multiplication, division and mod operator. Return the floor of the result of the division. Also, consider if there can be overflow cases i.e output is greater than INT_MAX, return INT_MAX. NOTE: INT_MAX = 2^31 - 1  


Problem Constraints
-231 <= A, B <= 231-1 B!= 0  


Input Format
First argument is an integer A denoting the dividend.
Second argument is an integer B denoting the divisor.


Output Format
Return an integer denoting the floor value of the division.


Example Input
Input 1:
 A = 5
 B = 2
Input 2:
 A = 7
 B = 1
  


Example Output
Output 1:
 2
Output 2:
 7
  


Example Explanation
Explanation 1:
 floor(5/2) = 2

*/

//sol->

int Solution::divide(int A, int B) 
{
     if(A == 0 || B == 1) 
        return A;
    else if(B == 0 || (B == -1 && A == INT_MIN))
        return INT_MAX;
            
    int res = 0;
    
    bool isNeg = false;
         
    if((A^B) < 0) isNeg = true;
     
    long x = abs((long)A);
    long y = abs((long)B);
     
    while(x >= y)
    {
        int k = 1;
        
        while((y<<k) >= (y<<k-1) && (x-(y<<k)) >= 0) 
            k++;
        res += (1<<k-1);
        
        x = x-(y<<k-1);
    }
    
    if(isNeg) return -1*res;
    
    return res;
}






/*
int Solution::divide(int dividend, int divisor) {
    assert(dividend >= -2147483648 && dividend <= 2147483647);
    assert(divisor >= -2147483648 && divisor <= 2147483647);
    
    long long n = dividend, m = divisor;
    // determine sign of the quotient
    int sign = n < 0 ^ m < 0 ? -1 : 1;

    // remove sign of operands
    n = abs(n), m = abs(m);

    // q stores the quotient in computation
    long long q = 0;

    // test down from the highest bit
    // accumulate the tentative value for valid bits
    for (long long t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;

    // assign back the sign
    if (sign < 0) q = -q;

    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}
-------------------------------------------
public class Solution {
	public int divide(int dividend, int divisor) {
	    
	    if (divisor == 0)
	        return Integer.MAX_VALUE;
	    
	    if (dividend == Integer.MIN_VALUE && divisor == -1)
	        return Integer.MAX_VALUE;
	        
	    if (dividend == divisor)
	        return 1;
	        
	    if (divisor == 1)
	        return dividend;
	        
	    if (divisor == -1)
	        return -dividend;
	        
	    if (divisor == 2)
	        return (dividend >> 1);
	        
	    int res = (int) res(dividend, divisor);
	    
	    return res;
	}
	
	private long res(long dividend, long divisor) {
	     boolean sign = false;
	    
	    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
	        sign = true;
	    
	    
    	 dividend = Math.abs(dividend);
    	    
    	 divisor = Math.abs(divisor);
	    
	    int result = (int) Math.floor(Math.exp(Math.log(dividend) - Math.log(divisor)));
	    
	    return sign ? -result : result;
	}
	
}
    

*/