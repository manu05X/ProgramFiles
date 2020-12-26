#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

	ll n,x,count,temp;
	cin >> n >> x; 

	ll wtchild[n];

	for(ll i=0;i<n;i++)
    {
        cin>>wtchild[i];
    }

	sort(wtchild, wtchild + n);

	ll i = count = 0;	//i to smallest
	ll j = n-1;		//j to largest
    
    //keep doing until i==j
	while(i <= j)
    {	//1 gondola per 2 child
		if(wtchild[i] + wtchild[j] <= x)
        {
            count++; 
            i++; 
            j--;
        }
		else
        { //1 gondola for 1 unpaired large child
            j--;
            count++;
        }
	}
	cout << count << endl;

    return 0;
}