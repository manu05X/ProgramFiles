/*
DISTINCT SUBSEQUENCES
Given a stringof lower case alphabets A of size N

Return the count of all distinct subsequences of A%10^9+7.


Input Format

The first argument given is the string A.
Output Format

Return the count of all distinct subsequences of A % 10^9 + 7.
Constraints

1 <= N, M <= 100000
For Example

Input 1:
    A = "aba"
Output 1:
    6
Explanation 1:
    "a", "b", "ab", "ba", "aa", "aba"

Input 2:
    A = "abc"
Output 2:
    7
	
		
*/


#define mod 1000000007
int Solution::solve(string A) {
    int n=A.length();
    int dp[n+1];
    dp[0]=1;

    int last[26];
    memset(last,-1,sizeof(last));
    
    for(int i=0;i<n;i++)
    {
        int x=(int)(A[i]-'a');
        dp[i+1]=dp[i]*2%mod;
        
        if(last[x]>=0)
            dp[i+1]-=dp[last[x]];
        dp[i+1]%=mod;
        last[x]=i;
    }
    dp[n]--;
    if(dp[n]<0)
        dp[n]+=mod;
        
    return dp[n];
}


/*
int solve(string A)
{
    int MOD = 1000000007;
    int N = A.length();
    int dp[N+1] = {0};
    dp[0] = 1;

    int last[26];
    memset(last, -1, sizeof(last));

    for (int i = 0; i < N; ++i) {
        int x = (int)(A[i] - 'a');
        dp[i+1] = dp[i] * 2 % MOD;
        if (last[x] >= 0)
            dp[i+1] -= dp[last[x]];
        dp[i+1] %= MOD;
        last[x] = i;
    }

        dp[N]--;
        if (dp[N] < 0) dp[N] += MOD;
        return dp[N];
}


*/