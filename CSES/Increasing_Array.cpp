// https://cses.fi/problemset/task/1094
#include <iostream>

using namespace std;

typedef unsigned long long ll;

int main() 
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, pre, count = 0, in;
    cin >> n >>pre;
    while(--n > 0)
    {
        cin >> in;
        if(pre > in)
        {
            count += pre - in;
        }
        else
        {
            pre = in;
        }
    }  
    cout << count << endl;
}