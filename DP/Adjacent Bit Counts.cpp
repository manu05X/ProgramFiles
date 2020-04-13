/*
Adjacent Bit Counts
Send Feedback
For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0
Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2n) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011
Input
The first line of input contains a single integer P, (1 = P = 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100.
Output
For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of n-bit strings with adjacent bit count equal to k. As answer can be very large print your answer modulo 10^9+7.
Sample Input
10
1 5 2
2 20 8
3 30 17
4 40 24
5 50 37
6 60 52
7 70 59
8 80 73
9 90 84
10 100 90
Sample Output
1 6
2 63426
3 1861225
4 168212501
5 44874764
6 160916
7 22937308
8 99167
9 15476
10 23076518
*/

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;
 
ll dp[101][101][2];
int main()
{
	int t,n,k,i,j;
	dp[1][0][0]=1;
	dp[1][0][1]=1;
	
	for(i=2;i<=100;i++)
	{
		dp[i][i-1][0]=0;
		dp[i][i-1][1]=1;
		dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
		dp[i][0][1] = dp[i-1][0][0];
		if(dp[i][0][0] >= mod)
			dp[i][0][0]-=mod;
	}
	for(i=2;i<=100;i++)
	{
		for(j=1;j<i;j++)
		{
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
			
			if(dp[i][j][0] >= mod)
				dp[i][j][0]-=mod;
			
			if(dp[i][j][1] >= mod)
				dp[i][j][1]-=mod;
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>i>>n>>k;
		if(n==0 && k==0)
			cout<<i<<" 1"<<endl;
		else
		{
			ll ans = dp[n][k][0] + dp[n][k][1];
			if(ans >= mod)
				ans-=mod;
			cout<<i<<" "<<ans<<endl; 
		}
	}
}


/*#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int dp[101][100][2]; // initialized to 0
int main() {
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for (int n = 2; n <= 100; n++) {
        for (int k = 0; k < n; k++) {
            dp[n][k][0] = dp[n-1][k][0] + dp[n-1][k][1];
            dp[n][k][1] = dp[n-1][k][0];
            if (k > 0) dp[n][k][1] += dp[n-1][k-1][1];
        }
    }
    int P; cin >> P;
    while (P--) {
        int cs, n, k; scanf("%d %d %d", &cs, &n, &k);
        if (k < 0 || k >= n) {
            printf("%d 0\n", cs);
        } else {
            printf("%d %d\n", cs, dp[n][k][0] + dp[n][k][1]);
        }
    }
}*/




/*#define scl(t) scanf("%ld",&t)
#define sc(t) scanf("%d",&t)
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define lc printf("\n")


using namespace std;



ll dp[10001][10001][4];


int main()
{


    int t,ind,n,k,i,j,b;
    ll ans;
    sc(t);
    while(t--)
    {
        sc(ind);sc(n);sc(k); // taking input
        for(i=0;i<n;i++)
            for(j=0;j<=k;j++)
                for(b=0;b<2;b++)
                    dp[i][j][b]=0; //initialising the array with all 0
        
         /* no of ways of constructing a string of length 1 with adjbc()=0 is 1 
             for b=0 and b=1 */
        
   /*      dp[1][0][0]=dp[1][0][1]=1; //base case
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {

                    dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                    if(j>0)
                        dp[i][j][1]=dp[i-1][j-1][1];
                    dp[i][j][1]+=dp[i-1][j][0];

            }
        }
        ans=dp[n][k][0]+dp[n][k][1];
        cout<<ind<<" "<<ans<<endl;
    }

_______________________________________________________________________

#include <bits/stdc++.h>
 
using namespace std;
const int M = 1000000007;
 
long long go(long long n, long long k){
    //vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(2,0)));
 
    long long dp[n + 1][k + 1][2]; 
    memset(dp, 0, sizeof(dp)); 
    dp[1][0][0] = 1; 
    dp[1][0][1] = 1;
 
    for (int i = 2; i < n+1; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            // if(j==0)
            // {
            // dp[i][j][1]=dp[i-1][j][0]%(1000000007);
            // dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%(1000000007);
            // }
            // else
            // {
            // dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%(1000000007);
            // dp[i][j][1]=(dp[i-1][j-1][1]+dp[i-1][j][0])%(1000000007);
            // }
 
            dp[i][j][0] = (dp[i-1][j][0]%M + dp[i-1][j][1]%M )%M;
            if(j>0)
                dp[i][j][1] = dp[i-1][j-1][1]%M;
            dp[i][j][1] = (dp[i][j][1]%M + dp[i-1][j][0]%M )%M;
        }
    }
 
    return (dp[n][k][0]) + dp[n][k][1];
 
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	long long p;
	cin>>p;
	while(p--){
		long long s, n, k;
		cin>>s>>n>>k;

		cout << s << " " << go(n, k) << '\n';
	}


	return 0 ; 



}






}*/