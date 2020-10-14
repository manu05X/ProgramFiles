/*
Longest Palindromic Subsequence
Problem Description

Given a string A. Find the longest palindromic subsequence (A subsequence which does not need to be contiguous and is a palindrome).

You need to return the length of longest palindromic subsequence.



Problem Constraints
1 <= length of(A) <= 103



Input Format
First and only integer is a string A.



Output Format
Return an integer denoting the length of longest palindromic subsequence.



Example Input
Input 1:

 A = "bebeeed"
Input 2:

 A = "aedsead"


Example Output
Output 1:

 4
Output 2:

 5


Example Explanation
Explanation 1:

 The longest palindromic subsequence is "eeee", which has a length of 4.
Explanation 2:

 The longest palindromic subsequence is "aedea", which has a length of 5.

*/

int Solution::solve(string A) {
    int n = A.size(); 
   int i, j, cl; 
   int L[n][n];  // Create a table to store results of subproblems 
  
  
   // Strings of length 1 are palindrome of lentgh 1 
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    // Build the table. Note that the lower diagonal values of table are useless and not filled in the process.
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (A[i] == A[j] && cl == 2) 
               L[i][j] = 2; 
            else if (A[i] == A[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1];
    
}


//Method 2
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;++i)
            dp[i][i] = 1;
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

//Method 3
class Solution {
public:
    int dp[1003][1003];
    int longestPalindromeSubseq(string s) {
        string t = s;
		//reverse the given string
        reverse(s.begin(),s.end());
        int n = s.size();
        // find longest common subsequence using dynamic programming
        for(int i = 0;i<= n;i++)
        {
            for(int j = 0;j<= n;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if(t[i -1] == s[j -1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i][j-1], dp[i -1][j]);
                }
            }
        }
        return dp[n][n];
    }
};


/*
class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def solve(self, A, B):
    
        m = len(A)
        n = len(B) 
        L = [[0 for i in range(n+1)] for j in range(0, n+1)] 
        
        i = 0
        j = 0
        
        for i in range(0, m+1):
            for j in range(0, n+1):
                
                #base condition
                if(i == 0 or j == 0): 
                    L[i][j] = 0
                elif(A[i-1] == B[j-1]): 
                    L[i][j] = L[i-1][j-1] + 1 
                else:
                    L[i][j] = max(L[i-1][j], L[i][j-1]) 
        
        return L[m][n]
*/

/*
class Solution {
public:
    // Bottom-up approach
    // TC: O(N*N), SC: O(N*N)
    int longestPalindromeSubseqTabular(string& s) {
        if(s.empty())
            return 0;
        
        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        vector<vector<int> > dp(N, vector<int>(N, 0));
        
        // all single chars are palindromic
        for(int i = 0; i < N; i++)
            dp[i][i] = 1;
        
        for(int l = 1; l < N; l++) {
            // starting index of window
            for(int i = 0; i < N - l; i++) {
                // ending index of window
                int j = i + l;
                
                // if there are only two chars
                if((j - i + 1) == 2) {
                    // if the chars are same, then that contributes 2, otherwise since
                    // individually they are palindromic so max length 1
                    dp[i][j] = 1 + (s[i] == s[j]);
                }
                else {
                    // for s[i:j]:
                    // longest palindrome length in s[i+1 : j-1] and +1 if s[i] == s[j]
                    // if s[i] != s[j], longest length palindrome = Max of longest palin in s[i:j-1] and s[i+1:j]
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
    
    // Using memoization
    // TC: O(N*N), SC: O(N*N)
    int longestPalindSubseqRec(vector<vector<int> >& dp, string& s, int i, int j) {
        if(i > j)
            return 0;
        // when one char
        if(i == j)
            return dp[i][j] = 1;
        
        if(dp[i][j] == -1) {
            if(s[i] == s[j])
                dp[i][j] = 2 + longestPalindSubseqRec(dp, s, i+1, j-1);
            else
                dp[i][j] = max(longestPalindSubseqRec(dp, s, i+1, j),
                               longestPalindSubseqRec(dp, s, i, j-1));
        }
        return dp[i][j];
    }
    
    // Recursive driver
    int longestPalindSubseqRecDriver(string& s) {
        if(s.empty())
                return 0;

        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        vector<vector<int> > dp(N, vector<int>(N, -1)); 
        
        return longestPalindSubseqRec(dp, s, 0, N-1);
    }
    
    int longestPalindromeSubseq(string s) {
        return longestPalindSubseqRecDriver(s);
        //return longestPalindromeSubseqTabular(s);
    }
};
*/

