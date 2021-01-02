// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main()
// {
// 	cin.tie(NULL);
// 	cout.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     ll n, t;
//     cin >> n;

//     // vector<ll> vec;
//     // for(ll i = 0; i < n; i++)
//     // {
//     //     cin >> t;
//     //     vec.push_back(t);
//     // }

//     map<ll, ll> mp;
//     ll max_length = 0, j = 0;

//     for(ll i = 1; i < n+1; i++)
//     {
//         cin >> t;
//         // Update j based on previous occurrence of vec[i] 
//         j = max(mp[t], j);
//         // Update max_length to store maximum length of subarray
//         max_length = max(max_length, i - j);
//         // Store the index of current occurrence of vec[i]
//         mp[t] = i;
//     }

//     cout << max_length <<endl;

//     return 0;
// }




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
    // unordered_map was giving TLE
    map<ll, ll> mp;
    ll max_length = 0;
 
    for(ll i = 0, j = 0; i < n; i++)
    {   
        // Update j based on previous occurrence of vec[i] 
        j = max(mp[vec[i]], j);
        // Update max_length to store maximum length of subarray
        max_length = max(max_length, i - j + 1);
        // Store the index of current occurrence of vec[i]
        mp[vec[i]] = i + 1;
    }
 
    cout << max_length <<endl;
 
    return 0;
}
