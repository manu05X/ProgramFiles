/*
Max Sum Contiguous Subarray
Problem Description

Find the contiguous subarray within an array, A of length N which has the largest sum.



Problem Constraints
1 <= N <= 1e6
-1000 <= A[i] <= 1000



Input Format
The first and the only argument contains an integer array, A.



Output Format
Return an integer representing the maximum possible sum of the contiguous subarray.



Example Input
Input 1:

 A = [1, 2, 3, 4, -10] 
Input 2:

 A = [-2, 1, -3, 4, -1, 2, 1, -5, 4] 


Example Output
Output 1:

 10 
Output 2:

 6 


Example Explanation
Explanation 1:

 The subarray [1, 2, 3, 4] has the maximum possible sum of 10. 
Explanation 2:

 The subarray [4,-1,2,1] has the maximum possible sum of 6. 
 
*/

int Solution::maxSubArray(const vector<int> &A) {
    int max_till_now=A[0],max_ending_here=A[0];
    for(int i=1;i<A.size();i++)
    {
        max_ending_here=max(max_ending_here+A[i],A[i]);
        
        if(max_till_now<max_ending_here)
            max_till_now=max_ending_here;
    }
    return max_till_now;
}



/*
public class Solution {
	// DO NOT MODFIY THE LIST. 
	public int maxSubArray(final List<Integer> A) {
	    
	    int sum = Integer.MIN_VALUE;
	    int last = 0;
	    
	    for (int num : A) {
	        
	        last += num;
	        sum = Math.max(sum, last);
	        if (last < 0)
	            last = 0;
	    }
	    
	    return sum;
	    
	}
}
__________________________________________________________________________________________________________________

class Solution {
    public:
        int maxSubArray(const vector<int> &A) {
            int n = A.size();
            int curSum = 0, maxSum = -1000000000;
            for (int i = 0; i < n; i++) {
                curSum += A[i];
                maxSum = max(maxSum, curSum);
                if (curSum < 0) curSum = 0;
            }
            return maxSum;
        }
};
*/


