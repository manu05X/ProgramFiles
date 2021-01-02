#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n, t;
    cin >> n;

    vector<ll> vec;
    for(ll i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
    }

    ll cost = 0;
    sort(vec.begin(), vec.end());

    ll k = vec[n/2];

    for (ll i = 0; i < n; ++i) 
        cost += abs(vec[i] - k);

    if (n % 2 == 0) 
    { 
        ll tempCost = 0; 
  
        k = vec[(n / 2) - 1]; 
  
        // Find cost again 
        for (ll i = 0; i < n; ++i) 
            tempCost += abs(vec[i] - k); 
  
        // Take minimum of two cost 
        cost = min(cost, tempCost); 
    } 
    cout << cost<<endl;

    return 0;
}