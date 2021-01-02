#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, m,max_pass = 0;
    vector<int> vec;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;

        int curr_pass = n - t;

        max_pass = max(max_pass, curr_pass);
    }

    return 0;
}