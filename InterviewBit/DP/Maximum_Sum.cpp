/*
Maximum Sum
Problem Description

You are given an array A of N integers and three integers B, C, and D.

You have to find the maximum value of A[i]*B + A[j]*C + A[k]*D, where 1 <= i <= j <= k <= N.



Problem Constraints
1 <= N <= 105

-10000 <= A[i], B, C, D <= 10000



Input Format
First argument is an array A
Second argument is an integer B
Third argument is an integer C
Fourth argument is an integer D



Output Format
Return an Integer S, i.e maximum value of (A[i] * B + A[j] * C + A[k] * D), where 1 <= i <= j <= k <= N.



Example Input
Input 1:

 A = [1, 5, -3, 4, -2]
 B = 2
 C = 1
 D = -1
Input 2:

 A = [3, 2, 1]
 B = 1
 C = -10
 D = 3


Example Output
Output 1:

 18
Output 2:

 -4


Example Explanation
Explanation 1:

 If you choose i = 2, j = 2, and k = 3 then we will get
 A[2]*B + A[2]*C + A[3]*D = 5*2 + 5*1 + (-3)*(-1) = 10 + 5 + 3 = 18
Explanation 2:

 If you choose i = 1, j = 3, and k = 3 then we will get
 A[1]*B + A[3]*C + A[3]*D = (3*1) + (-10*1) + (3*1) = 3 - 10 + 3 = -4

*/


int Solution::solve(vector<int> &A, int B, int C, int D) {
    
   int n=A.size();
    int L[n];
    L[0]=B*A[0];
    for(int i=1;i<n;i++)
        L[i]=max(L[i-1],B*A[i]);
        
    int R[n];
    R[n-1]=D*A[n-1];
    for(int i=n-2;i>=0;i--)
        R[i]=max(R[i+1],D*A[i]);
        
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
        ans=max(ans,L[i]+C*A[i]+R[i]);
        
    return ans;
}



/*
int Solution::solve(vector<int> &A, int B, int C, int D) {
    
    int n = (int)A.size();
    int dp[n+1][3];     // dp array to store answer of previous states
    
    for(int i = 0; i <= n; i += 1) {
        dp[i][0] = dp[i][1] = dp[i][2] = -1e9;          // Initialize the dp array with minus infinity
    }
    
    for(int i = 1; i <= n; i += 1) {
        dp[i][0] = max(dp[i-1][0], A[i-1] * B);             // Maximum value of A[i]*B
        dp[i][1] = max(dp[i-1][1], dp[i][0] + A[i-1] * C);  // Maximum value of A[i]*B + A[j]*C
        dp[i][2] = max(dp[i-1][2], dp[i][1] + A[i-1] * D);  // Maximum value of A[i]*B + A[j]*C + A[k]*D
    }
    
    return dp[n][2];        // return the answer.
}

*/