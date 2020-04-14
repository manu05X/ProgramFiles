/*
Fibonacci Sum
Send Feedback
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
Output Format :
A single line containing the answer for the task.
Sample Input :
10 19
Sample Output :
10857
*/

#include<cstring>
using namespace std;


void mul(unsigned long long a[][2],unsigned long long b[][2])
{
    unsigned long long res[2][2];
    memset(res,0,sizeof res);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				res[i][j]=(res[i][j] + a[i][k]*b[k][j])%1000000007;
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=res[i][j];
		}
	}
}

unsigned long long helper(unsigned long long n)
{
	unsigned long long q[2][2]={{1,1},{1,0}};
    unsigned long long w[2][2]={{1,0},{0,1}};
    while(n)
    {
        if(n&1)
           mul(w,q);
        mul(q,q);
        n>>=1;
    }
    return w[0][1];
	
}
unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
    return (helper(n+2)-helper(m+1)+1000000007)%1000000007;
}


int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}


/*
//sol->
#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const long long int mod=1000000007;
LL A[2][2]={{1,1},{1,0}};
void matrix_multiply(LL T[2][2],LL A[2][2])
{
	LL result[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			result[i][j]=0;
			for(int k=0;k<2;k++)
			{
				result[i][j]=(result[i][j]+(T[i][k]*A[k][j])%mod)%mod;
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			T[i][j]=result[i][j];
		}
	}
}
void matrix_power(LL T[2][2],LL exponent)
{
	if(exponent==0||exponent==1)
	return;
	matrix_power(T,exponent>>1);
	matrix_multiply(T,T);
	if(exponent&1)
	matrix_multiply(T,A);
}
LL result(LL n)
{
	LL T[2][2]={{1,1},{1,0}};
	matrix_power(T,n);
	LL ans=(T[0][1]);
	ans=(ans-1+mod)%mod;
	return ans;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL n,m,ans;
		scanf("%lld%lld",&n,&m);
		ans=(result(m+2)-result(n+1)+mod)%mod;
		printf("%lld\n",ans);
		
	}
	return 0;
}
________________________________________________________
// #include <bits/stdc++.h>
// using namespace std;

// #define mod 1000000007

// long long result[2][2]={{1,1},{1,0}};
// long long transformation[2][2]={{1,1},{1,0}};
// void matrixMul(long long a[2][2],long long b[2][2])
// {
//  int i,j,k;
//  long long re[2][2] ={0};
//  for(i=0;i<2;i++) {
//  	for(j=0;j<2;j++) {
//  		for(k=0;k<2;k++) {
//  			re*[j] = (re*[j] + (a*[k]*b[k][j])%mod ) % mod;
//  		}
//  	}
//  }
//  for(i=0;i<2;i++)
//  {
//  	for(j=0;j<2;j++)
//  		result*[j]=re*[j];
//  }
// }

// void initialize() {
// result[0][0]=result[0][1]=result[1][0]=1;
// result[1][1]=0;
// }
// void power(int n)
// {
// if(n==1)
// return ;
// power(n/2);
// matrixMul(result,result);
// if(n&1)
// {
// 	matrixMul(result,transformation);
// }
// }

// int main()
// { 	
// int t;
// cin>>t;
// while(t--){
// initialize();
// long long n,m;
// cin>>n>>m;
// long long x,y;
// if(n == 0 || n == 1) {
// 		x=n;
// }
// else {
// 	power(n);
// 	x=result[0][0]-1;
// }
// initialize();
// if(m == 0 || m == 1) {
// 		x=m;
// }
// else {
// 	power(m+1);
// 	y=result[0][0]-1;
// }
// if(x>y){
// 	x=x-y;
// }
// else
// 	x=y-x;

// cout<<((x+mod)%mod)<<endl;
// }
// return 0;
// }
*/