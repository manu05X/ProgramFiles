/*
Single Number

Given an array of integers A, every element appears twice except for one. Find that single one.

NOTE: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


Problem Constraints
2 <= |A| <= 2000000
0 <= A[i] <= INTMAX
  


Input Format
First and only argument of input contains an integer array A.


Output Format
Return a single integer denoting the single element.


Example Input
Input 1:
 A = [1, 2, 2, 3, 1]
Input 2:
 A = [1, 2, 2]
   


Example Output
Output 1:
 3
Output 2:
 1
  


Example Explanation
Explanation 1:
3 occurs once.
  Explanation 2:      
1 occurs once.
*/

//sol->

int Solution::singleNumber(const vector<int> &A) {
    int sig_num=0;
    for(int i=0;i<A.size();i++)
    {
        sig_num=sig_num xor A[i];
    }
    return sig_num;
}


/*
int Solution::singleNumber(const vector<int> &A) {
       int n = A.size();
       int result = 0;
       for (int i = 0; i < n; i++) {
           result ^= A[i];
       }
       return result;
}

----------------------------------------------
public class Solution {
	// DO NOT MODIFY THE LIST
	public int singleNumber(final List<Integer> A) {
	    int num = 0;
	    
	    for (int val : A) {
	        num ^= val;
	    }
	    
	    return num;
	    
	}
}
---------------------------------
class Solution:
    # @param A : tuple of integers
    # @return an integer
    def singleNumber(self, A):
        ret = A[0]
        for i in range(1,len(A)):
            ret ^= A[i]
        return ret
*/