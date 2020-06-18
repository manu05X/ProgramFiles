/*
Square Root of Integer


Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.



Problem Constraints
0 <= A <= 1010



Input Format
The first and only argument given is the integer A.



Output Format
Return floor(sqrt(A))



Example Input
Input 1:

 11
Input 2:

 9


Example Output
Output 1:

 3
Output 2:

 3


Example Explanation
Explanation:

 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 When A = 9 which is a perfect square of 3, 
 so we return 3.
 
 
 
*/

int Solution::sqrt(int A) {
    if(A==0 || A==1)
        return A;
    int start=0,end=A;
    int ans;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid<=A/mid)
        {
            start=mid+1;
            ans=mid;
        }
        else
            end=mid-1;
    }
    return ans;
}



/*

public class Solution {
	public int sqrt(int A) {
	    
	    int low, high, root;
	    int mid;
	    int num;
	    
	    low = 1;
	    high = A;
	    root = 0;
	    
	    while (low <= high) {
	        
	        mid = (low + high) / 2;
	        
	        if (mid == A / mid && (A % mid == 0))
	            return mid;
	            
	        if (mid <= A / mid) {
	            root = mid;
	            low = mid + 1;
	        } else {
	            high = mid - 1;
	        }
	        
	    }
	    
	    return root;
	    
	}
}


class Solution:
    # @param A : integer
    # @return an integer
    def sqrt(self, A):
        if A == 1:
            return 1
        ret = int(A**0.5)
        return ret
        low = 0
        high = A/2 + 1
        while low+1<high:
            mid=low+(high-low)/2
            square=mid**2
            if square==A:
                return mid
            elif square<A:
                low=mid
            else:
                high=mid
        return low

*/
