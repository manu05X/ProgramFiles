/*
Interleaving Strings
Problem Description

Given A, B, C find whether C is formed by the interleaving of A and B.



Problem Constraints
1 <= length(A), length(B) <= 100

1 <= length(C) <= 200



Input Format
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.



Output Format
Return 1 if string C is formed by interleaving of A and B else 0.



Example Input
Input 1:

 A = "aabcc"
 B = "dbbca"
 C = "aadbbcbcac"
Input 2:

 A = "aabcc"
 B = "dbbca"
 C = "aadbbbaccc"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)
Explanation 2:

 It is not possible to get C by interleaving A and B.
 
*/

string a,b,v;
bool dp(int in,int i,int j)
{
    if(in==v.size())
        return true;
    if(i==a.size() && j==b.size())
        return false;
        
    bool uso=false;
    if(i<a.size() && v[in]==a[i])
        uso=dp(in+1,i+1,j);
    if(uso)
        return true;
    if(j<b.size() && v[in]==b[j])
        uso=dp(in+1,i,j+1);
    if(uso)
        return true;
    return false;
        
}
int Solution::isInterleave(string A, string B, string C) {
    a=A;
    b=B;
    v=C;
    
    return dp(0,0,0);
}


/*
int Solution::isInterleave(string A, string B, string C) {
    int M = A.size(), N = B.size(); 
  
    // Let us create a 2D table to store solutions of subproblems.  dp[i][j] will be true if C[0..i+j-1] is an interleaving of A[0..i-1] and B[0..j-1]. 
    bool dp[M + 1][N + 1]; 
  
    memset(dp, 0, sizeof(dp)); // Initialize all values as false. 
  
    // C can be an interleaving of A and B only of sum of lengths of A & B is equal to length of C. 
    if ((M + N) != C.size()) 
        return false; 
  
    // Process all characters of A and B 
    for (int i = 0; i <= M; ++i) { 
        for (int j = 0; j <= N; ++j) { 
            // two empty strings have an empty string as interleaving 
            if (i == 0 && j == 0) 
                dp[i][j] = true; 
  
            // A is empty 
            else if (i == 0) { 
                if (B[j - 1] == C[j - 1]) 
                    dp[i][j] = dp[i][j - 1]; 
            } 
  
            // B is empty 
            else if (j == 0) { 
                if (A[i - 1] == C[i - 1]) 
                    dp[i][j] = dp[i - 1][j]; 
            } 
  
            // Current character of C matches with current character of A, but doesn't match with current character of B 
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
                dp[i][j] = dp[i - 1][j]; 
  
            // Current character of C matches with current character of B, but doesn't match with current character of A 
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                dp[i][j] = dp[i][j - 1]; 
  
            // Current character of C matches with that of both A and B 
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]); 
        } 
    } 
  
    return dp[M][N]; 
    
}
__________________________________________________________________________________________________________________

public class Solution {
    
    int nA, nB, nC;
    private int mem[][];
    private String A, B, C;
    
	public int isInterleave(String A, String B, String C) {
	    
	    if (A == null || B == null || C == null)
	        return 0;
	    
	    nA = A.length();
	    nB = B.length();
	    nC = C.length();
	    
	    
	    if (nA + nB != nC)
	        return 0;
	    
	    mem = new int[nA + 1][nB + 1];
	    
	    for (int i = 0; i <= nA; i++)
	        Arrays.fill(mem[i], -1);
	    
	    this.A = A;
	    this.B = B;
	    this.C = C;
	    
	    return rec(0, 0);
	    
	}
	
	
	public int rec(int nA, int nB) {
	    
	    if (nA + nB == nC)
	        return 1;
	    
	    if (mem[nA][nB] != -1)
	        return mem[nA][nB];
	    
	    char a = nA < this.nA ? A.charAt(nA) : '~';
	    char b = nB < this.nB ? B.charAt(nB) : '~';
	    char c = C.charAt(nA + nB);
	    
	    int status = 0;
	    
	    if (a == c) {
	        status = rec(nA + 1, nB);
	    }
	    
	    if (b == c) {
	        status |= rec(nA, nB + 1);
	    }
	    
	    return mem[nA][nB] = status;
	    
	}
	
}

*/