//  https://cses.fi/problemset/task/1095/


#include <iostream>

using namespace std;

typedef long long ll;

const int M = 1000000007;

int pow(ll a, ll b, int m) 
{
  ll res = 1, e = a; // Initialize res
  while (b>0) 
  {
	  // If b is odd, multiply e with result 
    if (b & 1) 
		res = (res * e) % m;
    // n must be even now
	b >>= 1;// b = b/2 
	e = (e * e) % m; // Change e to e^2 
    
  }
  return res;
}

int main() {
  int n;
  cout << "Enter testcases:";
  cin >> n;
  while (n--) {
    int a, b;
    cout << "Enter both number:";
    cin >> a >> b;
    cout << pow(a, b, M) << endl;
  }
}

/*

TLE
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 1000000007;

int main() {
  int T;
  cin>>T;
  while(T--)
  {
      ll n,m;
      cin>>n>>m;
      
      ll result = 1;
      for(int i = 0; i < m; ++i)
      {
        result = (result * n) % M;
      }
      
      cout << result << endl;
  }
  
}

*/