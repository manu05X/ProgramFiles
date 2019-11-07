/*
Income On Nth Day
Send Feedback
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:
The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.
Output:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
CONSTRAINTS:
1 = T = 10^5

0 = F0, F1, N = 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107
*/
//sol->
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
#define br cout<<"\n"
#define max_val 1000000
#define mod 1000000007
#define mod1 1000000006
 
void multiply(ll a[2][2],ll m[2][2]){
    a[0][0]=a[0][0]%mod1;
    a[0][1]=a[0][1]%mod1;
    a[1][0]=a[1][0]%mod1;
    a[1][1]=a[1][1]%mod1;
 
 
    ll p1=((a[0][0]*m[0][0])%mod1+(a[0][1]*m[1][0])%mod1)%mod1;
    ll p2=((a[0][0]*m[0][1])%mod1+(a[0][1]*m[1][1])%mod1)%mod1;
    ll p3=((a[1][0]*m[0][0])%mod1+(a[1][1]*m[1][0])%mod1)%mod1;
    ll p4=((a[1][0]*m[0][1])%mod1+(a[1][1]*m[1][1])%mod1)%mod1;
 
    a[0][0]=p1;
    a[0][1]=p2;
    a[1][0]=p3;
    a[1][1]=p4;
 
}
 
 
void fib_power(ll a[2][2],ll n){
    if (n==0 or n==1)
        return;
    fib_power(a,n/2);
    multiply(a,a);
    if(n%2!=0)
    {
        ll m[2][2]={{1,1},{1,0}};
        multiply(a,m);
    }
}
 
 
ll get_nth_fib(ll n){
    if (n==0 ) return 0;
    ll a[2][2]={{1,1},{1,0}};
    fib_power(a,n-1);
    return a[0][0]%mod1;
}
 
ll modular_power(ll a,ll b){
    if(a==0) return 0;
    if(b==0) return 1;
    if(b%2==0){
        ll smallans=modular_power(a,b/2);
        return (smallans*smallans)%mod;
    }
 
        ll smallans=modular_power(a,b-1);
        return (a*smallans)%mod;
    
}
 
 
 
ll solve(ll a,ll b,ll n){
    ll pow1=get_nth_fib(n-1)%(mod1);                     //in log(n)
    ll pow2=get_nth_fib(n)%(mod1);
    ll part1=modular_power(a+1,pow1)%mod;                // in log(n)
    ll part2=modular_power(b+1,pow2)%mod;
    return (part1*part2)%mod;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    
    ll a,b,c;
    while(t--){
        cin>>a>>b>>c;
        if(c==0){
                   cout<<a;br;
                   continue;
               }
               if(c==1){
                    cout<<b;br;
                   continue;
               }
        cout<<(solve(a,b,c)-1);
        br;
    }
}
