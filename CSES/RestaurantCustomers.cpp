#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> vec;
    for(int i = 0; i < n; i++)
    {
        int s,e;
        cin >> s >> e;
        vec.push_back(make_pair(s,1));
        vec.push_back(make_pair(e,-1));
    }

    sort(vec.begin(), vec.end());

    int sum = 0;
    int ans = 0;
    for (auto x : vec) 
    {
        sum += x.second;
        ans = max(ans, sum);
    }
    cout << ans << '\n';


    return 0;
}