#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    vector<int> vec;
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        int t; 
        cin >> t;
        int lo = 0, hi = vec.size();
        while (lo < hi) 
        {
            int mid = lo + (hi - lo)/2;

            if (vec[mid] > t) 
                hi = mid;
            else 
                lo = mid+1;
        }
        if (lo == vec.size()) 
            vec.push_back(t);
        else 
            vec[lo] = t;
    }
    cout << vec.size();

    return 0;
}