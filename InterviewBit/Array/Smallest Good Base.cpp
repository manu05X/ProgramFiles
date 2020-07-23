/*
Smallest Good Base
Given an integer A, we call k >= 2 a good base of A, if all digits of A base k are 1. Now given a string representing A, you should return the smallest good base of A in string format.


Input Format

The only argument given is the string representing A.
Output Format

Return the smallest good base of A in string format.
Constraints

3 <= A <= 10^18
For Example

Input 1:
    A = "13"
Output 1:
    "3"     (13 in base 3 is 111)

Input 2:
    A = "4681"
Output 2:
    "8"     (4681 in base 8 is 11111).

*/

//sol->

size_t try_k(size_t n, int k) 
{
    double ord = 1.0 / (k-1);
    double root = pow(n, ord); //O(log n) for required floating point precission
    size_t a = floor(root);
    
    if (a < 2) return 0;
        size_t sum = 1;
    for (int i = 0; i < k-1; i++) sum = sum * a + 1;  // k-1 time, which is O(log n)
        if (sum != n) return 0;
    return a;
}

string Solution::solve(string A) {
    size_t n = stoull(A);
    
    for (int k = 63; k >= 3; k--) 
    {
        size_t result = try_k(n, k);
        
        if (result > 0) return to_string(result);
    }
    return to_string(n-1);
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