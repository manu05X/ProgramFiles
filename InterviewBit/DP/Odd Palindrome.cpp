/*
Odd Palindrome
Problem Description

A palindrome string is a string which reads the same forward and backward. If a palindrome string is of odd length l, then (l+1)/2th character (1 index based) is said to be the centre of the palindrome.

You are given a string A. Return an array X of integers where X[i] = (number of odd length palindrome subsequence of A with A[i] as the centre) modulo (109 + 7).

A subsequence of A is a string which can be derived from A by deleting some of its character.



Problem Constraints
1 <= length(A) <= 1000
Every character of A will be a lowercase English letter 'a' - 'z'.



Input Format
First and only argument is a string A.



Output Format
Return an integer array X as mentioned in the question.



Example Input
Input 1:

 A = "xyzx"
Input 2:

 A = "ababzz"


Example Output
Output 1:

 [1, 2, 2, 1]
Output 2:

 [1, 2, 2, 1, 1, 1]


Example Explanation
Explanation 1:

 
 Index(i)  |   Palindrome subsequences with centre i
   0       |   a        
   1       |   y, xyx
   2       |   z, xzx
   3       |   x
 So, output array is [1, 2, 2, 1]

Explanation 2:

 Index(i)  |  Palindrome subsequences with centre i
   0       |  a    
   1       |  b, aba
   2       |  a, bab
   3       |  b
   4       |  z
   5       |  z
 So, output array is [1, 2, 2, 1, 1, 1]  

*/


vector<int> Solution::solve(string A) {

    int n = A.length(); 
    
    int Mod = 1000000007;
    
    // Created dp of size n+2 * n+2 so that, we don't have to check boundary conditions.
    long long int dp[n+2][n+2]; 
    memset(dp, 0, sizeof dp); 
        
    for(int len = n+1;len>=0;len--)
    {
        for(int i=0;i+len < n+2;i++)
        {
            int j = i+len;
            
        // base condtition, Number of ways to choose palindromic subsequence without any character on left or right is 1.
            if(i==0 || j == n+1) dp[i][j] = 1;
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j+1];
                
                // subtract dp[i-1][j+1], As dp[i-1][j] contains dp[i-1][j+1] and dp[i][j+1] contains dp[i-1][j+1] 
                if(A[i-1] != A[j-1]) dp[i][j] -= dp[i-1][j+1];
            }
            dp[i][j] = (dp[i][j] + Mod) % Mod;
        }
    }
    
    vector<int> ans;
    
    for(int i=1;i<=n;i++)
    {
        if(i==1 || i==n) ans.push_back(1);
        else    ans.push_back(dp[i-1][i+1]);    
    }
    
    return ans;
}