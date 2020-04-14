
/*
	Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/

#include<iostream>
using namespace std;

int makeSeave(int n){
    int i, count = 0,j;
    bool isPrime[n+1];
    
    for(i= 0;i < n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(i = 2; i*i<=n; i++)
    {
        if(isPrime[i] == true)
        {
            for(j = i*i;j<=n;j+=i)
            {
                isPrime[j]= false;
            }
        }
    }
    for(i= 0;i<= n; i++)
    {
        if(isPrime[i] == true)
        {
            count++;
        }
    }
    return count;
    
    
}


int main(){
	int n ;
    cin >> n ;
    cout << makeSeave(n)<<endl;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	int count = 0;

	if (n>=2)
	{
		count++;
	}
	if (n>=3)
	{
		count++;
	}

	//cout << n << '\n';
	for (int i = 2; i <= n; ++i)
	{
		int flag = 0;
		for (int j = 2; j*j <= i; ++j)
		{
			if (i%j==0)
			{
				flag = 0;
				break;
			}else{
				flag = 1;
			}

		}
		if (flag == 1)
		{
			count++;
		}
	}

	cout <<count<<endl;	



	return 0 ; 



}


*/