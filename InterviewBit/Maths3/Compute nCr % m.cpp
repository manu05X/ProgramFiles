/*
Compute nCr % m
Problem Description
Given three integers A, B and C, where A represents n, B represents r and C represents m, find and return the value of nCr % m where nCr % m = (n!/((n-r)!*r!))% m. x! means factorial of x i.e. x! = 1 * 2 * 3... * x.   


Problem Constraints
1 <= A * B <= 106 1 <= B <= A 1 <= C <= 106   


Input Format
The first argument given is integer A ( = n).
The second argument given is integer B ( = r).
The third argument given is integer C ( = m).


Output Format
Return the value of nCr % m.


Example Input
Input 1:
 A = 5
 B = 2
 C = 13
Input 2:
 A = 6
 B = 2
 C = 13
  


Example Output
Output 1:
 10
Output 2:
 2
  


Example Explanation
Explanation 1:
 The value of 5C2 % 11 is 10.
Explanation 2:
 The value of 6C2 % 13 is 2.
 
*/

//sol->

int Solution::solve(int n, int r, int p) {
    
    int C[r+1];
    memset(C,0,sizeof(C));
    C[0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
            C[j]=(C[j]+C[j-1])%p;
    }
    return C[r];
}





/*
int Solution::solve(int A, int B, int C) {
    int dp[A+1][B+1];
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= min(i,B); j++){
            if(j == i || j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] % C + dp[i-1][j] % C) % C;
            }
        }
    }
    return dp[A][B] % C;
}

------------------------

class Solution:
    # @param A : integer
    # @param B : integer
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C):
        dp = [[0 for i in range(B+1)] for j in range(A+1)]
        for i in range(A+1):
            for j in range(min(i,B) + 1):
                if(j == i or j == 0):
                    dp[i][j] = 1
                else:
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % C
        return (dp[A][B] % C)

*/
