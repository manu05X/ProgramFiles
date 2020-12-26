#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF    0x3f3f3f3f

int main()
{
    ll n,t, sum = 0;
    cin >> n;
    vector<ll> vec;
    for(ll i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
    }

    ll max = -INF;

    for (int i = 0; i < n; i++)
    {
        if(sum > 0)
        {
            sum = sum + vec[i];
        }
        else
        {
            sum = 0 + vec[i];
        }
        
        if (max < sum)
            max = sum;
    }
        
    cout << max << endl;

    return 0;
}