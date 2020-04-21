/*
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
YES
*/

#include <bits/stdc++.h>

using namespace std;

void go(vector<int> arr, int n, int i , int sum){
	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i < sum+1; ++i)
	{
		dp[n][i] = 0;
	}

	for (int j = 1; j < sum+1; ++j)
	{
		for (int i = n-1; i >= 0; --i)
		{
			bool c1 = 0;
			if (j-arr[i]>=0)
			{
				c1 = dp[i+1][j-arr[i]];	
			}

			if (c1 == 1)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i+1][j];

			}
		}
	}

	// for (int i = 0; i < n+1; ++i)
	// {
	// 	for (int j = 0; j < sum+1; ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout <<'\n';
	// }

	if (dp[0][sum] == 1)
	{
		cout << "Yes" << '\n';
	}else
		cout << "No" << '\n';

	return;



}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL); 
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int sum;
	cin>>sum;

	go(arr, n, 0, sum);



	return 0 ; 

}

/*
//using only two row 
#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* val,int n,int sum){

	bool** dp = new bool*[2];
	for(int i=0;i<=1;i++){
		dp[i] = new bool[sum+1];
	}

	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){

			dp[flag][j] = dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-val[i-1]];
			}
		}
		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][sum];
	// delete dp array
	return ans;


}
int main(){


	int val[] = {1,3,5,7,9};
	int sum = 12;

	cout<<subsetSum(val,5,sum)<<endl;
	
	return 0;


*/