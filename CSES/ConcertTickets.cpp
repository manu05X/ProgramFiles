#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll numTikts, numCustmr;
    cin >> numTikts >> numCustmr;

    ll x;
    multiset<ll,greater<ll>> tiktCost;
    for(int i = 0; i < numTikts; i++)
    {
        cin >> x;
        tiktCost.insert(x);
    }
    //  for(auto i = tiktCost.begin(); i != tiktCost.end(); i++)
    //  {
    //      cout << *i << endl;
    //  }


    ll custCost;
    while(numCustmr--)
    {
        cin >> custCost;
        auto it = tiktCost.lower_bound(custCost);
        //cout << *it;
        if( it != tiktCost.end() && *it <= custCost)
        {
             cout << *it << endl;
             tiktCost.erase(it);
        }
        else
        {
             cout << "-1" <<"\n";
        }
    }
    return 0;
}


/*
#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, m, curr, ticket;
    cin >> n >> m;
    multiset<lli, greater<int>> tickets;

    while (n--)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }

    while (m--)
    {
        cin >> curr;
        auto it = tickets.lower_bound(curr);
        if (it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return 0;
}
*/