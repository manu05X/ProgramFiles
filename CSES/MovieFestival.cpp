
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() 
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> vec;
    for(ll i=0;i<n;i++)
    {
        ll s,e;
        cin >> s >> e;
        vec.push_back({e,s});
    }
    
    sort(vec.begin(), vec.end());

    ll curr = vec[0].first;
    ll ans=1;
    for(ll i=1;i<n;i++)
    {
        if(vec[i].second >= curr)
        {
            // take this
            curr=vec[i].first;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
