/*
				PROBLEM STATEMENT
Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 109+7
She finds this task really easy, and thinks that you can do it too. Can you?
Input Format:
The first line contains a single integer N denoting size of array A. The next line contains N space separated integers denoting the elements of array A
Output Format:
Print the required answer Modulo 10^9+7 on a single line.
Constraints:
1≤N≤500

1≤A[i]≤100
Sample Input
3
1 2 3
Sample Output
5
*/

#include <bits/stdc++.h>

using namespace std;
int go(vector<int> v){
	int n = v.size();
	vector<vector<int>> dp(101, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		{
			dp[v[i]][i] = 1;
		}	

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (v[i]>v[j])
			{
				for (int k = 1; k < 101; ++k)
				{
					int gcn = __gcd(k, v[i]);
					dp[gcn][i] = (dp[gcn][i]+dp[k][j])%1000000007;
				}
			}
		}
	}

	int ans = 0;

	// for (int i = 1; i < 101; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout <<'\n';
	// }

	for (int i = 0; i < n; ++i)
	{
		ans=(ans+ dp[1][i])%1000000007;
	}

	return ans%1000000007;




}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	

	int n;
	cin>>n;
	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];	
	}

	cout << go(v) << '\n';



	return 0 ; 



}


/*
#include<bits/stdc++.h>
#define ll long long
#define lld long double
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main(){
boost;
ll N;
cin>>N;
ll arr[N],dp[N][101]={0};
for(ll i=0;i<N;i++){
cin>>arr[i];
dp[i][arr[i]]++;
}
for(ll i=0;i<N;i++){
for(ll j=i+1;j<N;j++){
if(arr[i]<arr[j]){
for(ll k=1;k<=100;k++){
if(dp[i][k])
dp[j][__gcd(k,arr[j])]=(dp[i][k]+dp[j][__gcd(k,arr[j])])%MOD;
}
}
}
}
ll ans=0;
for(ll i=0;i<N;i++)
ans=(ans+dp[i][1])%MOD;
cout<<ans<<endl;
}
*/
