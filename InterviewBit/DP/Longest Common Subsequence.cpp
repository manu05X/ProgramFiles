/*
Longest Common Subsequence
Problem Description

Given two strings A and B. Find the longest common subsequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= Length of A, B <= 1005



Input Format
First argument is a string A.
Second argument is a string B.



Output Format
Return an integer denoting the length of the longest common subsequence.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"
Input 2:

 A = "aaaaaa"
 B = "ababab"


Example Output
Output 1:

 5
Output 2:

 3


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5.
Explanation 2:

 The longest common subsequence is "aaa", which has a length of 3.

*/

int Solution::solve(string A, string B) {
    int m=A.size(),n=B.size();
    
    int L[m+1][n+1];
    int i,j;
    
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 ||j==0)
                L[i][j]=0;
                
            else if(A[i-1]==B[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];
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