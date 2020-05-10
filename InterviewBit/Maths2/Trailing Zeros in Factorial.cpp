/*
Trailing Zeros in Factorial
Problem Description
Given an integer A, return the number of trailing zeroes in A! i.e. factorial of A. Note: Your solution should run in logarithmic time complexity.    


Problem Constraints
1 <= A <= 109


Input Format
First and only argument is a single integer A.


Output Format
Return a single integer denoting number of zeroes.


Example Input
Input 1
 A = 5
Input 2:
 A = 6
 


Example Output
Output 1:
 1
Output 2:
 1
 


Example Explanation
Explanation 1:
 A! = 120.
 Number of trailing zeros = 1. So, return 1.
Explanation 2:
 A! = 720 
 Number of trailing zeros = 1. So, return 1.


*/

//sol->

int Solution::trailingZeroes(int A) {
    int count=0;
    for(int i=5;A/i>=1;i=i*5)
        count=count+A/i;
        
    return count;
}





/*
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while (n / 5 > 0) {
            sum += (n / 5);
            n /= 5;
        }
        return sum;
    }
};
--------------------------------
public class Solution {
	public int trailingZeroes(int A) {
	    
	    int count = 0;
	    
        long num = 5;
        
        while (num <= 1L * A) {
            count += ((int) (A / num));
            num *= 5;
        }
	    
	    return count;
	    
	}
}
------------------------------------
class Solution:
    # @param A : integer
    # @return an integer
    def trailingZeroes(self, A):
        ret = 0
        while A != 0:
            ret += (A/5)
            A /= 5
        return ret


*/
