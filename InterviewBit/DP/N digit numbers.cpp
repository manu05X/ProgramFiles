/*
N digit numbers
Problem Description

Find out the number of A digit positive numbers, whose digits on being added equals to a given number B.

Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007



Problem Constraints
1 <= A <= 1000

1 <= B <= 10000



Input Format
First argument is the integer A

Second argument is the integer B



Output Format
Return a single integer, the answer to the problem



Example Input
Input 1:

 A = 2
 B = 4
Input 2:

 A = 1
 B = 3


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 Valid numbers are {22, 31, 13, 40}
 Hence output 4.
Explanation 2:

 Only valid number is 3

*/


int Solution::solve(int n, int s) {
    long long int dp[n][s];
    if(s<1||s>9*n) return 0;
    
    for(int i=0;i<s;i++){
        if(i+1<=9) dp[0][i]=1;
        else dp[0][i]=0;
    }
    for(int j=0;j<n;j++){
        dp[j][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<s;j++){
            dp[i][j]=0;
            int k=0;
            if(j>=9) k=j-9;
            for(;k<=j;k++)
             dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
             
        }
    }
    return dp[n-1][s-1];

}
