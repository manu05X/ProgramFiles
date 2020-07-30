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