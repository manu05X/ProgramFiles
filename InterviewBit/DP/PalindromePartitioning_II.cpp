/*
Palindrome Partitioning II
Problem Description

Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Problem Constraints
1 <= length(A) <= 501



Input Format
The first and the only argument contains the string A.



Output Format
Return an integer, representing the minimum cuts needed.



Example Input
Input 1:

 A = "aba"
Input 2:

 A = "aab"


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 "aba" is already a palindrome, so no cuts are needed.
Explanation 2:

 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
		
*/

#define MAX 1002
int memo[MAX][MAX];
string v;
bool ispa(int i,int j)
{
    while(i<=j)
    {
        if(v[i]!=v[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int dp(int in,int i)
{
    if(i==v.size())
    {
        if(!ispa(in,i-1))
            return (1<<30);
        else
            return 0;
    }
    if(memo[in][i])
        return memo[in][i];
    if(ispa(in,i))
    {
        return memo[in][i]=min(1+dp(i+1,i+1),dp(in,i+1));
    }
    else
    {
        return memo[in][i]=dp(in,i+1);
    }
    
}
int Solution::minCut(string A) {
    v=A;
    int r=(A.size()-1);
    memset(memo,0,sizeof(memo));
    return min(r,dp(0,0));
}


/*
int Solution::minCut(string A) { int x=A.size(); int c[x]; int p[x][x]; int i,j,l; for(i=0;i<x;i++) p[i][i]=1;

for(l=2;l<=x;l++)
{
    for(i=0;i<x-l+1;i++)
    {
         j=i+l-1;
        if(l==2)
        p[i][j]=(A[i]==A[j]);
        else
        p[i][j]=(A[i]==A[j])&&(p[i+1][j-1])?1:0;
    }
}
for(i=0;i<x;i++)
{
    if(p[0][i]==1)
    c[i]=0;
    else
    {
        c[i]=INT_MAX;
        for(j=0;j<i;j++)
        {
            if(p[j+1][i]==1 && 1+c[j]<c[i])
             c[i]=c[j]+1;
        }
        
    }
    
}

int y=c[x-1];

return y; }
____________________________________________________________________________________________________________________

public class Solution {
    
    private int isPalin[][];
    private int dp[];
    private int N;
    private String A;
    
	public int minCut(String A) {
	    
	    N = A.length();
	    isPalin = new int[N][N];
	    
	    for (int i = 0; i < N; i++)
	        Arrays.fill(isPalin[i], -1);
	    
	    this.A = A;
	    palindromeDP(0, N - 1);
        
        dp = new int[N];
        Arrays.fill(dp, -1);
        
	    return minCuts(N - 1) - 1;
	    
	}
	

	
	public int minCuts(int index) {
	    
	    if (index < 0)
	        return 0;
	        
	    if (dp[index] != -1)
	        return dp[index];
	    
	    int minSteps = 99999999;
	    
	    for (int i = index; i >= 0; i--) {
	        
	        if (isPalin[i][index] == 1) {
	            minSteps = Math.min(minSteps, minCuts(i - 1) + 1);
	        }
	        
	    }
	    
	    return dp[index] = minSteps;
	    
	}
	
	
	public void palindromeDP(int begin, int end) {
	    
	    for (int l = 0; l < N; l++) {
	        
	        for (int i = 0; i < N - l; i++) {
	            
	            int j = i + l;
	            
	            if (i == j) {
	                isPalin[i][j] = 1;
	                continue;
	            }
	            
	            if (A.charAt(i) == A.charAt(j)) {
	                if (i + 1 <= j - 1)
    	                isPalin[i][j] = isPalin[i + 1][j - 1];
    	            else
    	                isPalin[i][j] = 1;
	            } else {
	                isPalin[i][j] = 0;
	            }
	        }
	    }
	}
	
}

*/