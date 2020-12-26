#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin>>n;
    ll arr[n];

    ll count = 1;

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            count++;
        }
    }
   
    cout << count;

    return 0;
}