#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n,m,k , t;
    cin>>n>>m>>k;

    vector<ll> appDim;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        appDim.push_back(t);
    }

    vector<ll> appAvil;
    for(int i = 0; i < m; i++)
    {
        cin >> t;
        appAvil.push_back(t);
    }

    sort(appDim.begin(), appDim.end());
    sort(appAvil.begin(), appAvil.end());

    ll i = 0, j = 0, count = 0;
    while(i < n && j < m)
    {
        if(appDim[i] <= appAvil[j]+k && appDim[i] >= appAvil[j]-k)
        {
            count++;
            i++;
            j++;
        }
        else
            if(appDim[i] < appAvil[j]-k)
            {
                i++;
            }
            else
            {
                j++;
            }    
    }
    
    cout << count;

    return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    ll n,m,k , t;
    cin>>n>>m>>k;
 
    vector<ll> appDim;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        appDim.push_back(t);
    }
 
    vector<ll> appAvil;
    for(int i = 0; i < m; i++)
    {
        cin >> t;
        appAvil.push_back(t);
    }
 
    sort(appDim.begin(), appDim.end());
    sort(appAvil.begin(), appAvil.end());
 
    ll i = 0, j = 0, count = 0;
    while(i < n && j < m)
    {
        if(abs(appDim[i] - appAvil[j]) <= k)
        {
            count++;
            i++;
            j++;
        }
        else
            if(appDim[i] < appAvil[j])
            {
                i++;
            }
            else
            {
                j++;
            }    
    }
    
    cout << count;
 
    return 0;
}
*/