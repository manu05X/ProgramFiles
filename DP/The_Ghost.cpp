#include<bits/stdc++.h>
using namespace std;
long long int dp[21][1<<20];
 
long long int solve(int u,int mask,int n)
{
    if(u==0&&(mask==((1<<n)-1))) return 1;
    if(u==0) return 0;
    if(dp[u][mask]!=-1) return dp[u][mask];
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;
        int flag=0;
        for(int j=0;j<n;j++)
            if(mask&(1<<j))
                if((i+1&j+1)==(i+1))
                {
                    flag=1; break;
                }
        if(!flag)
            ans+=solve(u-1,mask|(1<<i),n);
            
    }
    
    return dp[u][mask]=ans;
}
 
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,0,n);
    return 0;
}
