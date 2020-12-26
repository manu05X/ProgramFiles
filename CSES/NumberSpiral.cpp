//https://cses.fi/problemset/task/1071/

//using formula f = m(m-1) + 1 +(-1)^m * (x - y) where m = max(x,y)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll n,m;
        cin >>n >> m;
        ll p = max(n,m);
        
        ll s = 0;
        if(p % 2 == 0)
        {
            s = 1 * (n - m) ;
        }
        else
        {
            s = -1 * (n - m);
        }
        ll r = p * (p-1);

        ll res = r + 1 + s;

        cout << res << endl;
    }
}