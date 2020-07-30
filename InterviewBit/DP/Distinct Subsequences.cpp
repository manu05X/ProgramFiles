/*
Distinct Subsequences
Problem Description

Given two sequences A and B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).



Problem Constraints
1 <= length(A), length(B) <= 700



Input Format
The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format
Return an integer representing the answer as described in the problem statement.



Example Input
Input 1:

 A = "abc"
 B = "abc"
Input 2:

 A = "rabbbit" 
 B = "rabbit" 


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 Both the strings are equal.
Explanation 2:

 These are the possible removals of characters:
    => A = "ra_bbit" 
    => A = "rab_bit" 
    => A = "rabb_it"

 Note: "_" marks the removed character.

*/


/**
 * Solution (DP):
 * We keep a m*n matrix and scanning through string A, while
 * m = B.length() + 1 and n = A.length() + 1
 * and each cell in matrix Path[i][j] means the number of distinct subsequences of 
 * B.substr(1...i) in A(1...j)
 * 
 * Path[i][j] = Path[i][j-1]            (discard A[j])
 *              +     Path[i-1][j-1]    (A[j] == B[i] and we are going to use A[j])
 *                 or 0                 (A[j] != B[i] so we could not use A[j])
 * while Path[0][j] = 1 and Path[i][0] = 0.
 */
        
int Solution::numDistinct(string A, string B) {
    int m = B.length();
    int n = A.length();
    if (m > n) return 0;    // impossible for subsequence
    vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
    for (int k = 0; k <= n; k++) path[0][k] = 1;    // initialization

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            path[i][j] = path[i][j - 1] + (B[i - 1] == A[j - 1] ? path[i - 1][j - 1] : 0);
        }
    }

    return path[m][n];

}

/*
int Solution::numDistinct(string A, string B) {
    int A_size=A.size(),B_size=B.size();
    
    if(B_size>A_size)
        return 0;
        
    vector<vector<int>>dp(B_size+1,vector<int>(A_size+1,0));
    
    for(int i=0;i<=A_size;i++)
        dp[0][i]=1;
        
    for(int i=1;i<=B_size;i++)
    {
        for(int j=i;j<=A_size;j++)
        {
            if(A[j-1]==B[i-1])
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    return dp[B_size][A_size];
}
_______________________________________________
JAVA:

public class Solution {
    
    private String S;
    private String T;
    int [][] dp;
	int n;
	int nT;
	    
	public int numDistinct(String S, String T) {
	    if (T.length() > S.length())
	        return 0;
	    
	    n = S.length();
	    nT = T.length();
	    this.S = S;
	    this.T = T;
	    dp = new int[n][nT];
	    
	    for (int i = 0; i < n; i++)
	        Arrays.fill(dp[i], -1);
	    
	    return rec(0, 0);
	}
	
	public int rec(int sIndex, int tIndex) {
	    
	    if (tIndex == nT)
	        return 1;
	        
	    if (sIndex >= n)
	        return 0;
	    
	    if (dp[sIndex][tIndex] != -1)
	        return dp[sIndex][tIndex];
	        
	    int res = 0;
	    
	    if (S.charAt(sIndex) == T.charAt(tIndex))
	        res = rec(sIndex + 1, tIndex + 1);
	    
	    res += rec(sIndex + 1, tIndex);
	    
	    return dp[sIndex][tIndex] = res;
	    
	}
	
	
}


*/