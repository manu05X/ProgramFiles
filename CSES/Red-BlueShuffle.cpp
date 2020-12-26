#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        int R[n], B[n];

        for(int i =0; i < n; i++)
        {
            cin>>R[i];
        }
        for(int i =0; i < n; i++)
        {
            cin>>B[i];
        }

        string r = "",b = "";

        for(int i =0; i < n; i++)
        {
            r += char(R[i]) - 48;
            b += char(B[i]) - 48;
        }

        cout << r << b;
        int rCount = 0, bCount = 0, eCount = 0;
        if(r >= b)
        {
            rCount++;
        }
        if(r <= b)
        {
            bCount++;
        }
        while(next_permutation(b.begin(), b.end()) && next_permutation(r.begin(), r.end()))
        {
            if(r >= b)
            {
                rCount++;
            }
            if(r <= b)
            {
                bCount++;
            }
        }

        if(rCount > bCount)
        {
            cout << "RED"<<endl;
        }
        else if(rCount < bCount)
        {
            cout << "BLUE" <<endl;
        }
        else
        {
           cout << "EQUAL"<<endl;
        }
    }
    return 0;
}