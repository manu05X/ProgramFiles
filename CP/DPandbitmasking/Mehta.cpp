/*
Mehta And Bank Robbery
Send Feedback
One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular weight and particular profit associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his profit[x] with any of the first 10 primes and then put that item into his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its profit. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the profit as it is, more specifically, 1*profit[x] for xth item will get added to its total profit, and that he can do with as many items as he wants. He cannot fill his bag more than weight W units. Each item should be picked with its whole weight, i.e it cannot be broken into several other items of lesser weight. So, now to impress his squad, he wishes to maximize the total profit he can achieve by robbing this wealthy house.
Input:
First Line of input containts two integers N and W. Next N lines contain information of ith item, describing profit and weight of the ith item, profit and weight are separated by single space.
Output:
In a single line, output the maximum profit obtainable.
Constraints:
1 <= N <= 2000, 1 <= W <= 2000

1 <= Profit[i] <= 10^9, 1 <= Weight[i] <= 2000

SAMPLE INPUT
3 4

1 1

2 1

3 1

SAMPLE OUTPUT
152

Explanation:
As all, the items can be picked, so maximum profit is equal to = 1 X 19 + 2 X 23 + 3 X 29 = 152
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
typedef long long int LL;
typedef pair<int, int > pii;
const int MAXN = 2001;
LL P[11] = {1,2,3,5,7,11,13,17,19,23,29};
LL dp[2][MAXN][MAXN];
int profit[MAXN];
int weight[MAXN];
vector<pii > v;
int main() {
	int N,W;
	scanf("%d%d",&N,&W);
	assert(N >= 1 && N <= 2000);
	assert(W >= 1 && W <= 2000);
	rep(i,1,N+1) {
		scanf("%d%d",&profit[i], &weight[i]);
		assert(profit[i] >= 1 && profit[i] <= 1000000000);
		assert(weight[i] >= 1 && weight[i] <= 2000);
		v.push_back(make_pair(profit[i], weight[i]));
	}
	sort(v.begin(), v.end());
	rep(i,1,N+1) {
		profit[i] = v[i-1].first;
		weight[i] = v[i-1].second;
	}
	rep(p,0,11) rep(i,1,N+1) rep(j,1,W+1) {
		if(!p) {
			dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]);
			if(j >= weight[i])
				dp[0][i][j] = max(dp[0][i][j], dp[0][i-1][j-weight[i]]+profit[i]);
		} else {
			int cur = p&1;
			int prev = 1-cur;
			dp[cur][i][j] = dp[prev][i][j];
			dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i-1][j]);
			dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i][j-1]);
			if(j >= weight[i]) {
				dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i-1][j-weight[i]]+profit[i]);
				dp[cur][i][j] = max(dp[cur][i][j], dp[prev][i-1][j-weight[i]]+P[p]*profit[i]);
			}
		}
	}
	cout << dp[0][N][W] << endl;
	return 0;
}

/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int prime[]={1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
 
int main(){
    int n, w;
    cin>>n>>w;
    pair<ll, ll> *arr=new pair<ll, ll>[n];
    for (int i=0 ; i<n ; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n);
    ll ***dp=new ll**[2];
    for (int i=0 ; i<2 ; i++){
        dp[i]=new ll*[n+1];
        for (int j=0 ; j<=n ; j++){
            dp[i][j]=new ll[w+1];
            for (int k=0 ; k<=w ; k++){
                dp[i][j][k]=0;
            }
        }
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=w ; j++){
            dp[0][i][j]=dp[0][i-1][j];
            if (j>=arr[i-1].second){
                dp[0][i][j]=max(dp[0][i][j], dp[0][i-1][j-arr[i-1].second]+arr[i-1].first);
            }
        }
    }
    for (int p=1 ; p<=10 ; p++){
        int x=p%2;
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=w ; j++){
                dp[x][i][j]=dp[x][i-1][j];
                if (j>=arr[i-1].second){
                    dp[x][i][j]=max(dp[x][i][j], max(dp[x][i-1][j-arr[i-1].second]+arr[i-1].first, dp[x^1][i-1][j-arr[i-1].second]+arr[i-1].first*prime[p]));
                }
            }
        }
    }
    cout<<dp[0][n][w]<<endl;
    return 0;
}
*/