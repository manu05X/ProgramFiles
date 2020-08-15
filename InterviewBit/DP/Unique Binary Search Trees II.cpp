/*
Unique Binary Search Trees II
Problem Description

Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A?



Problem Constraints
1 <= A <=18



Input Format
First and only argument is the integer A



Output Format
Return a single integer, the answer to the problem



Example Input
Input 1:

 1
Input 2:

 2


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Only single node tree is possible.
Explanation 2:

 2 trees are possible, one rooted at 1 and other rooted at 2.
 
*/

int Solution::numTrees(int A) {
    int dp[A+2];
    memset(dp,0,sizeof(dp));
    
    dp[0]=1,dp[1]=1;
    
    for(auto i=2;i<=A;i++)
    {
        for(auto j=1;j<=i;j++)
        {
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[A];
}





/*
class Solution {
    public:
        int numTrees(int n) {
            if(n == 0) return 1;
            if(n == 1) return 1;

            int result[n + 1];
            memset(result, 0, sizeof(result));
            result[0] = 1;
            result[1] = 1;
            if(n < 2) {
                return result[n];
            }

            for (int i = 2; i <= n; i++) {
                for (int k = 1; k <= i; k++) {
                    result[i] = result[i] + result[k - 1] * result[i - k];
                }
            }


            return result[n];
        }
};
________________________________________________________________________________________________________

 public class Solution {
    
    private long [][] dp;
    private int A;
    
	public int numTrees(int A) {
	    
	    dp = new long[A][A];
	    
	    for (int i = 0; i < A; i++)
	        Arrays.fill(dp[i], -1);
	        
	    this.A = A;
	    return (int) rec(0, A - 1);
	}
	
	public long rec(int i, int j) {
	    
	    if (i < 0 || j < 0 || i >= A || j >= A)
	        return 1;
	    
	    if (dp[i][j] != -1)
	        return dp[i][j];
	    
	    if (i >= j)
	        return dp[i][j] = 1;
	    
	    dp[i][j] = 0;
	    
	    for (int k = i; k <= j; k++) {
	        dp[i][j] += (rec(i, k - 1) * rec(k + 1, j));
	    }
	    
	    return dp[i][j];
	}
	
	
}

*/