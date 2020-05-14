/*
Single Number II

Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

NOTE: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?



Problem Constraints
2 <= A <= 5*106
0 <= A <= INTMAX
   


Input Format
First and only argument of input contains an integer array A.


Output Format
Return a single integer.


Example Input
Input 1:
 A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Input 2:
 A = [0, 0, 0, 1]
   


Example Output
Output 1:
 4
Output 2:
 1
   


Example Explanation
Explanation 1:
 4 occurs exactly once in Input 1.
 1 occurs exactly once in Input 2.
     


*/

//sol->

int Solution::singleNumber(const vector<int> &A) {
    int res=0,x;
    
    for(int i=0;i<32;i++)
    {
        x=1<<i;
        int sum=0;
        for(int j=0;j<A.size();j++)
        {
            if(A[j]&x)
                sum++;
        }
        if(sum%3)
            res=res|x;
    }
return res;
        
}




/*
Approach 1:

int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}

Approach 2:
int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}

----------------------------------------------
public class Solution {
	// DO NOT MODIFY THE LIST
	
	public int singleNumber(final List<Integer> A) {
	    int [] bits;
	    bits = new int[32];
	    
	    for (int num : A) {
	        
	        for (int i = 0; i < 32; i++) {
	            bits[i] += (1 & (num >> i));
	            bits[i] %= 3;
	        }
	        
	    }
	    
	    int number = 0;
	    
	    for (int i = 31; i >= 0; i--) {
	        number = number * 2 + bits[i];
	    }
	    
	    
	    return number;
	    
	}
	
}
---------------------------------
class Solution:
    # @param A : tuple of integers
    # @return an integer
    def singleNumber(self, A):
        ones = 0
        twos = 0
        common_mask = 0
        for a in A:
            twos |= ones & a
            ones ^= a
            common_mask = ~(ones & twos)
            
            ones &= common_mask
            twos &= common_mask
        return ones
*/